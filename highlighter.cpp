#include <QtGui>
#include "highlighter.h"
Highlighter::Highlighter(QTextDocument *parent)
  : QSyntaxHighlighter(parent)
{
  HighlightingRule rule;

  singleLineCommentFormat.setBackground(Qt::green);
  rule.pattern = QRegExp("//[^\n]*");
  rule.format = singleLineCommentFormat;
  highlightingRules.append(rule);

  commentStartExpression = QRegExp("/\\*");
  commentEndExpression = QRegExp("\\*/");
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
  //! [7] //! [8]
  setCurrentBlockState(0);
  //! [8]

  //! [9]
  int startIndex = 0;
  if (previousBlockState() != 1)
    startIndex = commentStartExpression.indexIn(text);

  //! [9] //! [10]
  while (startIndex >= 0) {
    //! [10] //! [11]
    int endIndex = commentEndExpression.indexIn(text, startIndex);
    int commentLength;
    if (endIndex == -1) {
      setCurrentBlockState(1);
      commentLength = text.length() - startIndex;
    } else {
            commentLength = endIndex - startIndex
	      + commentEndExpression.matchedLength();
    }
    startIndex = commentStartExpression.indexIn(text, startIndex +
  commentLength);
  }
}
