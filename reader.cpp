#include "reader.h"
#include <QtGui>
reader::reader()
{
	setColor();
}
reader::~reader()
{
	cout<<"I am the destructor, bye"<<endl;
}

int reader::showColor()
{
	cout<<"the apple color is:"<<color<<endl;
	return 0;
}
int reader::setColor()
{
    if (!newImage.load(":img/peter.png"))
    {
           cout<<"img not found"<<endl;
            return 0;
    }
	color = "red";
	cout<<"set color to red"<<endl;
	return 0;
}


