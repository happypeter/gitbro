#include <QApplication>
#include <iostream>
#include "reader.h"
#include "ui_dialog.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QDialog *widget = new QDialog;
	Ui_Dialog ui;
	ui.setupUi(widget);
	widget->show();
	reader re;
	re.showColor();
	return app.exec();
}

