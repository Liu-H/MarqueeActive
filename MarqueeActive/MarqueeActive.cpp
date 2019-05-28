#include "MarqueeActive.h"

#include <ActiveQt/QAxFactory>
#include "ScrollText.h"
MarqueeActive::MarqueeActive(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(this, &MarqueeActive::textChanged, ui.scrollText, &ScrollText::setText);
	connect(this, &MarqueeActive::backgroundColorChanged, ui.scrollText, &ScrollText::setBackgroundColor);
	connect(this, &MarqueeActive::foregroundColorChanged, ui.scrollText, &ScrollText::setForegroundColor);
	connect(this, &MarqueeActive::moveSpeedChanged, ui.scrollText, &ScrollText::setMoveSpeed);
	connect(this, &MarqueeActive::fontSizezChanged, ui.scrollText, &ScrollText::setFontSize);
	setMoveSpeed("1");
	setFontSizez("30");
	setBackgroundColor(qRgb(220, 220, 220));
	setForegroundColor(qRgb(0, 0, 0));
}

QString MarqueeActive::text() const
{
	return _text;
}

void MarqueeActive::setText(QString text)
{
	if(_text!= text)
	{
		_text = text;
		emit textChanged(_text);
	}
}

QColor MarqueeActive::backgroundColor()
{
	return _backgroundColor;
}

QColor MarqueeActive::foregroundColor()
{
	return _foregroundColor;
}

QString MarqueeActive::moveSpeed() const
{
	return _moveSpeed;
}

QString MarqueeActive::fontSizez() const
{
	return _fontSizez;
}



void MarqueeActive::setBackgroundColor(QColor color)
{
	_backgroundColor = color;
	emit backgroundColorChanged(_backgroundColor);
}

void MarqueeActive::setForegroundColor(QColor color)
{
	_foregroundColor = color;
	emit foregroundColorChanged(_foregroundColor);
}

void MarqueeActive::setMoveSpeed(QString text)
{
	_moveSpeed = text;
	emit moveSpeedChanged(_moveSpeed);
}

void MarqueeActive::setFontSizez(QString text)
{
	_fontSizez = text;
	emit fontSizezChanged(_fontSizez);
}






QAXFACTORY_DEFAULT(MarqueeActive,
	"{e198aa3f-58cd-4ef4-b4c9-1472542c6fd9}",
	"{34731dbc-a6c2-4a55-8f46-5ee51a037559}",
	"{16dfa18c-ad30-4831-8328-d2fc0ecbdfc5}",
	"{4f9b736f-e166-4aca-8416-1336c4f6fc61}",
	"{f4377db9-4a48-4d98-a267-f2b101d5f384}"
)
