#include "QtAxtiveTest.h"

QtAxtiveTest::QtAxtiveTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.scrollText->setText("Liu------------------------------------------------------");
	QFont font;
	font.setPixelSize(100);
	font.setFamily("Microsoft YaHei");
	ui.scrollText->setTFont(font);
	ui.scrollText->setBackgroundColor(qRgb(100, 149, 237));
	ui.scrollText->setForegroundColor(qRgb(255, 255, 255));
}
