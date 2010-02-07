#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include <QWidget>
#include "reader.h"

class QLineEdit;
class QPushButton;

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:                                                                                
    DisplayWidget();
private slots:
    void showNewer();

private:

    QLineEdit *lineEdit;
    QPushButton *newerButton, *olderButton;
    Reader *reader;

};

#endif // DISPLAY_HPP
