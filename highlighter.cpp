#include <QtGui>
#include "highlighter.h"
Highlighter::Highlighter(QTextDocument *parent)
  : QSyntaxHighlighter(parent)
{
}
void Highlighter::highlightBlock(const QString &text)
{ 
  //why this function works, without being called.
  //is it in the constructor of hilighter?
  for (int i = 0; i < text.length(); ++i) {
       setFormat(i, 1, Qt::green);
  }
}
