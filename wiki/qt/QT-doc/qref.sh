#!/bin/bash          

# I suppose you have all the qt-doc pages in /var/www
cd /var/www
kw=$1".html" #concating two string is easy
name=$(ls|grep -i $kw) #no space is allowed between "name" and "="
echo --------
echo $name

lynx $name

#put me in $PATH and use me this way (named qref.sh->qref)
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
# mv the cursor to "QString"
#":!qref <cword>" will take you to the doc page
# so I finally have this in my .vimrc
# map <F12> :!qref <cword>
# use <ENTER> rater than  helps a lot on readablity and also eliminate the
# danger of ``->`^M` convertion when you try to do copy and paste
# "" is not two characters but one, it is produced by Ctr+v+Enter in Insert Mode
# If I do not use it, I have to type a Enter after I press <F12>
# REF: http://hea-www.harvard.edu/~fine/Tech/vi.html
# ^V - insert next character even if it is a editing character. 
# this is not very simple, but finally I have my vim works like Qtcreator with
# class doc just one click away!!
# 
################################################

###############################################
#
#and next time I see tons of  in my driver.c
#I can use :%s///gc to remove them all
#now I know it is just Enter in its visual form 
#but the prolem most happens when you create a file
#in Windows and open it in linux. Since I do not use Windows now
#so this won't happen very often
###############################################

