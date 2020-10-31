#!/bin/bash

set -eu

SERIAL_PORT="$1"
BAUDRATE=115200

screen "$SERIAL_PORT" "$BAUDRATE"

