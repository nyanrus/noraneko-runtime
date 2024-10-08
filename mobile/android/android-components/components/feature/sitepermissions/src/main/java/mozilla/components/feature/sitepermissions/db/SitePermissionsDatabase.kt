/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package mozilla.components.feature.sitepermissions.db

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import androidx.room.TypeConverter
import androidx.room.TypeConverters
import androidx.room.migration.Migration
import androidx.sqlite.db.SupportSQLiteDatabase
import mozilla.components.concept.engine.permission.SitePermissions

/**
 * Internal database for saving site permissions.
 */
@Database(entities = [SitePermissionsEntity::class], version = 8)
@TypeConverters(StatusConverter::class)
internal abstract class SitePermissionsDatabase : RoomDatabase() {
    abstract fun sitePermissionsDao(): SitePermissionsDao

    companion object {
        @Volatile
        private var instance: SitePermissionsDatabase? = null

        @Synchronized
        fun get(context: Context): SitePermissionsDatabase {
            instance?.let { return it }

            return Room.databaseBuilder(
                context,
                SitePermissionsDatabase::class.java,
                "site_permissions_database",
            ).addMigrations(
                Migrations.migration_1_2,
            ).addMigrations(
                Migrations.migration_2_3,
            ).addMigrations(
                Migrations.migration_3_4,
            ).addMigrations(
                Migrations.migration_4_5,
            ).addMigrations(
                Migrations.migration_5_6,
            ).addMigrations(
                Migrations.migration_6_7,
            ).addMigrations(
                Migrations.migration_7_8,
            ).build().also { instance = it }
        }
    }
}

@Suppress("unused")
internal class StatusConverter {
    private val autoplayStatusArray =
        SitePermissions.AutoplayStatus.entries.toTypedArray()

    private val statusArray = SitePermissions.Status.entries.toTypedArray()

    @TypeConverter
    fun toInt(status: SitePermissions.Status): Int {
        return status.id
    }

    @TypeConverter
    fun toStatus(index: Int): SitePermissions.Status? {
        return statusArray.find { it.id == index }
    }

    @TypeConverter
    fun toInt(status: SitePermissions.AutoplayStatus): Int {
        return status.id
    }

    @TypeConverter
    fun toAutoplayStatus(index: Int): SitePermissions.AutoplayStatus {
        return autoplayStatusArray.find { it.id == index } ?: SitePermissions.AutoplayStatus.BLOCKED
    }
}

internal object Migrations {
    val migration_1_2 = object : Migration(1, 2) {
        override fun migrate(db: SupportSQLiteDatabase) {
            // Version 1 is used in Nightly builds of Fenix, but not in production. Let's just skip actually migrating
            // anything and let's re-create the "site_permissions" table.

            db.execSQL("DROP TABLE site_permissions")
            db.execSQL(
                "CREATE TABLE IF NOT EXISTS `site_permissions` (" +
                    "`origin` TEXT NOT NULL, " +
                    "`location` INTEGER NOT NULL, " +
                    "`notification` INTEGER NOT NULL, " +
                    "`microphone` INTEGER NOT NULL, " +
                    "`camera` INTEGER NOT NULL, " +
                    "`bluetooth` INTEGER NOT NULL, " +
                    "`local_storage` INTEGER NOT NULL, " +
                    "`saved_at` INTEGER NOT NULL," +
                    " PRIMARY KEY(`origin`))",
            )
        }
    }

    @Suppress("MagicNumber")
    val migration_2_3 = object : Migration(2, 3) {
        override fun migrate(db: SupportSQLiteDatabase) {
            val haveAutoPlayColumns = db.query("SELECT * FROM site_permissions").columnCount == 10
            // We just want to apply this migration for user that do not have
            // the new autoplay fields autoplay_audible and autoplay_inaudible
            if (!haveAutoPlayColumns) {
                db.execSQL(
                    "ALTER TABLE site_permissions ADD COLUMN autoplay_audible INTEGER NOT NULL DEFAULT ''",
                )
                db.execSQL(
                    "ALTER TABLE site_permissions ADD COLUMN autoplay_inaudible INTEGER NOT NULL DEFAULT ''",
                )

                db.execSQL(
                    " UPDATE site_permissions" +
                        " SET autoplay_audible = -1, " + // BLOCKED by default
                        " `autoplay_inaudible` = 1", // ALLOWED by default
                )
            }
        }
    }

    @Suppress("MagicNumber")
    val migration_3_4 = object : Migration(3, 4) {
        override fun migrate(db: SupportSQLiteDatabase) {
            val hasEmeColumn = db.query("SELECT * FROM site_permissions").columnCount == 11
            if (!hasEmeColumn) {
                db.execSQL(
                    "ALTER TABLE site_permissions ADD COLUMN media_key_system_access INTEGER NOT NULL DEFAULT 0",
                )
                // default is NO_DECISION
                db.execSQL("UPDATE site_permissions SET media_key_system_access = 0")
            }
        }
    }

    @Suppress("MagicNumber")
    val migration_4_5 = object : Migration(4, 5) {
        override fun migrate(db: SupportSQLiteDatabase) {
            // Updating any previous autoplay sites with 0 (NO_DECISION) with the supported values
            // Autoplay permission doesn't support 0 (NO_DECISION),
            // it only supports 1 (ALLOWED) or -1 (BLOCKED)
            db.execSQL("UPDATE site_permissions SET autoplay_audible = -1 WHERE autoplay_audible = 0 ")
            db.execSQL("UPDATE site_permissions SET autoplay_inaudible = 1 WHERE autoplay_inaudible = 0 ")
        }
    }

    @Suppress("MagicNumber")
    val migration_5_6 = object : Migration(5, 6) {
        override fun migrate(db: SupportSQLiteDatabase) {
            db.execSQL(
                "UPDATE site_permissions SET origin = 'https://'||origin||':443'",
            )
        }
    }

    @Suppress("MagicNumber")
    val migration_6_7 = object : Migration(6, 7) {
        override fun migrate(db: SupportSQLiteDatabase) {
            // Update any site with our previous default value (block audio and video)  to block audio only.
            // autoplay_audible BLOCKED (-1) and autoplay_inaudible BLOCKED (-1) to
            // autoplay_audible BLOCKED (-1) and autoplay_inaudible ALLOWED (1)
            // This match the default value of desktop block audio only.
            db.execSQL(
                "UPDATE site_permissions SET autoplay_audible = -1, autoplay_inaudible= 1 " +
                    "WHERE autoplay_audible = -1 AND autoplay_inaudible = -1",
            )
        }
    }

    @Suppress("MagicNumber")
    val migration_7_8 = object : Migration(7, 8) {
        override fun migrate(db: SupportSQLiteDatabase) {
            val hasCrossOriginStorageAccessColumn = db.query("SELECT * FROM site_permissions").columnCount == 12
            if (!hasCrossOriginStorageAccessColumn) {
                db.execSQL(
                    "ALTER TABLE site_permissions ADD COLUMN cross_origin_storage_access INTEGER NOT NULL DEFAULT 0",
                )
                // default is NO_DECISION
                db.execSQL("UPDATE site_permissions SET cross_origin_storage_access = 0")
            }
        }
    }
}
