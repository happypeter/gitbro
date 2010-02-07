#ifndef READER_H
#define READER_H
#include <iostream>
#include <QTextEdit>
#include <QMainWindow>
#include <QString>
#include "highlighter.h"

using namespace std;

class Reader:public QMainWindow
{
    Q_OBJECT
public:
    Reader();
    ~Reader();
    void openFile(const QString&);
private:
    void setupEditor();
    QTextEdit *editor;
    Highlighter *highlighter;
};
#endif //READER_H
