#ifndef DISPLAY_CPP
#define DISPLAY_CPP

#include <QWidget>
#include <QSpinBox>
#include "reader.h"
#include "git.h"

class QLineEdit;
class QPushButton;

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:                                                                       
    DisplayWidget();
    void startGit(QString);
    void showInitFile();
    QString filePath;
    bool isFileInRepo(QString);

public slots:
    void showFile(int);

private:
    Git *git;
    QLineEdit *lineEdit;
    QPushButton *newerButton;
    QSpinBox *spinBox;
    Reader *reader;
    void   paintEvent ( QPaintEvent * event );
};

#endif // DISPLAY_HPP
