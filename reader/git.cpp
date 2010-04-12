#include <QProcess>
#include <iostream>
#include <QFileInfo>
#include "git.h"
using namespace std;

bool Git::isFileInRepo(QString fileName)
{
    QFileInfo fileInfo(fileName);
    QProcess cmd;
    cmd.setWorkingDirectory(fileInfo.absolutePath());
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
void Git::startGit(QString fileName)
{
    QFileInfo fileInfo(fileName);
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
        
        //processOutput();
        //the output here are simply all the patches of the specified file
        //Rather then store those info onto harddisks wasting time read and write files
        //things will go much faster if we just store all the data into a container
        //like QStringList or QVector, and porvide each patch on demand
    }
}
