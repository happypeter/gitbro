#include <QLayout>
#include <QVariant>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <iostream>
#include <QDir>
#include "display.h"

using namespace std;

DisplayWidget::DisplayWidget() :  QWidget()
{
    QGridLayout *layout = new QGridLayout;
    lineEdit = new QLineEdit;
    lineEdit->setReadOnly( TRUE );
    layout->addWidget( lineEdit, 0, 0 );
    reader = new Reader;
    layout->addWidget( reader, 1, 0, 1, 3 );
    newerButton = new QPushButton;
    newerButton->setText(tr("Version"));
    newerButton->setFlat(TRUE);
    spinBox = new QSpinBox;
    layout->addWidget( newerButton, 0, 1 );
    layout->addWidget( spinBox , 0, 2 );
    setLayout(layout);
    spinBox->setPrefix("v");
    connect( spinBox, SIGNAL( valueChanged(int) ),SLOT( showFile(int) ));//strange the "int" here
}
void DisplayWidget::paintEvent ( QPaintEvent * event )
{
//cout<<"paintEvent.."<<endl;//there are repaint() all the time, why? FIXME
//repaint() can be called by many reason, I think this is natrual
}
void DisplayWidget::showFile(int i)
{
    QDir dir(filePath);
    QStringList fileList;
    fileList = dir.entryList();
    spinBox->setPrefix("v");
    cout<<"------"<<fileList.size()<<endl;
    spinBox->setRange(0,fileList.size()-2);
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
    cout<<"showInitFile"<<fileList.size()<<endl;
    QString n = QVariant(fileList.size()-2).toString();
    QString fileName = filePath + "v";
    fileName.append(n);
    lineEdit->setText(fileName);
    reader->openFile(fileName);
}


