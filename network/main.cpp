#include <QApplication>
#include <iostream>
#include "screen.h"
using namespace std;
/*!
@brief main of all

the des of main goes here

@param nIndex 0: Update, 1:Install, 2:Erase
*/
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Screen screen;
    screen.resize(640, 512);
    screen.show();
    return app.exec();
}

