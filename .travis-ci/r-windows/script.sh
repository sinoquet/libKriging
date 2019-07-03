#!/usr/bin/env bash
set -eo pipefail

if [[ "$DEBUG_CI" == true ]]; then
  set -x
fi

# Default configuration when used out of travis-ci
if [[ -n ${TRAVIS_BUILD_DIR:+x} ]]; then
echo
    cd ${TRAVIS_BUILD_DIR}
fi

# make
export PATH="/c/Program Files/make/make-4.2.1/bin":${PATH}
# R shortcut
export PATH=${HOME}/Miniconda3/Scripts:${PATH}
# gcc for R
export PATH=$HOME/Miniconda3/Rtools/mingw_64/bin:$PATH
# OpenBLAS installation
export EXTRA_SYSTEM_LIBRARY_PATH=${HOME}/Miniconda3/Library/lib

# Crazy hack since R try to call 'g++ ' as compiler
# Message looks like:
# /usr/bin/sh: line 8: g++ : command not found
#       with a space here ^
ln -sf "$(which g++).exe" "$(which g++) .exe"

cd bindings/R
make clean
make
make test