#pragma once

#include <QtWidgets/QWidget>
#include <ActiveQt/QAxBindable>
#include <QString>
#include "ui_MarqueeActive.h"

class MarqueeActive : public QWidget, public QAxBindable
{
	Q_OBJECT
	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
	Q_PROPERTY(QString separator READ separator WRITE setSeparator NOTIFY separatorChanged)
	Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
	Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)
public:
	MarqueeActive(QWidget *parent = Q_NULLPTR);
	QString text() const;
	QString separator() const;
	QFont font();
	QColor backgroundColor();
	QColor foregroundColor();
public slots:
	
	void setText(QString text);
	void setSeparator(QString separator);

	void setFont(QFont font);
	void setBackgroundColor(QColor color);
	void setForegroundColor(QColor color);
signals:
	void textChanged(QString);
	void separatorChanged(QString);
	void fontChanged(QFont);
	void backgroundColorChanged(QColor);
	void foregroundColorChanged(QColor);
private:
	Ui::MarqueeActiveClass ui;
	QString _text;
	QString _separator;
	QFont _font;
	QColor _backgroundColor;
	QColor _foregroundColor;
};
