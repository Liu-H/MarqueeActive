#pragma once

#include <QWidget>
#include <QStaticText>
#include <QTimer>

class ScrollText : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QString text READ text WRITE setText)
	Q_PROPERTY(QString separator READ separator WRITE setSeparator)
	Q_PROPERTY(QFont tfont READ tfont WRITE setTFont)
	Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
	Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor)

public:
	ScrollText(QWidget *parent=0);
	~ScrollText();

public slots:
	QString text() const;
	void setText(QString text);

	QString separator() const;
	void setSeparator(QString separator);

	QFont font();
	QColor backgroundColor();
	QColor foregroundColor();

	void setFont(QFont font);
	void setBackgroundColor(QColor color);
	void setForegroundColor(QColor color);

protected:
	virtual void paintEvent(QPaintEvent *);
	virtual void resizeEvent(QResizeEvent *);

private:
	void updateText();
	QString _text;
	QString _separator;
	QStaticText staticText;
	int singleTextWidth;
	QSize wholeTextSize;
	int leftMargin;
	bool scrollEnabled;
	int scrollPos;
	QImage alphaChannel;
	QImage buffer;
	QTimer timer;
	QString _priText;
	QFont _font;
	QColor _backgroundColor;
	QColor _foregroundColor;

private slots:
	virtual void timer_timeout();
};
