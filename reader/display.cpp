#include <QLayout>
#include <QVariant>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <iostream>
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
QString path = "/home/peter/file/"; 
//when I think about how to pass the path to this function, firstly I think we need to change the 
//prototype into showNewer(Qstring &path)
//but if I just want to use reader as a popup window, maybe we can just use a global variable for the path
path.append(filename);//FIXME:it the file is not there, there is complete no warning
reader->openFile(path); 
}
