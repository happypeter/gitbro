#!/bin/bash -x

#################################
#
#    Variables
#    
#################################
REPO_DIR=$HOME/gitbro ## only when gitbro has a checkout on website branch
POST_DIR=$REPO_DIR/posts
OUTPUT_DIR=$HOME/ooo
INDEX=$REPO_DIR/index.html
HEADER=$REPO_DIR/css/header.html
FOOTER=$REPO_DIR/css/footer.html
CSS=$REPO_DIR/css/gitbro.css
#################################
#
#    Update rudely
#    
#################################
rm -rf $OUTPUT_DIR
mkdir $OUTPUT_DIR

#################################
#
#    generate all_posts.html
#    
#################################
cd $POST_DIR
stat * -c %y" "%n|sort -r|awk -F" " '{print $1" "$4}'>all_posts.html
# now I need sth like this:
#
# <h2> 2010-08-21 <a href="website_as_branch.html">website_as_branch</a></h2>
#
# I am use sed for the job

#################################
#
#    start Converting
#    
#################################
cd $POST_DIR
for file in `ls .`
do
    markdown --html4tags $file>$file".tmp" 
    ## we should not have file prefix for posts
    ## otherwise we need to use basename here
    cat $HEADER $file".tmp" $FOOTER >$file".html"    
    rm *.tmp
    mv *.html $OUTPUT_DIR
done


#################################
#
#    final structuring
#    
#################################
cd $OUTPUT_DIR
cp $INDEX .
cp $CSS .

    ## creat a shell before you use ssh or rsync
    #ssh -t happypeter,gitbro@shell.sourceforge.net create

    #rsync -r --delete $OUTPUT_DIR  happypeter,gitbro@shell.sourceforge.net:/home/groups/g/gi/gitbro/htdocs/
