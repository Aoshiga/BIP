#!/bin/bash
set -e
set -x verbose

mkdir -p output build

#bipc.sh -I . -p BlinkyBlock -d "BlinkyBlock()" \
bipc.sh -I . -p shape -d "shape()" \
    --gencpp-follow-used-packages \
		--gencpp-cc-I . \
		--gencpp-cc-extra-src ext_code/ext.cpp \
		--gencpp-output output
cd build
cmake ../output
make

echo -ne '\a'
echo -ne '\a'
echo -ne '\a'
echo "Finished. Run: ./build/system"
