#include "reader.h"
#include <QtGui>
Reader::Reader()
{
  setupEditor();
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

void Reader::setupEditor()
{

	cout<<"setup editor"<<endl;
	editor = new QTextEdit;
}


