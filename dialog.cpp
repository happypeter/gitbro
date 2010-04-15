#include "dialog.h"
#include <iostream>

using namespace std;

DialogForm::DialogForm()
{
    ui.setupUi(this);
}

void DialogForm::say_hello()
{

    cout<<"hello"<<endl;

}

