#!/bin/bash

if [[ ! -d out ]]; then
  mkdir out
fi

if [[ ! -d img ]]; then
  mkdir img
fi

gcc main.c -o out/main
out/main > "img/$1.ppm"
feh --zoom max --geometry 1024x1024 img/"$1.ppm"