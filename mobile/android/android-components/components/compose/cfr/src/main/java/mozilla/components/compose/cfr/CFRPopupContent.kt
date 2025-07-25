/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package mozilla.components.compose.cfr

import android.content.res.Configuration
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.layout.wrapContentHeight
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.ExperimentalComposeUiApi
import androidx.compose.ui.Modifier
import androidx.compose.ui.geometry.Offset
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.toArgb
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.semantics.semantics
import androidx.compose.ui.semantics.testTag
import androidx.compose.ui.semantics.testTagsAsResourceId
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.Dp
import androidx.compose.ui.unit.dp
import mozilla.components.compose.cfr.CFRPopup.IndicatorDirection.DOWN
import mozilla.components.compose.cfr.CFRPopup.IndicatorDirection.UP
import mozilla.components.ui.icons.R as iconsR

/**
 * Complete content of the popup.
 * [CFRPopupShape] with a gradient background containing [text] and a dismiss ("X") button.
 *
 * @param popupBodyColors One or more colors serving as the popup background.
 * @param dismissButtonColor The tint color that should be applied to the dismiss button.
 * @param indicatorDirection The direction the indicator arrow is pointing to.
 * @param indicatorArrowStartOffset Maximum distance between the popup start and the indicator arrow.
 * If there isn't enough space this could automatically be overridden up to 0.
 * @param onDismiss  Callback for when the popup is dismissed indicating also if the dismissal
 * was explicit - by tapping the "X" button or not.
 * @param title Optional [Text] composable to show just above the popup text.
 * @param text [Text] already styled and ready to be shown in the popup.
 * @param action Optional other composable to show just below the popup text.
 */
@OptIn(ExperimentalComposeUiApi::class)
@Composable
@Suppress("LongMethod")
fun CFRPopupContent(
    popupBodyColors: List<Int>,
    showDismissButton: Boolean,
    dismissButtonColor: Int,
    indicatorDirection: CFRPopup.IndicatorDirection,
    indicatorArrowStartOffset: Dp,
    onDismiss: (Boolean) -> Unit,
    popupWidth: Dp = CFRPopup.DEFAULT_WIDTH.dp,
    title: @Composable (() -> Unit)? = null,
    text: @Composable (() -> Unit),
    action: @Composable (() -> Unit) = {},
) {
    val popupShape = CFRPopupShape(
        indicatorDirection,
        indicatorArrowStartOffset,
        CFRPopup.DEFAULT_INDICATOR_HEIGHT.dp,
        CFRPopup.DEFAULT_CORNER_RADIUS.dp,
    )

    Box(modifier = Modifier.width(popupWidth + CFRPopup.DEFAULT_EXTRA_HORIZONTAL_PADDING.dp)) {
        Surface(
            color = Color.Transparent,
            // Need to override the default RectangleShape to avoid casting shadows for that shape.
            shape = popupShape,
            modifier = Modifier
                .align(Alignment.CenterStart)
                .background(
                    shape = popupShape,
                    brush = Brush.linearGradient(
                        colors = popupBodyColors.map { Color(it) },
                        end = Offset(0f, Float.POSITIVE_INFINITY),
                        start = Offset(Float.POSITIVE_INFINITY, 0f),
                    ),
                )
                .wrapContentHeight()
                .width(popupWidth),
        ) {
            Column(
                modifier = Modifier
                    .padding(
                        start = 16.dp,
                        top = 16.dp + if (indicatorDirection == CFRPopup.IndicatorDirection.UP) {
                            CFRPopup.DEFAULT_INDICATOR_HEIGHT.dp
                        } else {
                            0.dp
                        },
                        end = 16.dp,
                        bottom = 16.dp +
                            if (indicatorDirection == CFRPopup.IndicatorDirection.DOWN) {
                                CFRPopup.DEFAULT_INDICATOR_HEIGHT.dp
                            } else {
                                0.dp
                            },
                    ),
            ) {
                Box(
                    modifier = Modifier.padding(
                        end = if (showDismissButton) 24.dp else 16.dp, // 8.dp extra padding to the "X" icon
                    ),
                ) {
                    Column {
                        title?.let {
                            title()

                            Spacer(modifier = Modifier.height(8.dp))
                        }

                        text()
                    }
                }

                action()
            }
        }

        if (showDismissButton) {
            IconButton(
                onClick = { onDismiss(true) },
                modifier = Modifier
                    .align(Alignment.TopEnd)
                    .padding(
                        end = 6.dp,
                    )
                    .size(48.dp)
                    .semantics {
                        testTagsAsResourceId = true
                        testTag = "cfr.dismiss"
                    },
            ) {
                Icon(
                    painter = painterResource(iconsR.drawable.mozac_ic_cross_20),
                    contentDescription = stringResource(R.string.mozac_cfr_dismiss_button_content_description),
                    modifier = Modifier
                        // Following alignment and padding are intended to visually align the middle
                        // of the "X" button with the top of the text.
                        .align(Alignment.Center)
                        .padding(
                            top = if (indicatorDirection == CFRPopup.IndicatorDirection.UP) 9.dp else 0.dp,
                        )
                        .size(24.dp),
                    tint = Color(dismissButtonColor),
                )
            }
        }
    }
}

