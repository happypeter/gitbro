#ifndef DISPLAY_CPP
#define DISPLAY_CPP

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
    QString filePath;
private slots:
    void showFile(int);

private:

    QLineEdit *lineEdit;
    QPushButton *newerButton;
    QSpinBox *spinBox;
    Reader *reader;
    void   paintEvent ( QPaintEvent * event );
};

#endif // DISPLAY_HPP
