#!/bin/bash          

# I suppose you have all the qt-doc pages in /var/www
cd /var/www
kw=$1".html" #concating two string is easy
name=$(ls|grep -i $kw) #no space is allowed between "name" and "="
echo --------
echo $name

lynx $name
#####            BUG          ####################
#
#  you have to give me the full name of the class
#  I do not care about the case, but if you give me
#  sth like "QStr", I will reply you with shit
#
#################################################

###########   vim setting #############################
#
# so I finally have this in my .vimrc
# map <F12> :!qref <cword><ENTER>
# 
################################################
