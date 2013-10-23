#!/bin/bash

set -e

URL=http://z.zr.io/ri/
WIDTHS="160 320 480 640 800 1200 1600 2048"

if [ -d util/ ] ; then
    true
else
    echo "This script must be run from the project root directory."
    exit 1
fi

[ -d tmp-images ] || mkdir tmp-images
cd tmp-images/

[ -d shrunk ] || mkdir shrunk
cd shrunk/


for w in $WIDTHS; do
    [ -d $w ] || mkdir $w

    for img in $*; do
        img=${img%.jpg}
        fn=$w/$img.png
        if [ -f $fn ]; then
            echo "Already have $fn; skipping."
        else
            echo "Fetching $w/$fn."
            wget "$URL$img.jpg?width=$w&format=png" -O $fn
        fi
    done
done


