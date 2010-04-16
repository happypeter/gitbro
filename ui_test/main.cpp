#include "dialog.h"
#include "parent.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DialogForm df;
    QMyWidget my;
    my.show();
    df.show();
    return app.exec();


}
