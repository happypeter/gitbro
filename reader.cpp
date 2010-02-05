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
    //highlighter is not used hereafter, strange to me.
    //how it works?
    //if setCentralWidget(highlighter)
    //then I will feel it is natrual.
    //I will try to believe by newing the highlighter,
    //its constructor (which is just a series of functions) got
    //executed, and these functions modified editor->document()in some
    //way, like tagging the text, so that the next time you want to
    //use the document, it has been tagged, and thus highlighting is
    //done, that's how I understand as a C coder, really need to learn
    //C++ more:-)
    //the below makes sense
    /* QSyntaxHighlighter::QSyntaxHighlighter ( QTextDocument * parent
       )

       Constructs a QSyntaxHighlighter and installs it on parent. The
       specified QTextDocument also becomes the owner of the QSyntaxHighlighter.*/ 
    QFont font;
    font.setFamily("Times");
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
						tr("Open File"), "", "C++ Files (*.cpp *.h)");

    if (!fileName.isEmpty()) 
      {
          QFile file(fileName);
	  if (file.open(QFile::ReadOnly | QFile::Text))
	      editor->setPlainText(file.readAll());
      }
}


