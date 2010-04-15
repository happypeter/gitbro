#!/bin/bash          

# I suppose you have all the qt-doc pages in /var/www
cd /var/www
kw=$1".html" #concating two string is easy
name=$(ls|grep -i $kw) #no space is allowed between "name" and "="
echo --------
echo $name

lynx $name

#put me in $PATH and use me this way
#peter@cow:~$ qref QString 

#####            BUG          ####################
#
#  you have to give me the full name of the class
#  I do not care about the case, but if you give me
#  sth like "QStr", I will reply you with shit
#
#################################################

###########   TODO #############################
#
# It will be nice, if I can pass the name under
# the cursor with a shortcut in Vim
# maybe I need to write a vim script?
#
################################################
