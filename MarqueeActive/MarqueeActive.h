#pragma once

#include <QtWidgets/QWidget>
#include <ActiveQt/QAxBindable>
#include <QString>
#include "ui_MarqueeActive.h"

class MarqueeActive : public QWidget, public QAxBindable
{
	Q_OBJECT
	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
	Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)
	Q_PROPERTY(QString moveSpeed READ moveSpeed WRITE setMoveSpeed NOTIFY moveSpeedChanged)
	Q_PROPERTY(QString fontSizez READ fontSizez WRITE setFontSizez NOTIFY fontSizezChanged)

public:
	MarqueeActive(QWidget *parent = Q_NULLPTR);
	QString text() const;
	QColor backgroundColor();
	QColor foregroundColor();
	QString moveSpeed() const;
	QString fontSizez() const;
public slots:
	
	void setText(QString text);
	void setBackgroundColor(QColor color);
	void setForegroundColor(QColor color);
	void setMoveSpeed(QString text);
	void setFontSizez(QString text);
signals:
	void textChanged(QString);
	void backgroundColorChanged(QColor);
	void foregroundColorChanged(QColor);
	void moveSpeedChanged(QString);
	void fontSizezChanged(QString);
private:
	Ui::MarqueeActiveClass ui;
	QString _text;
	QColor _backgroundColor;
	QColor _foregroundColor;
	QString _moveSpeed;
	QString _fontSizez;
};
