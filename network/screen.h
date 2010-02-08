#ifndef SCREEN_CPP
#define SCREEN_CPP

#include <QWidget>
#include <QFrame>
#include <QPixmap> 
#include <QPainter>
#include <QRect>
#include <QString>

class Screen : public QFrame
{
    Q_OBJECT
    
public:
        Screen( QWidget *parent = 0 );
protected:
        void drawCordinate(QPainter &painter);
        void paintEvent( QPaintEvent * );
        void resizeEvent( QResizeEvent * );
        void mousePressEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);
	void mouseMoveEvent ( QMouseEvent * event );


private:  
        QPainter painter;
};


#endif // SCREEN_HPP
