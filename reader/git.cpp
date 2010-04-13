#include <QVariant>
#include <QProcess>
#include <iostream>
#include <QFileInfo>
#include "git.h"
#include "common.h"
using namespace std;

Git::Git()
{
//nothing to do now
}
/*
we can use this function to detect if we start git-reader in a repo or not
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
        ba = ba.trimmed();   //remove the trailing '\n'
        QString string(ba);       //easy to convert QByteArray->QString
        outPutString = string;
  }
}

void Git::generatePatches()
{
        QRegExp rx("commit [0-e]");
        // rx here means 'commit+SAPCE+onlyOneHexNumber', it is not perfect
        QStringList stringList;
        stringList = outPutString.split(rx);
        int v = 0;
        cmd.setWorkingDirectory(OUTPUT_DIR);
        cmd.start("mkdir", QStringList()<<"ppp");
        if (!cmd.waitForFinished())
        {
            cout<<"failed"<<endl;
        }

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
 

}
