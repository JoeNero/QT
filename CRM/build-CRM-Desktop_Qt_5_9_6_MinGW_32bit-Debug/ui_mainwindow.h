/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *btnSearch;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QTableView *tableView;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1250, 780);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(__qtreewidgetitem4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem5);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMaximumSize(QSize(160, 16777215));

        horizontalLayout->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 4, 0, 4);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(200, 25));
        comboBox->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 25));
        lineEdit->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(lineEdit);

        btnSearch = new QPushButton(widget);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(btnSearch);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnAdd = new QPushButton(widget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setMinimumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(btnAdd);

        btnDelete = new QPushButton(widget);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setMinimumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(btnDelete);


        verticalLayout->addWidget(widget);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->horizontalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        comboBox->raise();
        label_4->raise();
        lineEdit->raise();
        btnSearch->raise();
        treeWidget->raise();
        label_5->raise();
        comboBox->raise();
        btnSearch->raise();
        label_4->raise();
        lineEdit->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1250, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\212\261\346\265\213\345\256\242\346\210\267\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\345\214\272\345\237\237/\347\234\201\344\273\275", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "\345\205\250\351\203\250", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "\345\215\216\344\270\234", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "\345\261\261\344\270\234", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "\346\265\231\346\261\237", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "\346\261\237\350\213\217", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "\345\256\211\345\276\275", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem2->child(4);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "\344\270\212\346\265\267", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem2->child(5);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "\347\246\217\345\273\272", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "\345\215\216\345\215\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "\345\271\277\344\270\234", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "\345\271\277\350\245\277", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem9->child(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "\346\265\267\345\215\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "\345\215\216\344\270\255", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem13->child(0);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "\346\271\226\345\214\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem13->child(1);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "\346\271\226\345\215\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem13->child(2);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "\346\262\263\345\215\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem13->child(3);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "\346\261\237\350\245\277", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "\345\215\216\345\214\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem18->child(0);
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "\345\214\227\344\272\254", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem20 = ___qtreewidgetitem18->child(1);
        ___qtreewidgetitem20->setText(0, QApplication::translate("MainWindow", "\345\244\251\346\264\245", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem21 = ___qtreewidgetitem18->child(2);
        ___qtreewidgetitem21->setText(0, QApplication::translate("MainWindow", "\346\262\263\345\214\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem22 = ___qtreewidgetitem18->child(3);
        ___qtreewidgetitem22->setText(0, QApplication::translate("MainWindow", "\345\261\261\350\245\277", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem23 = ___qtreewidgetitem18->child(4);
        ___qtreewidgetitem23->setText(0, QApplication::translate("MainWindow", "\345\206\205\350\222\231", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem24 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem24->setText(0, QApplication::translate("MainWindow", "\345\205\266\344\273\226", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem25 = ___qtreewidgetitem24->child(0);
        ___qtreewidgetitem25->setText(0, QApplication::translate("MainWindow", "\345\256\201\345\244\217", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem26 = ___qtreewidgetitem24->child(1);
        ___qtreewidgetitem26->setText(0, QApplication::translate("MainWindow", "\346\226\260\347\226\206", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem27 = ___qtreewidgetitem24->child(2);
        ___qtreewidgetitem27->setText(0, QApplication::translate("MainWindow", "\351\235\222\346\265\267", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem28 = ___qtreewidgetitem24->child(3);
        ___qtreewidgetitem28->setText(0, QApplication::translate("MainWindow", "\351\231\225\350\245\277", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem29 = ___qtreewidgetitem24->child(4);
        ___qtreewidgetitem29->setText(0, QApplication::translate("MainWindow", "\347\224\230\350\202\203", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem30 = ___qtreewidgetitem24->child(5);
        ___qtreewidgetitem30->setText(0, QApplication::translate("MainWindow", "\345\233\233\345\267\235", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem31 = ___qtreewidgetitem24->child(6);
        ___qtreewidgetitem31->setText(0, QApplication::translate("MainWindow", "\344\272\221\345\215\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem32 = ___qtreewidgetitem24->child(7);
        ___qtreewidgetitem32->setText(0, QApplication::translate("MainWindow", "\350\264\265\345\267\236", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem33 = ___qtreewidgetitem24->child(8);
        ___qtreewidgetitem33->setText(0, QApplication::translate("MainWindow", "\350\245\277\350\227\217", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem34 = ___qtreewidgetitem24->child(9);
        ___qtreewidgetitem34->setText(0, QApplication::translate("MainWindow", "\351\207\215\345\272\206", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem35 = ___qtreewidgetitem24->child(10);
        ___qtreewidgetitem35->setText(0, QApplication::translate("MainWindow", "\350\276\275\345\256\201", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem36 = ___qtreewidgetitem24->child(11);
        ___qtreewidgetitem36->setText(0, QApplication::translate("MainWindow", "\345\220\211\346\236\227", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem37 = ___qtreewidgetitem24->child(12);
        ___qtreewidgetitem37->setText(0, QApplication::translate("MainWindow", "\351\273\221\351\276\231\346\261\237", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label_5->setText(QApplication::translate("MainWindow", "\347\255\233\351\200\211\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\211\200\346\234\211\347\261\273\345\236\213", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\274\201\344\270\232", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\253\230\346\240\241", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\240\224\347\251\266\346\211\200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\344\273\243\347\220\206", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\345\244\226", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\346\224\277\345\272\234\346\234\272\346\236\204", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\351\203\250\351\230\237", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\347\254\254\344\270\211\346\226\271", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("MainWindow", "\345\205\263\351\224\256\345\255\227\357\274\232", Q_NULLPTR));
        btnSearch->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242", Q_NULLPTR));
        btnAdd->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240", Q_NULLPTR));
        btnDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
