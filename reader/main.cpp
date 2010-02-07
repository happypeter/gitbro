#include <QApplication>
#include <iostream>
#include "reader.h"
using namespace std;
/*!
@brief main of all

the des of main goes here

@param nIndex 0: Update, 1:Install, 2:Erase
*/
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Reader reader;
    QStringList args = app.arguments();
    args.removeFirst(); // program name.. 
    QString filename = args.join(" ");
    cout<<filename.length()<<endl;//see qt-creator/src/tools/texteditor/
    reader.openFile(filename);    // to know how to handle files
    reader.resize(640, 512);
    reader.show();
    return app.exec();
}

