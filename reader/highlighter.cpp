#include <QtGui>
#include "highlighter.h"

Highlighter::Highlighter(QTextDocument *parent)
  : QSyntaxHighlighter(parent)
{
  HighlightingRule rule;

  addFormat.setBackground(QColor("#52ea55"));
  // http://doc.trolltech.com/4.6/qregexp.html
  rule.pattern = QRegExp("^"+QRegExp::escape("+")+"[^\n]*");
  //now it works, but the problem is:I should not
  //set the backgroud of the text, it is ugly, I should set background
  // of the whole line 

  rule.format = addFormat;
  highlightingRules.append(rule);
  minusFormat.setBackground(QColor("#ec8282"));
  rule.pattern = QRegExp("^"+QRegExp::escape("-")+"[^\n]*");
  rule.format = minusFormat;
  highlightingRules.append(rule);
}
void Highlighter::highlightBlock(const QString &text)
{ 
 
  foreach (const HighlightingRule &rule, highlightingRules) {
    QRegExp expression(rule.pattern);
    int index = expression.indexIn(text);
    while (index >= 0) {
      int length = expression.matchedLength();
      setFormat(index, length, rule.format);
      index = expression.indexIn(text, index + length);
    }
  }
}
