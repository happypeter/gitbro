#include <QtGui>
#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
  : QSyntaxHighlighter(parent)
{

}
void Highlighter::highlightBlock(const QString &text)
{
  for (int i = 0; i < text.length(); ++i) {
    if (text.at(i).isLetterOrNumber())
      setFormat(i, 1, Qt::green);
  }
}
