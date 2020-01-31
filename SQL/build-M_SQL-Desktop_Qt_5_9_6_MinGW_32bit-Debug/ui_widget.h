/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QLabel *label_3;
    QLineEdit *lineEditName;
    QLineEdit *lineEditNum;
    QLineEdit *lineEditScore;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *BtnInsert;
    QPushButton *BtnDelete;
    QPushButton *BtnChange;
    QPushButton *BtnRead;
    QPushButton *BtnAll;
    QTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 0, 261, 111));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 38, 15));
        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(61, 11, 181, 21));
        lineEditNum = new QLineEdit(widget);
        lineEditNum->setObjectName(QStringLiteral("lineEditNum"));
        lineEditNum->setGeometry(QRect(61, 39, 181, 21));
        lineEditScore = new QLineEdit(widget);
        lineEditScore->setObjectName(QStringLiteral("lineEditScore"));
        lineEditScore->setGeometry(QRect(61, 67, 181, 21));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 40, 38, 15));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 38, 15));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(290, 10, 131, 281));
        widget1 = new QWidget(widget_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 10, 101, 261));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        BtnInsert = new QPushButton(widget1);
        BtnInsert->setObjectName(QStringLiteral("BtnInsert"));

        verticalLayout->addWidget(BtnInsert);

        BtnDelete = new QPushButton(widget1);
        BtnDelete->setObjectName(QStringLiteral("BtnDelete"));

        verticalLayout->addWidget(BtnDelete);

        BtnChange = new QPushButton(widget1);
        BtnChange->setObjectName(QStringLiteral("BtnChange"));

        verticalLayout->addWidget(BtnChange);

        BtnRead = new QPushButton(widget1);
        BtnRead->setObjectName(QStringLiteral("BtnRead"));

        verticalLayout->addWidget(BtnRead);

        BtnAll = new QPushButton(widget1);
        BtnAll->setObjectName(QStringLiteral("BtnAll"));

        verticalLayout->addWidget(BtnAll);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 116, 261, 171));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\346\210\220\347\273\251:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\345\255\246\345\217\267:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\345\247\223\345\220\215:", Q_NULLPTR));
        BtnInsert->setText(QApplication::translate("Widget", "\346\217\222\345\205\245", Q_NULLPTR));
        BtnDelete->setText(QApplication::translate("Widget", "\345\210\240\351\231\244", Q_NULLPTR));
        BtnChange->setText(QApplication::translate("Widget", "\344\277\256\346\224\271", Q_NULLPTR));
        BtnRead->setText(QApplication::translate("Widget", "\346\237\245\350\257\242", Q_NULLPTR));
        BtnAll->setText(QApplication::translate("Widget", "\346\237\245\350\257\242\346\211\200\346\234\211\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
