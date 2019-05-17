#include "QtAxtiveTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtAxtiveTest w;
	w.show();
	return a.exec();
}
