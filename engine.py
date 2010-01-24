#!/usr/bin/python
import os
repo_path = "/home/peter/test-repo/"
output_path = "/home/peter/output_gitbro/"
patch_stage1_dir = "patch_stage1/" 
patch_stage2_dir = "patch_stage2/"
#output_path is the dir we store all the output files
#including tmp files like git-info.txt and useful final output
#like all the patches, of course in the future we will make this
#patch configurable
tmp_path = output_path
if os.path.exists(repo_path): #repo  go here
    print "we are going to check "+repo_path 
else:
    print "can not find the repo"   
if os.path.exists(output_path): #output files go here
    os.system("rm -rf "+output_path)
    print "old output_path removed"
    os.system("mkdir "+output_path)
else:
    os.system("mkdir "+output_path)

os.chdir(output_path)
print "now cwd: "+os.getcwd()
os.system("mkdir "+patch_stage1_dir)
os.system("mkdir "+patch_stage2_dir)

 

cwd = os.getcwd()
print cwd
os.chdir(repo_path)
cwd = os.getcwd()
print cwd
git_info_file = tmp_path + "git-info.txt"
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
n = 0
list_size = len(commit_list)
# the code in the following for loop is a little cumbersome 
# but it actually does sth really easy, just get all the diffs 
# of all the versions of the file named out and save these diffs 
# into patch files
for commit in commit_list:
    n = n+1
    if n == list_size:
        break
 
    print commit
    old_commit = commit
    print "old_commit:"
    print old_commit
    new_commit = commit_list[n]
    print "new_commit:"
    print new_commit
    git_cmd = "git diff -u "+old_commit+" "+new_commit
    patch_file_name = output_path + patch_stage1_dir +  file_name + "-" + str(n) + ".diff"
    cmd = git_cmd + ">" + patch_file_name
    os.system(cmd)

# now the problem is many of the patches obtained contain diffs for not 
# only out, but also some other files, so we need to get rid of the junk info
# the flow is aimple the patch file may contain many parts separated by a line
#
#   diff --git a/out b/out
# so we just search "diff --git a/", if this is followed by "out", then this
# part is what we want, anything else just remove

split_word = "diff -"
search_word = "-git a/"
#note:
# split_word + search_word = "diff --git a/"
search_keyword = search_word + file_name

# FIXME: so it works, but what if there is a patch file(as a <example> maybe) 
# inside a patch?
# then we will have problem
def remove_other_file(patch_name):
    f1 = open(patch_name, "r")
    lines = f1.read()
    line_list = lines.split(split_word)
    for line in line_list:
        if not line.find(search_keyword):
             print "the line:----"
             print line
             useful_data = ''
             useful_data = split_word + line 
             print "useful_data*****************"
             print useful_data
             print "**************"
             short_patch_name = os.path.basename(patch_name)
             print "short_patch_name:  "+ short_patch_name
             stage2_full_patch_name = output_path+patch_stage2_dir+short_patch_name 
             f2 = open(stage2_full_patch_name, "w")
             f2.write(useful_data)


patch_file_list = os.listdir(output_path+patch_stage1_dir) 
# print patch_file_list

for patch_file in  patch_file_list:
    patch_file = output_path+patch_stage1_dir+patch_file
    # we are currently using absolute path for everthing
    remove_other_file(patch_file)

