#include "dialog.h"
#include <iostream>

using namespace std;

DialogForm::DialogForm()
{
    ui.setupUi(this);
    QObject::connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(say_hello()));
}

void DialogForm::say_hello()
{

    cout<<"hello"<<endl;

}

