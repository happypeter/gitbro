#include <QApplication>
#include <QEvent>
#include <QSize>
#include <QMouseEvent>
#include <iostream>
#include <QFont>
#include <QPen>
#include <QStylePainter>

#include "screen.h"
using namespace std;

Screen::Screen( QWidget *parent )
    : QFrame( parent )//as a paint device, QFrame is somewhat limited, maybe QGraphicsView is better?
{
}

void Screen::paintEvent( QPaintEvent * /*event*/ )
{
    QPainter painter(this);
    drawCordinate(painter);
}


void Screen::resizeEvent( QResizeEvent * /*event*/ )
{

    cout<<"resize............."<<endl;

}
void Screen::mousePressEvent(QMouseEvent *event)
 {
     if (event->button() == Qt::LeftButton) {
        cout<<"left button..."<<endl;
         // handle left mouse button here
     } else {
        ; //do nothing
     }
 }

void Screen::drawCordinate(QPainter &painter)
{	
	static int i = 1;
	i++;
        painter.setPen(QPen(Qt::blue,1,Qt::SolidLine) );
        painter.drawLine( 10,10,20*i,20*i);
	QFont sansFont("Helvetica [Cronyx]", 12);
        painter.setFont(sansFont);
        QRect rect(10,10,100,50);
        painter.drawText(rect, Qt::AlignCenter, tr("peter.cpp"));
        painter.fillRect ( rect, QColor(255, 0, 0, 127));

}


void Screen::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
	setVisible(TRUE);
	break;
    case Qt::Key_Down:
	setHidden(TRUE);
        break;
    }
}
void Screen::mouseMoveEvent ( QMouseEvent * event ) 
{	
 //this works, but very wiredly, you need to press the button and do a move
// and the out put will then keep the same, no matter where the cursor is
// the returned position is actually based on the whole monitor screen, not this widget
	QPoint p = pos ();
	cout<<p.x()<<"--"<<p.y()<<endl;
}
