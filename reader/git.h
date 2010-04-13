#ifndef GIT_H
#define GIT_H

#include <QWidget>

class Git : public QWidget
{
    Q_OBJECT

public:                                                                       
    Git();
    bool isFileInRepo();
    void startGit(QString);
    QString fileName;
public slots:

private:
};

#endif // GIT_H
