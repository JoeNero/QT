#ifndef MYITEM_H
#define MYITEM_H

#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QSize>
#include <QListWidgetItem>

class MyPageItem:public QListWidgetItem//自定义控件
{

public:
    MyPageItem(QListWidget *);

    QPushButton *frist_page, *second_page, *three_page, *four_page, *five_page;
    QPushButton *next_page, *previous_page;
    QHBoxLayout *page_layout;

    QListWidgetItem *page_item;
    QWidget *page_widget;

};

class LyricItem:public QListWidgetItem//自定义控件
{

public:
    LyricItem(QListWidget *);
    QLabel *lyric_label;

    QListWidgetItem *lyric_item;
    QWidget *lyric_widget;
    QHBoxLayout *lyric_layout;
};

class MyItem : public QListWidgetItem
{

public:
    MyItem(QListWidget *);

    QListWidgetItem *music_item;
    QRadioButton *islike;
    QPushButton *video_btn, *paly_btn, *add_btn, *down_btn, *more_btn;
    QPushButton *music_author_btn, *special_btn;
    QLabel *music_name_label, *time_label;
    QWidget *music_widget;
    QHBoxLayout *music_layout;

};

#endif // MYITEM_H
