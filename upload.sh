#!/bin/bash

set -eu

SERIAL_PORT="$1"
SKETCH="$(basename $PWD).ino"
ARGS="${@:2}"

arduino-cli upload \
    -b esp32:esp32:esp32 \
    -p "$SERIAL_PORT" \
    "$ARGS"

