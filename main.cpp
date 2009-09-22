#include <QApplication>
#include <iostream>
#include "reader.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	reader re;
	re.showColor();
	return app.exec();
}

