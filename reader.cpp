#include "reader.h"
#include <QtGui>
Reader::Reader()
{
  setCentralWidget(editor);

}
Reader::~Reader()
{
	cout<<"I am the destructor, bye"<<endl;
}

int Reader::showColor()
{
	cout<<"hi,peter..the apple color"<<endl;
	return 0;
}
int Reader::setColor()
{

	cout<<"set color to red"<<endl;
	return 0;
}


