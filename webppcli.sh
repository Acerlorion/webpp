#!/bin/bash

build_ems () {
  if [[ -d "./build" ]]; then
    rm -rf build
  fi
  mkdir build
  cd build
  emcmake cmake ..
  emmake make
  cd ..
}

start_ems () {
  python -m http.server --directory ./build
}

build_vanilla () {
  if [[ -d "./build" ]]; then
    rm -rf build
  fi
  mkdir build
  cd build
  cmake ..
  make
  cd ..
}

if [[ $1 == "start_ems" ]]; then
  start_ems
fi

if [[ $1 == "build_ems" ]]; then
  build_ems
fi

if [[ $1 == "build_vanilla" ]]; then
  build_vanilla
fi
