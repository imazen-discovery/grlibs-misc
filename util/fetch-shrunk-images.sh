#!/bin/bash

set -e

FS_URL=http://s3.amazonaws.com/resizer-images
URL=http://z.zr.io/ri/
WIDTHS="160 320 480 640 800 1200 1600 2048"

if [ -d util/ ] ; then
    true
else
    echo "This script must be run from the project root directory."
    exit 1
fi

if [ "$1" = "" ]; then
    echo "USAGE: $0 [<filename> ... | - ]"
    exit 1
fi

if [ "$1" = '-' ]; then
    FILES="11s.jpg 11.jpg 12s.jpg 12.jpg 8.jpg 8.jpg 8s.jpg 15.jpg 15s.jpg
           22s.jpg 22.jpg 13.jpg 13s.jpg"
else
    FILES=$*
fi


[ -d tmp-images ] || mkdir tmp-images
cd tmp-images/

[ -d shrunk ] || mkdir shrunk
cd shrunk/

echo "Fetching original images."
for img in $FILES; do
    if [ -f $img ]; then
        echo "Already have '$img'.  Skipping."
    else
        wget "$FS_URL/$img"
    fi
done

echo "Fetching shrunk images."
for w in $WIDTHS; do
    [ -d $w ] || mkdir $w

    for img in $FILES; do
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


