#include "reader.h"
#include <QtGui>
#define NDEBUG
Reader::Reader()
{
    setupEditor();
    setCentralWidget(editor);
    openFile();
}
Reader::~Reader()
{
    cout<<"~Reader(): bye"<<endl;
}
void Reader::setupEditor()
{
#ifndef NDEBUG
    cout<<__FILE__<<":"<<__LINE__<<" setup editor"<<endl;
#endif
    editor = new QTextEdit;
    highlighter = new Highlighter(editor->document());
    QFont font;
    font.setFamily("Lucica");
    font.setFixedPitch(true);
    font.setPointSize(13);
    editor->setFont(font);
    editor->setReadOnly(TRUE);
}

//cp form /home/peter/qtsdk-2010.01/qt/examples/richtext/syntaxhighlighter
void Reader::openFile()
{
    fileName = QFileDialog::getOpenFileName(this,
						tr("Open File"), "", "All Files(*)");
}


