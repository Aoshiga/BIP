#!/bin/bash
set -e
set -x verbose

#cp model/* .

rm -rf build output *.json
mkdir -p output build


./tools/bipc/bin/bipc.sh -p HelloPackage -d "HelloCompound()" \
	-f 'ujf.verimag.bip.middleend.gluetranslator.GluetranslatorFilter!ujf.verimag.bip.middleend.xflattening.XflatteningFilter' \
    -I model \
    --gencpp-output-dir output

echo "-------- BIP COMPILATION OK"


./tools/drbip/drbip model/HelloPackage.drbip output/Deploy model
./tools/drbip/scripts/mktemplates HelloPackage output/Deploy
cp -f model/*.cpp output/Deploy 2>/dev/null || true
cp -f model/*.h output/Deploy  2>/dev/null || true
cp -f model/*.hpp output/Deploy 2>/dev/null || true

echo "-------- DR-BIP COMPILATION OK"


cd build
cmake ../output
make

echo "Finished. Run: ./build/system"