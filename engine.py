#!/usr/bin/python
import os,sys
if len(sys.argv)!=2:
   print """
gitbro: missing operand
Usage:
      $gitbro filename
          """
   sys.exit(1)
file_name = sys.argv[1] # this is the file we are working on
### check if in a git repo --begin
cmd="git log>/dev/null"
if not os.system(cmd):
    print "OK, we are in a repo, Let's get to work..."
else:
    print "sorry gitbro only handles files in git, so Bye!"
    sys.exit(1)

### check if in a git repo --end

output_path = "/home/peter/output_gitbro/"
patch_stage1_dir = "patch_stage1/" 
patch_stage2_dir = "patch_stage2/"
#output_path is the dir we store all the output files
#including tmp files like git-info.txt and useful final output
#like all the patches, of course in the future we will make this
#patch configurable

if os.path.exists(output_path): #output files go here
    os.system("rm -rf "+output_path)
    os.system("mkdir "+output_path)
else:
    os.system("mkdir "+output_path)


os.system("mkdir -p "+output_path+patch_stage1_dir)
os.system("mkdir -p "+output_path+patch_stage2_dir)

 
git_info_file = output_path + "git-info.txt"
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
        if not line.find("commit"): #'commit' at the beginning of the str
            print line
            line = line.replace("commit","")
            commit_hash_list.append(line.strip())
            #strip() to remove trailing '\n'
        if not line:
            done = 1 #stop
    return commit_hash_list


commit_list = get_commit_hashes(git_info_file)
commit_list.reverse()
#we reverse the list since we want the first commit first
#so that we can generate the first patch first, look shown below
first_commit = commit_list[0]
#we need this to get v0(original version) of the file_name

#####get v0 begin####
cmd="git checkout -b "+file_name+' '+first_commit
os.system(cmd)
cmd="cp -rf "+file_name+' '+output_path
#This Problem Fixed
os.system(cmd)
cmd="git checkout master"
os.system(cmd)
cmd="git branch -D "+file_name
os.system(cmd)
####get vo end####

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
    old_commit = commit
    new_commit = commit_list[n]
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

# FIXME: Now we only search in the first line of each patch,like 
# "diff --git a/dir/filename"
# this is much safer
# PROBLEM: if some 'dir' name is the same as filename
# however this is a rare case 
def remove_other_file(patch_name):
    f1 = open(patch_name, "r")
    lines = f1.read()
    line_list = lines.split(split_word)
    print line_list
    for line in line_list:
        list = line.split('\n')
        if list[0].find(file_name)>0:
            print "we find it:"
            useful_data = split_word + line 
            short_patch_name = os.path.basename(patch_name)
            stage2_full_patch_name = output_path+patch_stage2_dir+short_patch_name 
            f2 = open(stage2_full_patch_name, "w")
            f2.write(useful_data)

patch_file_list = os.listdir(output_path+patch_stage1_dir) 
# print patch_file_list

for patch_file in  patch_file_list:
    patch_file = output_path+patch_stage1_dir+patch_file
    # we are currently using absolute path for everthing
    remove_other_file(patch_file)

