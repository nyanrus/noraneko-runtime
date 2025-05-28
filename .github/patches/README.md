# Useful diff command

```bash
git diff HEAD -- . :^.github :^browser/branding/noraneko :^noraneko > .github/patches/[dir]/[filename].patch
```

```bash
git stash -- ':!.github'
```