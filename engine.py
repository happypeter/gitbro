#!/usr/bin/python
import os
repo_path = "/home/peter/test-repo/"
if os.path.exists(repo_path): #output files go here
    print "we are going to check "+repo_path 
else:
    print "can not find the repo"    

cwd = os.getcwd()
print cwd
os.chdir(repo_path)
cwd = os.getcwd()
print cwd

os.system("git log")
