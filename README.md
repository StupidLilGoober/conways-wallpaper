# Conway's Wallpaper

John Conway's Game of Life on the Linux wallpaper.

## What it Does

Conway’s Wallpaper generates raw RGB frames from a simulation of Conway's Game
of Life, and then runs it through a video software where it can then be placed
onto the wallpaper.

### Why Run Through a Video?

For most Linux setups, you can't directly edit the wallpaper without using
setup-specific libraries. By running through something like `mpvpaper`, there
is not longer a need to use such a library.

## Dependencies

* MPV - The video software that `mpvpaper` uses to render to the wallpaper.
* `mpvpaper` - Software that renders videos onto the wallpaper. (Wayland)
* `xwinwrap` - Software that renders videos onto the wallpaper. (X11)
* SDL3 - Used for timing primarily.

---

## Known Issues

* Completely covers desktop icons
* Is not full 16:9 ratio
