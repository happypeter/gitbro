#!/bin/bash

POSTDIR=../posts/
OUTPUTDIR=$HOME/gitbro-output
mkdir $OUTPUTDIR
cd $POSTDIR
echo
echo 1-------
echo $POSTDIR
pwd
echo 1^^^^^^^
echo
for file in `ls .`
do
    echo
    echo 2--------
    echo $PWD
    echo $file
    echo 2^^^^^^^^
    echo
    markdown $file>$file".html"
    mv *.html $OUTPUTDIR
done

## then we can use `cat` to add header&footer to the output htmls
