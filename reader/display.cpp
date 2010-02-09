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
    newerButton->setText(tr("Newer"));
    olderButton = new QPushButton;
    olderButton->setText( tr( "Older" ) );
    layout->addWidget( newerButton, 0, 1 );
    layout->addWidget( olderButton , 0, 2 );
    setLayout(layout);
    connect( newerButton, SIGNAL( clicked () ), SLOT( showNewer() ) );
}


void DisplayWidget::showNewer()
{
    QDir dir(filePath);
    QStringList fileList;
    fileList = dir.entryList();
    static int i = 0; //I do not really like this, is there a better way?
    cout<<"current Version number now is :"<<++i<<endl;
    QString n = QVariant(i).toString();
    if(i <= fileList.size()-2)
    {
        QString fileName = filePath + "v";
        fileName.append(n);
        cout<<qPrintable(fileName)<<endl;
        reader->openFile(fileName);
    }
    else
    {//disable newerButton
    }
}
