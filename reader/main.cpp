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
    QString absPath = "/home/peter/file/";//use argv[1] insteasd
    QApplication app(argc, argv);
    DisplayWidget display;
    display.filePath = absPath;
    display.resize(640, 512);
    display.setWindowTitle("the name of the file, baseName(absPath)");
    display.show();
    return app.exec();
}

