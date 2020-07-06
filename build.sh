#!/bin/sh

#build script for CentOS 5

PATH=~/cmake-2.8/bin:$PATH
set -e
export OS=`uname`
if [ $OS = "Darwin" ]; then
    export BOOST=~/BldArea/boost/1_55_0
    if [ ! -d MacBuild ]; then
        mkdir MacBuild ; cd MacBuild ;
        cmake -D CMAKE_BUILD_TYPE:STRING=RelWithDebInfo -D TARGET_PLATFORM_32:BOOL=OFF -DCMAKE_OSX_SYSROOT=macosx -DCMAKE_OSX_DEPLOYMENT_TARGET=10.7 --build .. ;
        cd .. 
    fi ;
    pushd  MacBuild
    make -j 2
    popd
    rm -rf MacBuild
    exit
fi
echo "Build 32" ; 
if [ ! -d build32 ]; then
    mkdir build32 ; cd build32 ;
    scl enable devtoolset-2 'cmake -D TARGET_PLATFORM_32:BOOL=ON -D CMAKE_SHARED_LINKER_FLAGS:STRING=-m32 -D CMAKE_EXE_LINKER_FLAGS:STRING=-m32 -D CMAKE_BUILD_TYPE:STRING=RelWithDebInfo --build .. ';
    cd .. 
fi ;
cd build32 ;  scl enable devtoolset-2 'make -j 4' ; cd .. ; rm -rf build32

echo "Build 64" ; 
if [ ! -d build64 ]; then
    mkdir build64 ; cd build64 ;
    scl enable devtoolset-2 'cmake -D CMAKE_BUILD_TYPE:STRING=RelWithDebInfo -D TARGET_PLATFORM_32:BOOL=OFF --build .. ';
    cd .. 
fi ;
cd build64 ;  scl enable devtoolset-2 'make -j 4' ; cd ..; rm -rf build64

#strip -s bin/*
cd bin
rm -f *.{debug,a}
for i in *; do eu-strip -f $i.debug $i ; done
cd ..

function makeSelfArch() {
    local TARGET=AddInChrLin
    local TARGETLIB=libAddInNativeLin
    local ADIR="$1"
    [ -d ${ADIR} ] && rm -rf ${ADIR}
    mkdir ${ADIR}
    [ ! -d ./binsh ] && mkdir ./binsh
    cp ./bin/${TARGET}${ADIR} ${ADIR}
    cp ./bin/${TARGETLIB}${ADIR}.so ${ADIR}
    cp ./install_host.sh ${ADIR}/${TARGET}.sh
    sed -i -e "s|ARCHITECTURE|$ADIR|g" ${ADIR}/${TARGET}.sh

    cp ./AddInChromeSetup/com.1c.enterprise.addin.example.json ${ADIR}
    cp ./AddInChromeSetup/com.1c.enterprise.addin.example.FF.json ${ADIR}
    sed -i -e "s|ARCHITECTURE|$ADIR|g" ${ADIR}/com.1c.enterprise.addin.example.json
    sed -i -e "s|ARCHITECTURE|$ADIR|g" ${ADIR}/com.1c.enterprise.addin.example.FF.json

    makeself  --nox11 ${ADIR}/ ./binsh/${TARGET}${ADIR}.sh "1CExtIntgr82ChrLin" ./${TARGET}.sh "\\\"\`pwd\`\\\" \"\`dirname \$0\`\"" $@
    rm -rf ${ADIR}
}

makeSelfArch "32"
makeSelfArch "64"

tar -cjf bin.tar.bz2 binsh/ bin/
