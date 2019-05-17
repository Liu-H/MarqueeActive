/********************************************************************************
** Form generated from reading UI file 'MarqueeActive.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARQUEEACTIVE_H
#define UI_MARQUEEACTIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <ScrollText.h>

QT_BEGIN_NAMESPACE

class Ui_MarqueeActiveClass
{
public:
    QGridLayout *gridLayout;
    ScrollText *scrollText;

    void setupUi(QWidget *MarqueeActiveClass)
    {
        if (MarqueeActiveClass->objectName().isEmpty())
            MarqueeActiveClass->setObjectName(QStringLiteral("MarqueeActiveClass"));
        MarqueeActiveClass->resize(682, 98);
        gridLayout = new QGridLayout(MarqueeActiveClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollText = new ScrollText(MarqueeActiveClass);
        scrollText->setObjectName(QStringLiteral("scrollText"));

        gridLayout->addWidget(scrollText, 0, 0, 1, 1);


        retranslateUi(MarqueeActiveClass);

        QMetaObject::connectSlotsByName(MarqueeActiveClass);
    } // setupUi

    void retranslateUi(QWidget *MarqueeActiveClass)
    {
        MarqueeActiveClass->setWindowTitle(QApplication::translate("MarqueeActiveClass", "MarqueeActive", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MarqueeActiveClass: public Ui_MarqueeActiveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARQUEEACTIVE_H
