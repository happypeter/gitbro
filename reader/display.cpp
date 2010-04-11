#include <QMessageBox>
#include <QLayout>
#include <QDebug>
#include <QVariant>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <iostream>
#include <QDir>
#include <QProcess>
#include "display.h"

using namespace std;

DisplayWidget::DisplayWidget() :  QWidget()
{
    QGridLayout *layout = new QGridLayout;
    lineEdit = new QLineEdit;
    lineEdit->setReadOnly( TRUE );
    layout->addWidget( lineEdit, 0, 0 );
    reader = new Reader;
    if(!isFileInRepo(reader->fileName))
    {
         QMessageBox::warning(this,"git","not in a git repo");
    }
    startGit(reader->fileName);
    layout->addWidget( reader, 1, 0, 1, 3 );
    newerButton = new QPushButton;
    newerButton->setText(tr("Version"));
    newerButton->setFlat(TRUE);
    spinBox = new QSpinBox;
    spinBox->setPrefix("v");
    layout->addWidget( newerButton, 0, 1 );
    layout->addWidget( spinBox , 0, 2 );
    setLayout(layout);
}
void DisplayWidget::paintEvent ( QPaintEvent * event )
{
//cout<<"paintEvent.."<<endl;//there are repaint() all the time, why? FIXME
//repaint() can be called by many reason, I think this is natrual
}
void DisplayWidget::showFile(int i)
{
    QString n = QVariant(i).toString();
    QString fileName = filePath + "v";
    fileName.append(n);
    lineEdit->setText(fileName);
}

void DisplayWidget::showInitFile()
{
    QDir dir(filePath);
    QStringList fileList;
    fileList = dir.entryList();
    int totalVersion = fileList.size()-2;
    QString n = QVariant(totalVersion).toString();
    QString fileName = filePath + "v";
    fileName.append(n);
    lineEdit->setText(fileName);
    spinBox->setValue(totalVersion);
    spinBox->setRange(0,totalVersion);
    connect( spinBox, SIGNAL( valueChanged(int) ),SLOT( showFile(int) ));
}
bool DisplayWidget::isFileInRepo(QString fileName)
{
    QFileInfo fileInfo(fileName);
    QProcess cmd;
    cmd.setWorkingDirectory(fileInfo.absolutePath());
    //'git rev-parse --is-inside-work-tree', inspired by qgit/src/git_stratup.cpp
    cmd.start("git", QStringList()<<"rev-parse"<<"--is-inside-work-tree");
    if (!cmd.waitForFinished())
    {
        qDebug() << " failed:" << cmd.errorString();
    }
    QByteArray ba;
    ba = cmd.readAllStandardOutput();
    ba = ba.trimmed();   //remove the trailing '\n'
    QString s(ba);       //easy to convert QByteArray->QString
    if(s == "true")
        return true;
    else
        return false;

}
void DisplayWidget::startGit(QString fileName)
{
    QFileInfo fileInfo(fileName);
    QProcess cmd;
    cmd.setWorkingDirectory(fileInfo.absolutePath()); 
    cmd.start("git", QStringList()<<"log"<<"-p"<<"--follow"<<fileName);
    if (!cmd.waitForFinished())
    {
        qDebug() << " failed:" << cmd.errorString();
    }
    else
    {
        qDebug() << " output:" << cmd.readAll();
        //processOutput();
        //the output here are simply all the patches of the specified file
        //Rather then store those info onto harddisks wasting time read and write files
        //things will go much faster if we just store all the data into a container
        //like QStringList or QVector, and porvide each patch on demand
    }
}
