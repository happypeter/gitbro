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
    cout<<qPrintable(reader->fileName)<<"+++"<<endl;
    //now we have the fileName, next step we need to pass it to git cmd 
    //to get all its patches
    QFileInfo fileInfo(reader->fileName);
    cout<<qPrintable(fileInfo.absolutePath())<<"   abs--path"<<endl;
    //then I can pass the abs-path to QProcess::setWorkingDirectory ( const QString & dir )
    //inorder to excuted git cmd
    //here we use QProcess rather than system(command), since it is more interactive
    QProcess cmd;
    cmd.setWorkingDirectory(fileInfo.absolutePath()); 
    cmd.start("git", QStringList()<<"log");
    if (!cmd.waitForFinished())
    {
        qDebug() << " failed:" << cmd.errorString();
    }
    else
    {
        qDebug() << " output:" << cmd.readAll();
        cout<<cmd.exitCode()<<"--exitCode "<<endl;//exitCode: 0 when in repo; 1 when not in a repo
    }
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
//    reader->openFile(fileName);
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
//    reader->openFile(fileName);
    spinBox->setValue(totalVersion);
    spinBox->setRange(0,totalVersion);
    connect( spinBox, SIGNAL( valueChanged(int) ),SLOT( showFile(int) ));//strange the "int" here
}


