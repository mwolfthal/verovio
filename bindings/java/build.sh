#!/bin/bash

RM=/usr/bin/rm
FIND=/usr/bin/find
SWIG=/cygdrive/d/opt/swig/bin/swig.exe
mkdir -p src/main/java/org/rismch/verovio
mkdir -p target/classes/META-INF/lib

# generate the git commit include file
cd ..
../tools/get_git_commit.sh
cd java

cd swig
${SWIG} -c++ -java -package org.rismch.verovio -outdir ../src/main/java/org/rismch/verovio verovio.i
cd ..

#SRCFILES=$(ls ../../src/*.cpp ../../libmei/dist/*.cpp ../../libmei/addons/*.cpp)
#ALL_FILES="$SRCFILES \
# ../../src/pugi/pugixml.cpp \
# ../../src/midi/Binasc.cpp \
# ../../src/midi/MidiEvent.cpp \
# ../../src/midi/MidiEventList.cpp \
# ../../src/midi/MidiFile.cpp \
# ../../src/midi/MidiMessage.cpp \
# ../../src/hum/humlib.cpp \
# ../../src/json/jsonxx.cc \
# ../../src/crc/crc.cpp"

SOURCES=$(${FIND} ../../libmei/dist ../../libmei/addons ../../src  \
-type f \( -iname \*.cc -o -iname \*.cpp \) -print0 | xargs -0 )

CXXOPTS="-g -fpic -m64 -Wa,-mbig-obj -std=c++23 \
-I../../include -I../../include/vrv -I../../include/json \
-I../../include/hum -I../../include/crc -I../../include/midi -I../../include/pugi \
-I../../include/zip -I../../libmei/addons -I../../libmei/dist \
-I/usr/java/include -I/usr/java/include/linux"

#test compilation of the wrapper
#g++ -c $CXXOPTS verovio_wrap.cxx

g++ -shared -o target/classes/META-INF/lib/libverovio.jnilib $CXXOPTS swig/verovio_wrap.cxx $SOURCES

#cp target/libverovio.jnilib target/classes/META-INF/li
${RM} ${TMPDIR}/*.o


