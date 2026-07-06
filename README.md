# Conway's Wallpaper

John Conway's game of life on the Linux wallpaper using a clever trick with
`mpvpaper`.

## What it Does

Conway's Wallpaper takes raw RGB frames from the SDL3 "game" and flushes them
to `stdout`. From there, they are read by `mpvpaper` as if they were a video,
and rendered onto the wallpaper.
