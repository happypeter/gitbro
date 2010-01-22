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
git_info_file = "/home/peter/git-info.txt"
file_name = "out"
git_cmd = "git log --follow "+file_name
cmd = git_cmd+">"+git_info_file
os.system(cmd)
#actually we only need all the commit hash num
#so now we will read git-info.txt, get all the commit number and save them in a list
#and I think I need a function to do this for me

def get_commit_hashes(file_name):
    f=open(file_name,"r");
    done = 0
    commit_hash_list = []
    while not done:
        line = f.readline()
        if not line.find("commit"):
            print line
            line = line.replace("commit","")
            commit_hash_list.append(line.strip())
            #strip() to remove trailing '\n'
        if not line:
            done = 1 #stop
    return commit_hash_list

commit_list = get_commit_hashes(git_info_file)
print commit_list
commit_list.reverse()
#we reverse the list since we want the oldest commit first
#so that we can generate the first patch first, look shown below
for commit in commit_list:
    print commit
