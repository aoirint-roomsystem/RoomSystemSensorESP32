#!/bin/bash

set -eu

SKETCH="$(basename $PWD).ino"

if [ -f .env ]; then
    echo "Found .env file."
    export $(cat .env | sed 's/#.*//g' | xargs)
fi

arduino-cli compile \
    -b esp32:esp32:esp32 \
    --build-properties \
        "build.defines=-DSECRET_FIREBASE_HOST=$FIREBASE_HOST -DSECRET_FIREBASE_AUTH=$FIREBASE_AUTH -DSECRET_WIFI_SSID=$WIFI_SSID -DSECRET_WIFI_PW=$WIFI_PW" \
    "$SKETCH" "$@"

