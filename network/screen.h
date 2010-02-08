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
	
private:  
    QPixmap newPixmap,savePixmap,midPixmap;
    QPainter painter;
};


#endif // SCREEN_HPP
