#include "MarqueeActive.h"

#include <ActiveQt/QAxFactory>
#include "ScrollText.h"
MarqueeActive::MarqueeActive(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(this, &MarqueeActive::textChanged, ui.scrollText, &ScrollText::setText);
	connect(this, &MarqueeActive::separatorChanged, ui.scrollText, &ScrollText::setSeparator);
	connect(this, &MarqueeActive::fontChanged, ui.scrollText, &ScrollText::setTFont);
	connect(this, &MarqueeActive::backgroundColorChanged, ui.scrollText, &ScrollText::setBackgroundColor);
	connect(this, &MarqueeActive::foregroundColorChanged, ui.scrollText, &ScrollText::setForegroundColor);
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

QString MarqueeActive::separator() const
{
	return _separator;
}

void MarqueeActive::setSeparator(QString separator)
{

	if (_separator != separator)
	{
		_separator = separator;
		emit textChanged(_separator);
	}
}

QFont MarqueeActive::font()
{
	return _font;
}

QColor MarqueeActive::backgroundColor()
{
	return _backgroundColor;
}

QColor MarqueeActive::foregroundColor()
{
	return _foregroundColor;
}

void MarqueeActive::setFont(QFont font)
{
	_font = font;
	emit fontChanged(_font);
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

QAXFACTORY_DEFAULT(MarqueeActive,
	"{e198aa3f-58cd-4ef4-b4c9-1472542c6fd9}",
	"{34731dbc-a6c2-4a55-8f46-5ee51a037559}",
	"{16dfa18c-ad30-4831-8328-d2fc0ecbdfc5}",
	"{4f9b736f-e166-4aca-8416-1336c4f6fc61}",
	"{f4377db9-4a48-4d98-a267-f2b101d5f384}"
)
