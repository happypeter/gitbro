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

#FIXME, the following code has hole.
#what if $gitbro my-git-repo/file
### check if in a git repo --begin
cmd="git log>/dev/null"
if not os.system(cmd):
    print "OK, we are in a repo, Let's get to work..."
else:
    print "sorry gitbro only handles files in git, so Bye!"
    sys.exit(1)
### check if in a git repo --end

output_path = "/home/peter/output-gitbro/"
patch_dir = "patch/" 
#output_path is the dir we store all the output files
#including tmp files like git-info.txt and useful final output
#like all the patches, of course in the future we will make this
#patch configurable

if os.path.exists(output_path): #output files go here
    os.system("rm -rf "+output_path)
    os.system("mkdir "+output_path)
else:
    os.system("mkdir "+output_path)


os.system("mkdir -p "+output_path+patch_dir)

 
git_info_file = output_path + "git-info.txt"
git_cmd = "git log --follow "+file_name
cmd = git_cmd+">"+git_info_file
os.system(cmd)

def get_commit_hashes(file_name):
    """
actually we only need all the commit hash num
so now we will read git-info.txt
get all the commit number and save them in a list

    """
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
n=0
for commit in commit_list:
    git_cmd = "git show "+commit+' '+file_name
    patch_file_name = output_path + patch_dir +  file_name + "-" + str(n) + ".diff"
    cmd = git_cmd + ">" + patch_file_name
    os.system(cmd)
    n=n+1



patch_file_list = os.listdir(output_path+patch_dir) 
# print patch_file_list

for patch_file in  patch_file_list:

    print patch_file
