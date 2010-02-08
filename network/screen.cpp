#include <QApplication>
#include <QEvent>
#include <QSize>
#include <iostream>
#include <QFont>
#include <QPen>
#include <QStylePainter>

#include "screen.h"
using namespace std;

Screen::Screen( QWidget *parent )
    : QFrame( parent )
{
    QPainter painter(this);
    drawCordinate(painter);
}

void Screen::paintEvent( QPaintEvent * /*event*/ )
{
}

void Screen::resizeEvent( QResizeEvent * /*event*/ )
{
 
}


void Screen::drawCordinate(QPainter &painter)
{
        painter.setPen(QPen(Qt::blue,1,Qt::SolidLine) );
        painter.drawLine( 10,10,1000,1000);
}