@Composable
@Preview(locale = "en", name = "LTR")
@Preview(locale = "ar", name = "RTL")
@Preview(uiMode = Configuration.UI_MODE_NIGHT_YES, name = "Dark theme")
@Preview(uiMode = Configuration.UI_MODE_NIGHT_NO, name = "Light theme")
private fun CFRPopupAbovePreview() {
    CFRPopupContent(
        popupBodyColors = listOf(Color.Cyan.toArgb(), Color.Blue.toArgb()),
        showDismissButton = true,
        dismissButtonColor = Color.Black.toArgb(),
        indicatorDirection = DOWN,
        indicatorArrowStartOffset = CFRPopup.DEFAULT_INDICATOR_START_OFFSET.dp,
        onDismiss = { },
        text = { Text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod") },
    )
}

@Composable
@Preview(locale = "en", name = "LTR")
@Preview(locale = "ar", name = "RTL")
@Preview(uiMode = Configuration.UI_MODE_NIGHT_YES, name = "Dark theme")
@Preview(uiMode = Configuration.UI_MODE_NIGHT_NO, name = "Light theme")
private fun CFRPopupBelowPreview() {
    CFRPopupContent(
        popupBodyColors = listOf(Color.Cyan.toArgb(), Color.Blue.toArgb()),
        showDismissButton = true,
        dismissButtonColor = Color.Black.toArgb(),
        indicatorDirection = UP,
        indicatorArrowStartOffset = CFRPopup.DEFAULT_INDICATOR_START_OFFSET.dp,
        onDismiss = { },
        text = { Text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod") },
    )
}

@Composable
@Preview(locale = "en", name = "LTR")
@Preview(locale = "ar", name = "RTL")
@Preview(uiMode = Configuration.UI_MODE_NIGHT_YES, name = "Dark theme")
@Preview(uiMode = Configuration.UI_MODE_NIGHT_NO, name = "Light theme")
private fun CFRPopupBelowPreviewWithTitle() {
    CFRPopupContent(
        popupBodyColors = listOf(Color.Cyan.toArgb(), Color.Blue.toArgb()),
        showDismissButton = true,
        dismissButtonColor = Color.Black.toArgb(),
        indicatorDirection = UP,
        indicatorArrowStartOffset = CFRPopup.DEFAULT_INDICATOR_START_OFFSET.dp,
        onDismiss = { },
        title = {
            Text(
                text = "This is the title",
                fontWeight = FontWeight.SemiBold,
            )
        },
        text = {
            Text("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod")
        },
    )
}
