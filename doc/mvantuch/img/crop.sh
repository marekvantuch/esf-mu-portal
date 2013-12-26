#!/bin/bash
FILES=*.pdf
for f in $FILES
do
  if [[ $f != *crop.pdf ]] ; then

    c="${f%%.*}-crop.pdf"
    if [ -f $c ] ; then
      echo "Skipping $f file..."
    else
      echo "Processing $f file..."
      pdfcrop $f
    fi
  fi
done
