# Conway's Wallpaper

A live wallpaper implementation of John Conway's Game of Life for Linux.

![Preview](preview.gif)

> [!NOTE]
> The actual program is significantly smoother than the GIF preview.

## What it Does

Conway's Wallpaper generates raw RGB frames from a simulation of Conway's Game
of Life and pipes them into video software, allowing the simulation to be
displayed as a live wallpaper.

## Why Use Video Software?

Most Linux desktop environments do not provide a universal way to modify the
wallpaper directly. By using software such as `mpvpaper`, Conway's Wallpaper
avoids desktop-environment-specific APIs.

## Dependencies

### Wayland
* MPV
* mpvpaper
* SDL3

### X11
* MPV
* xwinwrap
* SDL3

## Limitations

* Desktop icons may be hidden while the wallpaper is running.
* Currently optimized for 16:9 displays.
