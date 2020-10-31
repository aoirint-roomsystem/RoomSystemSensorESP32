#!/bin/bash

set -eu

SERIAL_PORT="$1"

./compile.sh && ./upload.sh "$SERIAL_PORT" && ./serialmon.sh "$SERIAL_PORT"

