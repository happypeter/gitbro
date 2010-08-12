#!/bin/bash -x

REPO_DIR=$HOME/website-gitbro
POST_DIR=$REPO_DIR/posts
OUTPUT_DIR=$HOME/gitbro-output
HEADER=$REPO_DIR/css/header.html
FOOTER=$REPO_DIR/css/footer.html
rm -rf $OUTPUT_DIR
mkdir $OUTPUT_DIR
cd $POST_DIR
for file in `ls .`
do
    markdown $file>$file".html"
    mv *.html $OUTPUT_DIR
done

## then we can use `cat` to add header&footer to the output htmls

