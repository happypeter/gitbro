#ifndef DISPLAY_H
#define DISPLAY_H 

#include <QWidget>
#include <QSpinBox>
#include "reader.h"

class QLineEdit;
class QPushButton;

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:                                                                       
    DisplayWidget();
    void showInitFile();
    QString filePath;

public slots:
    void showFile(int);

private:
    QLineEdit *lineEdit;
    QPushButton *newerButton;
    QSpinBox *spinBox;
    Reader *reader;
    void   paintEvent ( QPaintEvent * event );
};

#endif // DISPLAY_H
