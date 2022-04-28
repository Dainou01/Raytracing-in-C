#!/bin/bash

if [[ ! -d out ]]; then
  mkdir out
fi

if [[ ! -d img ]]; then
  mkdir img
fi

g++ main.cpp -o out/main -lm
out/main > "img/$1.ppm"
feh --zoom max --geometry 1024x576  img/"$1.ppm"