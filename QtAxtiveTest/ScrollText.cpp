#include "ScrollText.h"
#include <QPainter>
ScrollText::ScrollText(QWidget *parent)
	: QWidget(parent), scrollPos(0), _imoveSpeed(1)
{
	staticText.setTextFormat(Qt::PlainText);

	QFont font;
	font.setPixelSize(30);
	font.setFamily("Microsoft YaHei");
	setFont(font);
	setBackgroundColor(qRgb(220, 220, 220));
	setForegroundColor(qRgb(0, 0, 0));
	leftMargin = height() / 3;

	setSeparator("      ");

	connect(&timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
	timer.setInterval(10);
}

ScrollText::~ScrollText()
{
}

QString ScrollText::text() const
{
	return _text;
}

void ScrollText::setText(QString text)
{
	_text = text;
	//_text1 = text;

	updateText();
	update();
}

QString ScrollText::separator() const
{
	return _separator;
}

void ScrollText::setSeparator(QString separator)
{
	_separator = separator;
	updateText();
	update();
}

QFont ScrollText::tfont()
{
	return _font;
}

QColor ScrollText::backgroundColor()
{
	return _backgroundColor;
}

QColor ScrollText::foregroundColor()
{
	return _foregroundColor;
}

void ScrollText::setTFont(QFont font)
{
	_font = font;
}

void ScrollText::setBackgroundColor(QColor color)
{
	_backgroundColor = color;
	updateText();
}

void ScrollText::setForegroundColor(QColor color)
{
	_foregroundColor = color;
	updateText();
}

int ScrollText::speed()
{
	return _speed;
}

void ScrollText::setSpeed(int sp)
{
	_speed = sp;
}


void ScrollText::updateText()
{
	timer.stop();
	_priText = text();
	QFontMetrics fm(_font);
	do
	{

		singleTextWidth = fm.width(_priText);
		scrollEnabled = (singleTextWidth > width() - leftMargin);
		if (!scrollEnabled)
		{
			_priText.append(" ");
		}
	} while (!scrollEnabled);



	if (scrollEnabled)
	{
		//scrollPos = -64;
		staticText.setText(_priText + _separator);
		timer.start();
	}
	else
		staticText.setText(_priText);

	staticText.prepare(QTransform(), font());
	wholeTextSize = QSize(fm.width(staticText.text()), fm.height());
}

void ScrollText::paintEvent(QPaintEvent*)
{
	QPainter p(this);

	if (scrollEnabled)
	{
		buffer.fill(_backgroundColor);
		QPainter pb(&buffer);
		pb.setPen(_foregroundColor);
		pb.setFont(_font);

		int x = qMin(-scrollPos, 0) + leftMargin;
		while (x < width())
		{

			pb.drawStaticText(QPointF(x, (height() - wholeTextSize.height()) / 2) + QPoint(2, 2), staticText);
			x += wholeTextSize.width();
		}

		//Apply Alpha Channel
		pb.setCompositionMode(QPainter::CompositionMode_DestinationIn);
		pb.setClipRect(width() - 15, 0, 15, height());
		pb.drawImage(0, 0, alphaChannel);
		pb.setClipRect(0, 0, 15, height());
		//initial situation: don't apply alpha channel in the left half of the image at all; apply it more and more until scrollPos gets positive
		if (scrollPos < 0)
			pb.setOpacity((qreal)(qMax(-8, scrollPos) + 8) / 8.0);
		pb.drawImage(0, 0, alphaChannel);

		//pb.end();
		p.drawImage(0, 0, buffer);
	}
	else
	{
		p.drawStaticText(QPointF(leftMargin, (height() - wholeTextSize.height()) / 2), staticText);
	}
}

void ScrollText::resizeEvent(QResizeEvent*)
{
	//When the widget is resized, we need to update the alpha channel.

	alphaChannel = QImage(size(), QImage::Format_ARGB32_Premultiplied);
	buffer = QImage(size(), QImage::Format_ARGB32_Premultiplied);

	//Create Alpha Channel:
	if (width() > 64)
	{
		//create first scanline
		QRgb* scanline1 = (QRgb*)alphaChannel.scanLine(0);
		for (int x = 1; x < 16; ++x)
			scanline1[x - 1] = scanline1[width() - x] = qRgba(_foregroundColor.red(), _foregroundColor.green(), _foregroundColor.blue(), x << 4);
		for (int x = 15; x < width() - 15; ++x)
			scanline1[x] = _foregroundColor.rgb();
		//copy scanline to the other ones
		for (int y = 1; y < height(); ++y)
			memcpy(alphaChannel.scanLine(y), (uchar*)scanline1, width() * 4);
	}
	else
		alphaChannel.fill(_foregroundColor);


	//Update scrolling state
	//bool newScrollEnabled = (singleTextWidth > width() - leftMargin);
	//if (newScrollEnabled != scrollEnabled)
	if (scrollPos > width())
	{
		scrollPos = 0;
	}
	updateText();

}

void ScrollText::timer_timeout()
{
	scrollPos = (scrollPos + _speed)
		% wholeTextSize.width();
	update();
}
