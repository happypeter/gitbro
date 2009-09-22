#include "reader.h"

reader::reader()
{
setColor();
}
reader::~reader()
{
cout<<"I am the destructor"<<endl;
}

int reader::showColor()
{
cout<<"the apple color is:"<<color<<endl;
return 0;
}
int reader::setColor()
{
color = "red";
cout<<"set color to red"<<endl;
return 0;
}


