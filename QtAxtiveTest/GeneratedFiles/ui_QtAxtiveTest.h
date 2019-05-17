/********************************************************************************
** Form generated from reading UI file 'QtAxtiveTest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTAXTIVETEST_H
#define UI_QTAXTIVETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <ScrollText.h>

QT_BEGIN_NAMESPACE

class Ui_QtAxtiveTestClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    ScrollText *scrollText;

    void setupUi(QMainWindow *QtAxtiveTestClass)
    {
        if (QtAxtiveTestClass->objectName().isEmpty())
            QtAxtiveTestClass->setObjectName(QStringLiteral("QtAxtiveTestClass"));
        QtAxtiveTestClass->resize(346, 189);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        QtAxtiveTestClass->setFont(font);
        QtAxtiveTestClass->setAutoFillBackground(false);
        centralWidget = new QWidget(QtAxtiveTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollText = new ScrollText(centralWidget);
        scrollText->setObjectName(QStringLiteral("scrollText"));

        gridLayout->addWidget(scrollText, 0, 0, 1, 1);

        QtAxtiveTestClass->setCentralWidget(centralWidget);

        retranslateUi(QtAxtiveTestClass);

        QMetaObject::connectSlotsByName(QtAxtiveTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtAxtiveTestClass)
    {
        QtAxtiveTestClass->setWindowTitle(QApplication::translate("QtAxtiveTestClass", "QtAxtiveTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtAxtiveTestClass: public Ui_QtAxtiveTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTAXTIVETEST_H
