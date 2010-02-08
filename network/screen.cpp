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
}

void Screen::paintEvent( QPaintEvent * /*event*/ )
{
    QPainter painter(this);
    drawCordinate(painter);
}


void Screen::resizeEvent( QResizeEvent * /*event*/ )
{

        QRect rectNew(100,100,100,50);
    painter.drawText(rectNew, Qt::AlignCenter, tr("xxx"));
    painter.fillRect ( rectNew, Qt::gray);
cout<<"resize............."<<endl;

}


void Screen::drawCordinate(QPainter &painter)
{
        painter.setPen(QPen(Qt::blue,1,Qt::SolidLine) );
        painter.drawLine( 10,10,100,100);
	QFont sansFont("Helvetica [Cronyx]", 12);
        painter.setFont(sansFont);
        QRect rect(10,10,100,50);
        painter.drawText(rect, Qt::AlignCenter, tr("peter.cpp"));
        painter.fillRect ( rect, QColor(255, 0, 0, 127));

}





