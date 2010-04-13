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
        QString string(ba);       //easy to convert QByteArray->QString
      //  cout<<"s---"<<qPrintable(s)<<endl;        
        QRegExp rx("commit [0-e]");
        QStringList stringList;
        stringList = string.split(rx);
        int v = 0;
        for(int i=0; i<stringList.size(); i++)
        {
            v++;
            cout<<"Patch------------- NO."<<v<<endl;
            cout<<stringList.at(i).toLocal8Bit().constData()<<endl;
        }
        //processOutput();

/*in order to cut the `s` into a StringList I think we need this:

  	QStringList 	split ( const QRegExp & rx, SplitBehavior behavior = KeepEmptyParts ) const

while the regExp here shall be 'commit+SAPCE+someHexNumber'
*/
    }
}
