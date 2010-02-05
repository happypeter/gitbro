#ifndef READER_H
#define READER_H
#include <iostream>
#include <QTextEdit>
#include <QMainWindow>
#include <QString>
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
};
#endif //READER_H
