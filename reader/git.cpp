#include <QProcess>
#include <iostream>
#include <QFileInfo>
#include "git.h"
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
        QString s(ba);       //easy to convert QByteArray->QString
      //  cout<<"s---"<<qPrintable(s)<<endl;
        
        //processOutput();
        //the output here are simply all the patches of the specified file
        //Rather then store those info onto harddisks wasting time read and write files
        //things will go much faster if we just store all the data into a container
        //like QStringList or QVector, and porvide each patch on demand
    }
}
