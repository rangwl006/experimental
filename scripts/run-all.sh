#!/bin/bash

function clean_folder()
{
  for FILE in ${INSTALL_PATH}; do
    if [[ -d $FILE ]]; then
      rm -rf $FILE
    fi
  done
}

clean_folder

cmake build -S /builder -B /builder/build
cmake --build /builder/build
cmake --install /builder/build

echo "START: EXECUTION OF ALL BUILT PROGRAMS"

for FILE in ${INSTALL_PATH}/*/*/*; do
  if [[ -x "$FILE" ]]; then
    echo "##### STARTING PROGRAM: $FILE"
    "$FILE"
    echo "##### END OF PROGRAM: $FILE"
fi
done

echo "ENDED: EXECUTION OF ALL BUILT PROGRAMS"
