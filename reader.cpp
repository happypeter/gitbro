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

void Reader::setupEditor()
{
    cout<<"setup editor"<<endl;
    editor = new QTextEdit;
}

//cp form /home/peter/qtsdk-2010.01/qt/examples/richtext/syntaxhighlighter
void Reader::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this,
						tr("Open File"), "", "C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) 
      {
          QFile file(fileName);
	  if (file.open(QFile::ReadOnly | QFile::Text))
	      editor->setPlainText(file.readAll());
      }
}


