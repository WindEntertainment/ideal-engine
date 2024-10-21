#!/bin/bash

source "$(dirname "$0")/global.sh"

with_coverage=false
with_dependencies=false

root=""

while [[ "$#" -gt 0 ]]; do
  case $1 in
    -wc|--with-coverage) with_coverage=true; ;;
    -wd|--with-dependencies) with_dependencies=true; ;;
    --root) root="$2"; shift; ;;
    *) echo "Unknown parameter passed: $1" ;;
  esac
  shift
done

cd "$root" || exit

if [[ $with_dependencies = true ]]; then
  rm -rf build
  wm run conan-install -bt Debug
fi

wm run cmake-configure --build-type Debug --with-testing

cd "$root/build/app/build/Debug/tests" || exit

if [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "win32" ]]; then
  cmake --build "$root/build/app/build/Debug" --config Debug --parallel 10 --target "native-tests" --verbose
else
  cmake --build "$root/build/app/build/Debug" --parallel 10 --target "native-tests" --verbose
fi

ctest

if [[ $with_coverage = true ]]; then
  cd "../" || exit

  if [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "win32" ]]; then
    cmake --build "$root/build/app/build/Debug" --config Debug --parallel 10 --target "coverage" --verbose
  else
    cmake --build "$root/build/app/build/Debug" --parallel 10 --target "coverage" --verbose
  fi

fi

cd "$root" || exit
