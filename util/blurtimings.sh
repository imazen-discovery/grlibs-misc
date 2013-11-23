#!/bin/bash

# Run blur on successively increasing radiuses (also 0 -> old blur)
# and output the timings.

set -e

IMG=tmp-images/8s.jpg

function doblur {
    echo -n "$1:  "
    ./cprogs/blur $IMG $1 0 xxx | grep -- -blur
}
    


for r in {0..20}; do
    doblur $r
done

