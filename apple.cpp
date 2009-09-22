#include "apple.h"

apple::apple()
{
setColor();
}
apple::~apple()
{
cout<<"I am the destructor"<<endl;
}

int apple::showColor()
{
cout<<"the apple color is:"<<color<<endl;
return 0;
}
int apple::setColor()
{
color = "red";
cout<<"set color to red"<<endl;
return 0;
}


