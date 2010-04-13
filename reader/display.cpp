#include <QMessageBox>
#include <QLayout>
#include <QDebug>
#include <QVariant>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <iostream>
#include <QDir>
#include "display.h"

using namespace std;

DisplayWidget::DisplayWidget() 
{
    QGridLayout *layout = new QGridLayout;
    lineEdit = new QLineEdit;
    lineEdit->setReadOnly( TRUE );
    layout->addWidget( lineEdit, 0, 0 );
    reader = new Reader;
    if(!git->isFileInRepo(reader->fileName))
    {
        QMessageBox::warning(this,"git","not in a git repo");
    }
    git->startGit(reader->fileName);
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
    reader->openFile(fileName);
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
    cout<<"fileName---"<<qPrintable(fileName)<<endl;
    lineEdit->setText(fileName);
    spinBox->setValue(totalVersion);
    spinBox->setRange(0,totalVersion);
    connect( spinBox, SIGNAL( valueChanged(int) ),SLOT( showFile(int) ));
}

