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
    static int i = 0; //I do not really like this, is there a better way?
    cout<<"Version number now is :"<<++i<<endl;
    QString n = QVariant(i).toString();
    QString filename = "v";
    filename.append(n);
    cout<<qPrintable(filename)<<endl;
    cout<<qPrintable(filePath)<<endl;//now we have a path passed form main
    QDir dir(filePath);
    QStringList file_list;
    file_list = dir.entryList();
    cout<<file_list.size()<<endl;//the number counts . and .. in
    filePath.append(filename);
    reader->openFile(filePath);
}
