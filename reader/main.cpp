#include <QApplication>
#include <iostream>
#include "display.h"
using namespace std;
/*!
@brief main of all

the des of main goes here

@param nIndex 0: Update, 1:Install, 2:Erase
*/
int main(int argc, char *argv[])
{
    QString absPath = "/home/peter/tmp-git/";
    QApplication app(argc, argv);
    DisplayWidget display;
    display.filePath = absPath;
    display.showInitFile();
    display.resize(640, 512);
    display.setWindowTitle("the name of the file, baseName(absPath)");
    display.setGeometry(100,100,1300,700);
    display.show();
    return app.exec();
}

