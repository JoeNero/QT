#include "myitem.h"

MyItem::MyItem(QListWidget *father)
{
    music_item = new QListWidgetItem(father,0);

    music_widget = new QWidget(father);
    islike = new QRadioButton(music_widget);           //喜欢
    islike->setText("喜欢");

    music_name_label = new QLabel(music_widget);      //音乐名
    music_name_label->setText("音乐名");
    music_name_label->setFixedSize(120, 30);

    video_btn = new QPushButton(music_widget);        //MV播放
    video_btn->setFixedSize(20, 30);
    video_btn->setStyleSheet("border-image: url(:/images/media.png);background-color:rgba(0,0,0,0%)");

    paly_btn = new QPushButton(music_widget);         //播放
    paly_btn->setFixedSize(20, 30);
    paly_btn->setStyleSheet("border-image: url(:/images/paly2.png);background-color:rgba(0,0,0,0%)");

    add_btn = new QPushButton(music_widget);          //添加到按钮
    add_btn->setFixedSize(20, 30);
    add_btn->setStyleSheet("border-image: url(:/images/add.png);background-color:rgba(0,0,0,0%)");

    down_btn = new QPushButton(music_widget);         //下载按钮
    down_btn->setFixedSize(20, 30);
    down_btn->setStyleSheet("border-image: url(:/images/down.png);background-color:rgba(0,0,0,0%)");

    more_btn = new QPushButton(music_widget);         //更多操作按钮
    more_btn->setFixedSize(20, 30);
    more_btn->setStyleSheet("border-image: url(:/images/more.png);background-color:rgba(0,0,0,0%)");

    music_author_btn = new QPushButton(music_widget); //歌手
    music_author_btn->setText("歌手");
    music_author_btn->setMaximumSize(80, 30);

    special_btn = new QPushButton(music_widget);      //专辑
    special_btn->setText("专辑");
//    special_btn->setMinimumSize(60, 30);
    special_btn->setFixedSize(160, 30);

    time_label = new QLabel(music_widget);            //时长
    time_label->setText("时长");

    music_layout =  new QHBoxLayout(music_widget);
    music_layout->addWidget(islike);
//    music_layout->addStretch(0);
    music_layout->addWidget(music_name_label);
//    music_layout->addStretch(0);
    music_layout->addWidget(video_btn);
//    music_layout->addStretch(0);
    music_layout->addWidget(paly_btn);
//    music_layout->addStretch(0);
    music_layout->addWidget(add_btn);
//    music_layout->addStretch(0);
    music_layout->addWidget(down_btn);
//    music_layout->addStretch(0);
    music_layout->addWidget(more_btn);
//    music_layout->addStretch(0);
    music_layout->addWidget(music_author_btn);
    music_layout->addStretch(0);
    music_layout->addWidget(special_btn);
    music_layout->addStretch(0);
    music_layout->addWidget(time_label);
    music_layout->addStretch(0);
    music_layout->addStretch(0);


    QSize size = music_item->sizeHint();
    music_item->setSizeHint(QSize(size.width(), 56));
}


MyPageItem::MyPageItem(QListWidget *father)
{
    page_item = new QListWidgetItem(father,0);

    page_widget = new QWidget(father);

    frist_page = new QPushButton(page_widget);
    frist_page->setText("1");
    frist_page->setFixedSize(40, 30);
    second_page = new QPushButton(page_widget);
    second_page->setText("2");
    second_page->setFixedSize(40, 30);
    three_page = new QPushButton(page_widget);
    three_page->setText("3");
    three_page->setFixedSize(40, 30);
    four_page = new QPushButton(page_widget);
    four_page->setText("4");
    four_page->setFixedSize(40, 30);
    five_page = new QPushButton(page_widget);
    five_page->setText("5");
    five_page->setFixedSize(40, 30);
    next_page = new QPushButton(page_widget);
    next_page->setText("下一页");
    next_page->setFixedSize(60, 30);
    previous_page = new QPushButton(page_widget);
    previous_page->setText("上一页");
    previous_page->setFixedSize(60, 30);

    page_layout =  new QHBoxLayout(page_widget);

    page_layout->addStretch();
    page_layout->addStretch();
    page_layout->addWidget(previous_page);
    page_layout->addWidget(frist_page);
    page_layout->addWidget(second_page);
    page_layout->addWidget(three_page);
    page_layout->addWidget(four_page);
    page_layout->addWidget(five_page);
    page_layout->addWidget(next_page);
    page_layout->addStretch();
    page_layout->addStretch();

    QSize size = page_item->sizeHint();
    page_item->setSizeHint(QSize(size.width(), 56));
}

LyricItem::LyricItem(QListWidget *father)
{
    lyric_item = new QListWidgetItem(father,0);

    lyric_widget = new QWidget(father);
    lyric_layout = new QHBoxLayout(lyric_widget);

    lyric_label = new QLabel(lyric_widget);
    lyric_label->setAlignment(Qt::AlignCenter);

    lyric_layout->addWidget(lyric_label);

    QSize size = lyric_item->sizeHint();
    lyric_item->setSizeHint(QSize(size.width(), 56));
}
