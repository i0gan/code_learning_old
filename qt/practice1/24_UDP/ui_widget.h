/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIp;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIp = new QLineEdit(Widget);
        lineEditIp->setObjectName(QStringLiteral("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 0, 1, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(Widget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        pushButtonSend = new QPushButton(Widget);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(246, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        pushButtonClose = new QPushButton(Widget);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 3, 2, 1, 1);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "host ip", Q_NULLPTR));
        lineEditIp->setText(QApplication::translate("Widget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "host port", Q_NULLPTR));
        lineEditPort->setText(QApplication::translate("Widget", "7891", Q_NULLPTR));
        pushButtonSend->setText(QApplication::translate("Widget", "send", Q_NULLPTR));
        pushButtonClose->setText(QApplication::translate("Widget", "close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
