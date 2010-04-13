#ifndef GIT_H
#define GIT_H

#include <QWidget>

class Git : public QWidget
{
    Q_OBJECT

public:                                                                       
    Git();
    bool isFileInRepo();
    void startGit();
    void generatePatches();
    QString fileName;
public slots:

private:
    QString outPutString;
};

#endif // GIT_H
