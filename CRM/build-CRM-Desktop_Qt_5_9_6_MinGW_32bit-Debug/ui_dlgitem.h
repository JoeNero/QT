/********************************************************************************
** Form generated from reading UI file 'dlgitem.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGITEM_H
#define UI_DLGITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgItem
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *edit1;
    QLabel *label_7;
    QComboBox *combo1;
    QLabel *label;
    QComboBox *combo2;
    QLabel *label_2;
    QComboBox *combo3;
    QLabel *label_3;
    QLineEdit *edit2;
    QLabel *label_4;
    QLineEdit *edit3;
    QLabel *label_5;
    QLineEdit *edit4;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QTextEdit *textEdit;
    QLabel *label_10;
    QTextEdit *textEdit2;
    QLabel *label_11;
    QTextEdit *textEdit3;
    QLabel *label_9;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTip;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdd;
    QPushButton *btnCancel;

    void setupUi(QDialog *DlgItem)
    {
        if (DlgItem->objectName().isEmpty())
            DlgItem->setObjectName(QStringLiteral("DlgItem"));
        DlgItem->resize(1000, 700);
        verticalLayout = new QVBoxLayout(DlgItem);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(DlgItem);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        edit1 = new QLineEdit(DlgItem);
        edit1->setObjectName(QStringLiteral("edit1"));
        edit1->setMinimumSize(QSize(0, 25));
        edit1->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(edit1, 0, 1, 1, 1);

        label_7 = new QLabel(DlgItem);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        combo1 = new QComboBox(DlgItem);
        combo1->setObjectName(QStringLiteral("combo1"));
        combo1->setMinimumSize(QSize(0, 25));
        combo1->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(combo1, 1, 1, 1, 1);

        label = new QLabel(DlgItem);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        combo2 = new QComboBox(DlgItem);
        combo2->setObjectName(QStringLiteral("combo2"));
        combo2->setMinimumSize(QSize(0, 25));
        combo2->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(combo2, 2, 1, 1, 1);

        label_2 = new QLabel(DlgItem);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        combo3 = new QComboBox(DlgItem);
        combo3->setObjectName(QStringLiteral("combo3"));
        combo3->setMinimumSize(QSize(0, 25));
        combo3->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(combo3, 3, 1, 1, 1);

        label_3 = new QLabel(DlgItem);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        edit2 = new QLineEdit(DlgItem);
        edit2->setObjectName(QStringLiteral("edit2"));
        edit2->setMinimumSize(QSize(0, 25));
        edit2->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(edit2, 4, 1, 1, 1);

        label_4 = new QLabel(DlgItem);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 5, 0, 1, 1);

        edit3 = new QLineEdit(DlgItem);
        edit3->setObjectName(QStringLiteral("edit3"));
        edit3->setMinimumSize(QSize(0, 25));
        edit3->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(edit3, 5, 1, 1, 1);

        label_5 = new QLabel(DlgItem);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 6, 0, 1, 1);

        edit4 = new QLineEdit(DlgItem);
        edit4->setObjectName(QStringLiteral("edit4"));
        edit4->setMinimumSize(QSize(0, 25));
        edit4->setMaximumSize(QSize(400, 16777215));

        gridLayout_2->addWidget(edit4, 6, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(DlgItem);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        textEdit = new QTextEdit(DlgItem);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 1, 1, 1);

        label_10 = new QLabel(DlgItem);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        textEdit2 = new QTextEdit(DlgItem);
        textEdit2->setObjectName(QStringLiteral("textEdit2"));

        gridLayout->addWidget(textEdit2, 1, 1, 1, 1);

        label_11 = new QLabel(DlgItem);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        textEdit3 = new QTextEdit(DlgItem);
        textEdit3->setObjectName(QStringLiteral("textEdit3"));

        gridLayout->addWidget(textEdit3, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        label_9 = new QLabel(DlgItem);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout->addWidget(label_9);

        tableWidget = new QTableWidget(DlgItem);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem25);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(0, 350));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelTip = new QLabel(DlgItem);
        labelTip->setObjectName(QStringLiteral("labelTip"));
        labelTip->setMinimumSize(QSize(400, 0));

        horizontalLayout->addWidget(labelTip);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdd = new QPushButton(DlgItem);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(btnAdd);

        btnCancel = new QPushButton(DlgItem);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DlgItem);

        QMetaObject::connectSlotsByName(DlgItem);
    } // setupUi

    void retranslateUi(QDialog *DlgItem)
    {
        DlgItem->setWindowTitle(QApplication::translate("DlgItem", "\347\274\226\350\276\221\345\256\242\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("DlgItem", "\345\215\225\344\275\215\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("DlgItem", "\345\215\225\344\275\215\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        combo1->clear();
        combo1->insertItems(0, QStringList()
         << QApplication::translate("DlgItem", "\344\274\201\344\270\232", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\351\253\230\346\240\241", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\347\240\224\347\251\266\346\211\200", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\344\273\243\347\220\206", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\244\226", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\224\277\345\272\234\346\234\272\346\236\204", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\351\203\250\351\230\237", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\347\254\254\344\270\211\346\226\271", Q_NULLPTR)
        );
        label->setText(QApplication::translate("DlgItem", "\345\214\272\345\237\237\357\274\232", Q_NULLPTR));
        combo2->clear();
        combo2->insertItems(0, QStringList()
         << QApplication::translate("DlgItem", "\345\215\216\344\270\234", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\215\216\345\215\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\215\216\344\270\255", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\215\216\345\214\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\205\266\344\273\226", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\244\226", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("DlgItem", "\347\234\201\344\273\275\357\274\232", Q_NULLPTR));
        combo3->clear();
        combo3->insertItems(0, QStringList()
         << QApplication::translate("DlgItem", "\345\261\261\344\270\234", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\265\231\346\261\237", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\261\237\350\213\217", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\256\211\345\276\275", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\344\270\212\346\265\267", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\347\246\217\345\273\272", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\271\226\345\214\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\271\226\345\215\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\262\263\345\215\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\261\237\350\245\277", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\214\227\344\272\254", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\244\251\346\264\245", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\262\263\345\214\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\261\261\350\245\277", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\206\205\350\222\231", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\271\277\344\270\234", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\271\277\350\245\277", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\265\267\345\215\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\256\201\345\244\217", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\346\226\260\347\226\206", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\351\235\222\346\265\267", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\351\231\225\350\245\277", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\347\224\230\350\202\203", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\233\233\345\267\235", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\344\272\221\345\215\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\350\264\265\345\267\236", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\350\245\277\350\227\217", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\351\207\215\345\272\206", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\350\276\275\345\256\201", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\345\220\211\346\236\227", Q_NULLPTR)
         << QApplication::translate("DlgItem", "\351\273\221\351\276\231\346\261\237", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("DlgItem", "\345\237\216\345\270\202\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("DlgItem", "\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("DlgItem", "\347\275\221\345\235\200\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("DlgItem", "\351\207\207\350\264\255\346\203\205\345\206\265\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("DlgItem", "\347\240\224\347\251\266\346\226\271\345\220\221\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("DlgItem", "\345\244\207\346\263\250\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("DlgItem", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DlgItem", "\350\201\224\347\263\273\344\272\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DlgItem", "\350\201\214\344\275\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DlgItem", "\347\224\265\350\257\235", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DlgItem", "\344\274\240\347\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DlgItem", "\351\202\256\347\256\261", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("DlgItem", "\345\217\257\350\203\275\350\277\207\346\227\266", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("DlgItem", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("DlgItem", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("DlgItem", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("DlgItem", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("DlgItem", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("DlgItem", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("DlgItem", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("DlgItem", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem14->setText(QApplication::translate("DlgItem", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem15->setText(QApplication::translate("DlgItem", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem16->setText(QApplication::translate("DlgItem", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem17->setText(QApplication::translate("DlgItem", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem18->setText(QApplication::translate("DlgItem", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem19->setText(QApplication::translate("DlgItem", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem20->setText(QApplication::translate("DlgItem", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem21->setText(QApplication::translate("DlgItem", "16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem22->setText(QApplication::translate("DlgItem", "17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem23->setText(QApplication::translate("DlgItem", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem24->setText(QApplication::translate("DlgItem", "19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem25->setText(QApplication::translate("DlgItem", "20", Q_NULLPTR));
        labelTip->setText(QString());
        btnAdd->setText(QApplication::translate("DlgItem", "\345\242\236\345\212\240", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("DlgItem", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DlgItem: public Ui_DlgItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGITEM_H
