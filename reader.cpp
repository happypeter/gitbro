#include "reader.h"
#include <QtGui>
Reader::Reader()
{
  setupEditor();
  setCentralWidget(editor);
  QString content = "hello";
  editor->setPlainText(content);

}
Reader::~Reader()
{
	cout<<"I am the destructor, bye"<<endl;
}

void Reader::setupEditor()
{

	cout<<"setup editor"<<endl;
	editor = new QTextEdit;
}


