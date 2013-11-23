#!/bin/bash

# Do multiple blur runs on one image/size pair

set -e

IMG=$1
RADIUS=$1

function doblur {
    ./cprogs/blur $IMG $RADIUS 0 xxx | grep -- -blur
}
    


for r in {0..5}; do
    doblur $r
done

