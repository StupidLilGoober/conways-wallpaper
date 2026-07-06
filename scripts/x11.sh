#!/bin/sh

./conways_wallpaper | xwinwrap -ni -fs -un -s -st -sp -b -nf -- \
mpv -wid WID \
    --no-audio \
    --demuxer=rawvideo \
    --demuxer-rawvideo-w=640 \
    --demuxer-rawvideo-h=480 \
    --demuxer-rawvideo-mp-format=rgb24 \
    --demuxer-rawvideo-fps=60 \
    -
