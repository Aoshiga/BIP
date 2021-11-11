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
		
./tools/drbip/drbip shape.drbip output
./tools/drbip/scripts/mktemplates output
cp -f *.cpp output 2>/dev/null || true
cp -f *.h output 2>/dev/null || true
cp -f *.hpp output 2>/dev/null || true

cd build
cmake ../output
make

echo -ne '\a'
echo -ne '\a'
echo -ne '\a'
echo "Finished. Run: ./build/system"
