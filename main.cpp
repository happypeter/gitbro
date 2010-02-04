#include <QApplication>
#include <iostream>
#include "reader.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
        Reader reader;
        reader.resize(640, 512);
        reader.show();
	return app.exec();
}

