#ifndef APPLE_H
#define APPLE_H
#include <iostream>
#include <QPixmap>
#include <QTextEdit>
using namespace std;
class reader
{
public:
reader();
~reader();
string color;
QPixmap newImage;
QTextEdit textEdit;
int showColor();
int setColor();
};
#endif //APPLE_H
