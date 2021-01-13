#!/bin/bash

build () {
  if [[ -d "./build" ]]; then
    rm -rf build
  fi
  mkdir build
  cd build
  emcmake cmake ..
  emmake make
  cd ..
}

start () {
  python -m http.server --directory ./build
}

if [[ $1 == "start" ]]; then
  start
else if [[ $1 == "build" ]]; then
  build
else
  echo "Usage: webppcli [COMMAND]

  build		to build the project.
  start		to start the project.
"
fi
fi
