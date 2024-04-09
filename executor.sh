#!/usr/bin/bash
#cd build
mkdir build
cd build

cmake ..
kefile

read readable

change="set(VAR 3)"

# shellcheck disable=SC1068
writes = "set(VAR $readable)"

sed -i "s/$change/$writes" CMakeLists.txt

cmake --build .

cd /home/nikita/CLionProjects/untitled2/bigInt/build/src/Dynamic
./libbigInt2.a
