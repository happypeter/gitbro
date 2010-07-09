#include <QApplication>
#include <iostream>
#include "display.h"
#include "git.h"
#include "common.h"
using namespace std;
/*!
@brief main of all

the des of main goes here

@param nIndex 0: Update, 1:Install, 2:Erase
*/
int main(int argc, char *argv[])
{
    QString absPath = OUTPUT_DIR;
/*
OUTPUT_DIR is the place where I need to put all the revesions of the selected file (generated by classGit), 
with names like v0, v1 ....
To generate all these files will be slow, I am going to change it in the future.
*/
    QApplication app(argc, argv);
    Git *git = new Git();
    git->fileName = "build.sh";//the file name shall be given by a QFileDialog or sth
    if(!git->isFileInRepo())
    {
        cout<<"file not in repo"<<endl;
        return -1;
    }
    else
    {
        git->startGit();
    }
    DisplayWidget display;
    display.filePath = absPath;
    display.showInitFile();
    display.resize(640, 512);
    display.setWindowTitle("the name of the file, baseName(absPath)");
    display.setGeometry(100,100,1300,700);
    display.show();
    return app.exec();
}

