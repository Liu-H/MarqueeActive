#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAxtiveTest.h"

class QtAxtiveTest : public QMainWindow
{
	Q_OBJECT

public:
	QtAxtiveTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtAxtiveTestClass ui;
};
