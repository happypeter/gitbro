#include <QMainWindow>
#include <iostream>

using namespace std;

class QMyWidget: public QMainWindow
{
    Q_OBJECT

public:
    QMyWidget();
    ~QMyWidget(){cout<<"QMainWindow~() is called"<<endl;};

};
