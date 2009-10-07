#ifndef APPLE_H
#define APPLE_H
#include <iostream>
#include <QPixmap>
using namespace std;
class reader
{
public:
reader();
~reader();
string color;
QPixmap newImage;
int showColor();
int setColor();
};
#endif //APPLE_H
