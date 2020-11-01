#!/bin/bash

set -eu

SKETCH="$(basename $PWD).ino"

if [ -f .env ]; then
    echo "Found .env file."
    export $(cat .env | sed 's/#.*//g' | xargs)
fi

DEFINES="-DSECRET_FIREBASE_HOST=$FIREBASE_HOST"
DEFINES="${DEFINES} -DSECRET_FIREBASE_AUTH=$FIREBASE_AUTH"
DEFINES="${DEFINES} -DSECRET_WIFI_SSID=$WIFI_SSID"
DEFINES="${DEFINES} -DSECRET_WIFI_PW=$WIFI_PW"
DEFINES="${DEFINES} -DSOUND_VOLUME=$SOUND_VOLUME"

arduino-cli compile \
    -b esp32:esp32:esp32 \
    --build-properties \
        "build.defines=${DEFINES}" \
    "$SKETCH" "$@"
