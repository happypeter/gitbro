#include <QApplication>
#include <iostream>
#include "reader.h"
#include "ui_dialog.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *widget = new QWidget;
	Ui_Dialog ui;
	ui.setupUi(widget);
	widget->show();
	reader re;
	re.showColor();
	return app.exec();
}

