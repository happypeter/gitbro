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
    highlighter = new Highlighter(editor->document());
    QFont font;
    font.setFamily("Lucica");
    font.setFixedPitch(true);
    font.setPointSize(15);
    editor->setFont(font);

}

//cp form /home/peter/qtsdk-2010.01/qt/examples/richtext/syntaxhighlighter
void Reader::openFile(const QString &path)
{
    QString fileName = path;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this,
						tr("Open File"), "", "Patch Files (*.diff *.patch)");

    if (!fileName.isEmpty()) 
      {
          QFile file(fileName);
	  if (file.open(QFile::ReadOnly | QFile::Text))
	      editor->setPlainText(file.readAll());
      }
}


