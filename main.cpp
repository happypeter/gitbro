#include <QApplication>
#include <iostream>
#include "apple.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	apple ap;
	ap.showColor();
	return app.exec();
}

