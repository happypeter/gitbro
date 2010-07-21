#include <QVariant>
#include <QProcess>
#include <iostream>
#include <QFileInfo>
#include "git.h"
#include "common.h"
using namespace std;

/** 
* @brief maybe I can use the constructor to check if git is available on the
* system or not
*/
Git::Git()
{
//nothing to do now
}
/** 
* @brief  
we can use this function to detect if we start git-reader in a repo or not
* 
* @return 
*/
bool Git::isFileInRepo()
{
    QFileInfo fileInfo(fileName);
    QProcess cmd;
    cmd.setWorkingDirectory(fileInfo.absolutePath());
    cout<<"absolutePath"<<qPrintable(fileInfo.absolutePath())<<endl;
    //'git rev-parse --is-inside-work-tree', inspired by qgit/src/git_stratup.cpp
    cmd.start("git", QStringList()<<"rev-parse"<<"--is-inside-work-tree");
    if (!cmd.waitForFinished())
    {
        cout<<"failed"<<endl;
    }
    QByteArray ba;
    ba = cmd.readAllStandardOutput();
    ba = ba.trimmed();   //remove the trailing '\n'
    QString s(ba);       //easy to convert QByteArray->QString
    if(s == "true")
        return true;
    else
        return false;

}
void Git::startGit()
{
    QFileInfo fileInfo(fileName);
    cout<<"startGit---"<<qPrintable(fileName)<<endl;
    QProcess cmd;
    cmd.setWorkingDirectory(fileInfo.absolutePath()); 
    cmd.start("git", QStringList()<<"log"<<"-p"<<"--follow"<<fileName);
    if (!cmd.waitForFinished())
    {
        cout<<"failed"<<endl;
    }
    else
    {
        QByteArray ba;
        ba = cmd.readAllStandardOutput();
        ba = ba.trimmed();  
        QString string(ba);
        outPutString = string;
    }
    generatePatches();
    // if we do things this way, what's  the point of using Qt, it is not OOP
    // anymore, why not just write bash script to do the job here, and then
    // use Qt to implement a nice looking gui as front-end to the script,
    // Clearer design, less coding
    generateRevisions();
}

void Git::generatePatches()
{
    QRegExp rx("commit [0-e]");
    // rx here means 'commit+SAPCE+onlyOneHexNumber', it is not perfect
    QStringList stringList;
    stringList = outPutString.split(rx);
    int v = 0;
    for(int i=0; i<stringList.size(); i++)
    {
        v++;
        QString patchName("p");
        QVariant variant(v);
        QString ver = variant.toString(); 
        patchName.append(ver).append(".diff");
        cout<<qPrintable(patchName)<<endl;
        cout<<"Patch------------- NO."<<v<<endl;
        cout<<stringList.at(i).toLocal8Bit().constData()<<endl;
    }
    //FIXME: need to write all patches into files and store them in OUTPUT_DIR
}

void Git::generateRevisions()
{
//apply to the patches in OUTPUT_DIR, to produce v1, v2...
    QProcess genRev;
    cout<<"------------generateRevisions()"<<endl;
    genRev.setWorkingDirectory(OUTPUT_DIR);
    genRev.start("mkdir", QStringList()<<"xxx");
    if (!genRev.waitForFinished())
    {
        cout<<"failed"<<endl;
    }
    //FIXME: need to apply patches to get revisions.
}
