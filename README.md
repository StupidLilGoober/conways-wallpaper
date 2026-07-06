# Conway's Wallpaper

John Conway's Game of Life on the Linux wallpaper using a clever trick with
`mpvpaper`.

## What it Does

Conway’s Wallpaper generates raw RGB frames using an SDL3-based simulation of Conway’s Game of Life. 
These frames are streamed as a continuous video-like output, via stdout. The stream is consumed by MPV, 
which decodes the raw frame data and renders it in real time. MPV is then attached to the desktop 
background using mpvpaper, allowing the simulation to function as a live wallpaper.

## Dependencies

* MPV
* `mpvpaper`
