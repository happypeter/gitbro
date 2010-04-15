#include "dialog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DialogForm df;
    df.show();
    return app.exec();


}
