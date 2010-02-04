#ifndef READER_H
#define READER_H
#include <iostream>
#include <QPixmap>
#include <QTextEdit>
#include <QMainWindow>
using namespace std;

class Reader:public QMainWindow
{
    Q_OBJECT

public:
    Reader();
    ~Reader();
private:
    int showColor();
    int setColor();


};
#endif //READER_H
