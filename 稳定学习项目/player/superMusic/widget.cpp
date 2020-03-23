    #include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qsrand(time(NULL));
    initData();
    initPage();

    QFile file(":/qss/main.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString style_sheet = filetext.readAll();
    this->setStyleSheet(style_sheet);
    qDebug() << style_sheet;
    file.close();

    ui->tabWidget->setStyleSheet("background:transparent");

    connect(this, SIGNAL(tosearch()), this, SLOT(on_search_btn_clicked()));
    connect(this, SIGNAL(requestLyric()), this, SLOT(musicStatusChange()));
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(musicPositionChanged(qint64)));
    connect(play_list, SIGNAL(currentMediaChanged(QMediaContent)), this, SLOT(musicChanged(QMediaContent)));
    connect(this, SIGNAL(createListFinish()), this, SLOT(showList()));
    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(playMusic(QListWidgetItem*)));
    connect(this, SIGNAL(requestFinshed(int)), this, SLOT(createMusicList(int)));
    connect(manager_music, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpReplyMusicInfo(QNetworkReply *)));
    connect(manager_lyrics, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpReplyLyrics(QNetworkReply *)));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(httpReply(QNetworkReply *)));
    connect(manager_img, SIGNAL(finished(QNetworkReply *)), this, SLOT(httpReplyImg(QNetworkReply *)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_search_btn_clicked()
{
    ui->detail_widget->setCurrentIndex(2);
    page = 1;
    request->setUrl(QString(search_url).arg(ui->search_edit->text()).arg(page));
//    qDebug() << QString(search_url).arg(ui->search_edit->text());
    manager->get(*request);
}

void Widget::httpReply(QNetworkReply *reply)
{

    QByteArray byte_arr = reply->readAll();
    if (!byte_arr.isEmpty())
    {
        QJsonDocument document = QJsonDocument::fromJson(byte_arr);
        QJsonObject json_obj = document.object();

        QJsonObject json_obj_data = json_obj.value("data").toObject();


        if (!json_obj_data.isEmpty())
        {
            page_size = json_obj_data.value("pagesize").toInt();
            qDebug() << "pagesize" << page_size;
            QJsonArray music_list_json = json_obj_data.value("lists").toArray();
            if (!music_list_json.isEmpty())
            {
                for (int i = 0; i < 10; i++)
                {
                    if (music_info[i] == NULL)
                    {
                        break;
                    }

                    QJsonObject music_name_obj = music_list_json[i].toObject();
                    music_info[i]->hash = music_name_obj.value("FileHash").toString();
                    music_info[i]->album_id = music_name_obj.value("AlbumID").toString();

                    request_music->setUrl(QString(play_url).arg(music_info[i]->hash).arg(music_info[i]->album_id));

                    request_music->setRawHeader("Cookie", COOKIE);
                    request_music->setRawHeader("accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
                    manager_music->get(*request_music);
                    qDebug() << QString(play_url).arg(music_info[i]->hash).arg(music_info[i]->album_id);
                }
            }
        }
    }

}

void Widget::httpReplyMusicInfo(QNetworkReply *reply)
{
    QByteArray byte_arr = reply->readAll();

    if (!byte_arr.isEmpty())
    {
        QJsonDocument document = QJsonDocument::fromJson(byte_arr);
        QJsonObject json_obj = document.object();

        QJsonObject json_obj_data = json_obj.value("data").toObject();
        if (!json_obj_data.isEmpty())
        {
            int i = 0;
            QString hash = json_obj_data.value("hash").toString();
            QString id = json_obj_data.value("album_id").toString();
            for (i = 0; i < 10; i++)
            {
                if (hash == music_info[i]->hash && id ==music_info[i]->album_id)
                    break;
            }

            if (i == 10)
            {
                for(int i = 0; i < 10; i++)
                {
                    if (music_item[i] != NULL)
                    {
                        delete music_item[i];
                        music_item[i] = NULL;
                    }
                }

                qDebug() << "没有获取到音乐";
                return ;
            }

            music_info[i]->time_length = json_obj_data.value("timelength").toInt();
            music_info[i]->file_size = json_obj_data.value("filesize").toInt();
            music_info[i]->img_url = json_obj_data.value("img").toString();
            music_info[i]->have_mv = json_obj_data.value("have_mv").toInt();
            music_info[i]->author_name = json_obj_data.value("author_name").toString();
            music_info[i]->song_name = json_obj_data.value("song_name").toString();
            music_info[i]->play_url = json_obj_data.value("play_url").toString();
            music_info[i]->album_name = json_obj_data.value("album_name").toString();

            qDebug() << "imgurl:"<<music_info[i]->img_url;
            qDebug() << "playurl:"<<music_info[i]->play_url;
            qDebug() << "time_length:"<<music_info[i]->time_length;
            qDebug() << "filesize:"<<music_info[i]->file_size;
            qDebug() << "songname:"<<music_info[i]->song_name;
            qDebug() << "author_name:"<<music_info[i]->author_name;
            qDebug() << "album_name:"<<music_info[i]->album_name;

            if (music_item[i] == NULL)
            {
                music_item[i] = new MyItem(ui->listWidget);
                QSize size =  music_item[i]->music_item->sizeHint();
                music_item[i]->music_item->setSizeHint(QSize(size.width(), 56));
                ui->listWidget->addItem(music_item[i]->music_item);
                music_item[i]->music_widget->setSizeIncrement(QSize(size.width(), 56));
                connect(music_item[i]->paly_btn, SIGNAL(clicked(bool)), this, SLOT(palyBtn()));
                connect(music_item[i]->add_btn, SIGNAL(clicked(bool)), this, SLOT(addBtn()));
            }

            QString null_str;
            null_str.clear();
            for(int j = 0; j <= i; j++)
                null_str += " ";
            music_item[i]->paly_btn->setText(null_str);
            music_item[i]->add_btn->setText(null_str);

            emit requestFinshed(i);

        }
    }
}

void Widget::httpReplyLyrics(QNetworkReply *reply)
{    
    QByteArray byte_arr = reply->readAll();

    if (!byte_arr.isEmpty())
    {
        QJsonDocument document = QJsonDocument::fromJson(byte_arr);
        QJsonObject json_obj = document.object();
        if (json_obj.value("err_code") != 0)
        {
            qDebug() << "获取歌词出错";
            return;
        }
        QJsonObject json_obj_data = json_obj.value("data").toObject();
        if (!json_obj_data.isEmpty())
        {
            QString lyrics = json_obj_data.value("lyrics").toString();
            qDebug() << "lyrics: " << lyrics;

            QRegularExpression rex("(\\[\\d{2}:\\d{2}.\\d{2}\\]){1,}.*?\\n");
            QRegularExpressionMatch match;
            QString str;
            int offset = 0;
            do{
                match = rex.match(lyrics, offset);
                if(match.hasMatch()) {
                    offset = match.capturedEnd();
                    str = match.captured(0);

                    QRegularExpression re("\\d{2}:\\d{2}.\\d{2}");
                    QRegularExpressionMatch match_time;
                    QString time;

                    match_time = re.match(str);
                    time = match_time.captured(0);

                    QRegularExpression re1("\\].*?\\n");
                    QRegularExpressionMatch match_lyric;
                    QString lyric;

                    match_lyric = re1.match(str);
                    lyric = match_lyric.captured(0).trimmed().mid(1);

                    qDebug() << time << lyric;

                    Lyric lyric_obj;
                    lyric_obj.lyric = lyric;
                    lyric_obj.time = time.mid(0, 2).toInt()*60 * 1000 + time.mid(3).toFloat()*1000;

                    lyric_list << lyric_obj;
                    qDebug() << "jijij" << time.mid(0, 2) <<lyric_obj.time;

                }else
                {
                    break;
                }
            }while(!str.isEmpty());


        }
    }
}

void Widget::httpReplyImg(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();

        pm = new QPixmap;
        pm->loadFromData(bytes);

        QRect rc = ui->label->rect();

        QPixmap pm1 = pm->scaled(rc.size(), Qt::KeepAspectRatio);

        QRect rc1 = music_img->rect();

        QPixmap pm2 = pm->scaled(rc1.size(), Qt::KeepAspectRatio);

//        ui->label->setAutoFillBackground(true);
        ui->label->setPixmap(pm1);

        music_img->setPixmap(pm2);

    }
    else
    {
        //出错
    }
}

void Widget::createMusicList(int i)
{

    if (music_item[i] == NULL)
    {

        qDebug() << "地址错误";
        return;
    }

        qDebug() << "---------------------" << i<<"addr:" <<music_item[i];

    music_item[i]->music_name_label->setText(music_info[i]->song_name);
    music_item[i]->music_author_btn->setText(music_info[i]->author_name);
    music_item[i]->special_btn->setText(music_info[i]->album_name);

    int minute = music_info[i]->time_length / 1000 / 60;
    int second = music_info[i]->time_length / 1000 % 60;
    QString music_time = QString("%1:%2").arg(minute, 2, 10, QChar('0')).arg(second, 2, 10, QChar('0'));

    music_item[i]->time_label->setText(music_time);

    QString null_str;
    null_str.clear();
    for(int j = 0; j <= i; j++)
        null_str += " ";
    music_item[i]->music_item->setText(null_str);
    count++;
    qDebug() << "page_size&&count" <<page_size<<count;
    if (count == page_size)
    {
        count = 0;
        qDebug() << "发出信号";
        emit createListFinish();
    }
//
}

//双击播放槽函数
void Widget::playMusic(QListWidgetItem *item)
{

    paly_song->setStyleSheet("border-image: url(:/images/pause.png);background-color:rgba(0,0,0,0%)");

    if (item->text() == " ")
    {
        palyListAddMusic(0);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "  ")
    {
        palyListAddMusic(1);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "   ")
    {
        palyListAddMusic(2);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "    ")
    {
        palyListAddMusic(3);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "     ")
    {
        palyListAddMusic(4);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "      ")
    {
        palyListAddMusic(5);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "       ")
    {
        palyListAddMusic(6);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "        ")
    {
        palyListAddMusic(7);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "         ")
    {
        palyListAddMusic(8);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(item->text() == "          ")
    {
        palyListAddMusic(9);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
}

void Widget::funcDoubleClick(QListWidgetItem *func_item)
{
    qDebug()  <<func_item->text();
    if (func_item->text() == "音乐馆")
        ui->detail_widget->setCurrentIndex(0);
    else if (func_item->text() == "歌词")
        ui->detail_widget->setCurrentIndex(1);
    else if (func_item->text() == "音乐列表")
        ui->detail_widget->setCurrentIndex(2);
}

void Widget::showList()
{

    qDebug() << "sssssssssss";
    for (int i = 0; i < page_size; i++)
        ui->listWidget->setItemWidget(music_item[i]->music_item, music_item[i]->music_widget);


    if (pt == NULL)
    {
        pt = new MyPageItem(ui->listWidget);
        QSize page_size = pt->page_item->sizeHint();
        pt->page_item->setSizeHint(QSize(page_size.width(), 56));
        ui->listWidget->addItem(pt->page_item);
        pt->page_widget->setSizeIncrement(QSize(page_size.width(), 56));

        connect(pt->five_page, SIGNAL(clicked(bool)), this, SLOT(numPage()));
        connect(pt->four_page, SIGNAL(clicked(bool)), this, SLOT(numPage()));
        connect(pt->three_page, SIGNAL(clicked(bool)), this, SLOT(numPage()));
        connect(pt->second_page, SIGNAL(clicked(bool)), this, SLOT(numPage()));
        connect(pt->frist_page, SIGNAL(clicked(bool)), this, SLOT(numPage()));
        connect(pt->next_page, SIGNAL(clicked(bool)), this, SLOT(nextPage()));
        connect(pt->previous_page, SIGNAL(clicked(bool)), this, SLOT(previousPage()));
    }
    ui->listWidget->setItemWidget(pt->page_item, pt->page_widget);
}

void Widget::previousPage()
{
    if (page == 1)
        pt->previous_page->setEnabled(false);
    else
    {
        page--;
        if (page <= 1)
            pt->previous_page->setEnabled(false);
        count = 0;
        request->setUrl(QString(search_url).arg(ui->search_edit->text()).arg(page));
    //    qDebug() << QString(search_url).arg(ui->search_edit->text());
        manager->get(*request);
    }
}

void Widget::nextPage()
{
    pt->previous_page->setEnabled(true);
    page++;

    count = 0;
    request->setUrl(QString(search_url).arg(ui->search_edit->text()).arg(page));
//    qDebug() << QString(search_url).arg(ui->search_edit->text());
    manager->get(*request);
}

void Widget::addBtn()
{
    QPushButton *btn =qobject_cast<QPushButton *> (sender());
    if (btn->text() == " ")
    {
        palyListAddMusic(0);
    }
    else if(btn->text() == "  ")
    {
        palyListAddMusic(1);

    }
    else if(btn->text() == "   ")
    {
        palyListAddMusic(2);
    }
    else if(btn->text() == "    ")
    {
        palyListAddMusic(3);
    }
    else if(btn->text() == "     ")
    {
        palyListAddMusic(4);
    }
    else if(btn->text() == "      ")
    {
        palyListAddMusic(5);
    }
    else if(btn->text() == "       ")
    {
        palyListAddMusic(6);
    }
    else if(btn->text() == "        ")
    {
        palyListAddMusic(7);
    }
    else if(btn->text() == "         ")
    {
        palyListAddMusic(8);
    }
    else if(btn->text() == "          ")
    {
        palyListAddMusic(9);
    }
}

//按钮播放槽函数
void Widget::palyBtn()
{
    QPushButton *btn =qobject_cast<QPushButton *> (sender());

    if (btn->text() == " ")
    {
        palyListAddMusic(0);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "  ")
    {
        palyListAddMusic(1);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "   ")
    {
        palyListAddMusic(2);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "    ")
    {
        palyListAddMusic(3);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "     ")
    {
        palyListAddMusic(4);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "      ")
    {
        palyListAddMusic(5);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "       ")
    {
        palyListAddMusic(6);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "        ")
    {
        palyListAddMusic(7);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "         ")
    {
        palyListAddMusic(8);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }
    else if(btn->text() == "          ")
    {
        palyListAddMusic(9);
        int count = play_list->mediaCount();
        play_list->setCurrentIndex(--count);
        player->play();
    }

}

void Widget::musicChanged(QMediaContent content)
{

    //    寻找歌曲在列表中的具体位置
    for (int i = 0; i < music_list.size(); ++i)
    {
        if (music_list.at(i) == content)
        {
            request_img->setUrl(QUrl(music_list[i].img_url));
            manager_img->get(*request_img);
            qDebug() << "请求地址：" << music_list[i].img_url;

            music_name->setText(music_list[i].song_name + " - " + music_list[i].author_name);
            time_ratio->setText(QString("%1").arg(music_list[i].time_length));
            total_time = music_list[i].time_length;
            progress_slider->setRange(0, total_time);
            lyric_list.clear();
            lyric_item[0]->lyric_label->setText(music_list[i].song_name);
            lyric_item[1]->lyric_label->setText(music_list[i].author_name);

            emit requestLyric();
        }
    }
}

void Widget::musicPositionChanged(qint64 value)
{

    for (int i = 0; i < lyric_list.size() - 3; ++i)
    {
        if (lyric_list.at(i).time < value+800 && lyric_list.at(i + 1).time > value+800)
        {


            if (i <= 2)
            {
                lyric_item[2]->lyric_label->setText(lyric_list.at(0).lyric);
                lyric_item[3]->lyric_label->setText(lyric_list.at(1).lyric);
                lyric_item[4]->lyric_label->setText(lyric_list.at(2).lyric);
                lyric_item[5]->lyric_label->setText(lyric_list.at(3).lyric);
                lyric_item[6]->lyric_label->setText(lyric_list.at(4).lyric);
            }else
            {
                lyric_item[2]->lyric_label->setText(lyric_list.at(i-2).lyric);
                lyric_item[3]->lyric_label->setText(lyric_list.at(i-1).lyric);
                lyric_item[4]->lyric_label->setText(lyric_list.at(i).lyric);
                lyric_item[5]->lyric_label->setText(lyric_list.at(i+1).lyric);
                lyric_item[6]->lyric_label->setText(lyric_list.at(i+2).lyric);
            }
            qDebug() << lyric_list.at(i).lyric;
        }
    }
    progress_slider->setValue(value);
}

void Widget::progressMoved(int value)
{
    qDebug() << "h滑块移动";
    player->setPosition(value);
}

void Widget::palyTimeChanged(int value)
{
    int minute_total = total_time / 1000 / 60;
    int second_total = total_time / 1000 % 60;
    QString music_time = QString("%1:%2").arg(minute_total, 2, 10, QChar('0')).arg(second_total, 2, 10, QChar('0'));

    int minute_pass = value / 1000 /60;
    int second_pass = value / 1000 % 60;
    QString time_pass = QString("%1:%2").arg(minute_pass, 2, 10, QChar('0')).arg(second_pass, 2, 10, QChar('0'));

    int msecond = value % 1000 % 60;

    QString test = QString("%1:%2.%3").arg(minute_pass, 2, 10, QChar('0')).arg(second_pass, 2, 10, QChar('0')).arg(msecond, 2, 10, QChar('0'));
    qDebug() <<"time    "<< test;

    time_ratio->setText(time_pass + "/" + music_time);
}

void Widget::musicStatusChange()
{
    qDebug() << "进来了";
    QString name = music_name->text();

    for (int i = 0; i < music_list.size(); ++i)
    {
        qDebug() << name <<" :" << music_list.at(i).song_name;
        if (music_list.at(i).song_name+" - "+music_list.at(i).author_name == name)
        {
            qDebug() << "Found at11111 position" << i;

            request_lyrics->setUrl(QString(play_url).arg(music_list[i].hash).arg(music_list[i].album_id));

            request_lyrics->setRawHeader("Cookie", COOKIE);
            manager_lyrics->get(*request_lyrics);
            qDebug() << QString(play_url).arg(music_list[i].hash).arg(music_list[i].album_id);

        }

    }

}

void Widget::musicStatusChanged()
{
    switch(player->state())
    {
//        停止状态
        case QMediaPlayer::StoppedState: player->play();
        paly_song->setStyleSheet("border-image: url(:/images/pause.png);background-color:rgba(0,0,0,0%)");

        break;
//        播放状态
        case QMediaPlayer::PlayingState: player->pause();
        paly_song->setStyleSheet("border-image: url(:/images/paly.png);background-color:rgba(0,0,0,0%)");

        break;
//        暂停状态
        case QMediaPlayer::PausedState: player->play();
        paly_song->setStyleSheet("border-image: url(:/images/pause.png);background-color:rgba(0,0,0,0%)");
        break;
    }
}

void Widget::nextSong()
{

    qDebug() << "下一曲";
    int current;
    int row = play_list->mediaCount();

    if (play_list->playbackMode() == QMediaPlaylist::Random)
    {
        current = qrand() % row;
    }else if(play_list->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        current  = play_list->currentIndex();
    }else
    {
        current  = play_list->currentIndex();
        if(++current > row)
        {
            current = 0;
        }
    }
    play_list->setCurrentIndex(current);
    player->play();
}

void Widget::proviousSong()
{
    qDebug() << "下一曲";
    int current;
    int row = play_list->mediaCount();

    if (play_list->playbackMode() == QMediaPlaylist::Random)
    {
        current = qrand() % row;
    }else if(play_list->playbackMode() == QMediaPlaylist::CurrentItemInLoop)
    {
        current  = play_list->currentIndex();
    }else
    {
        current  = play_list->currentIndex();
        if(--current < row)
        {
            current = 0;
        }
    }
    play_list->setCurrentIndex(current);
    player->play();
}

void Widget::voiceChange(int value)
{
    player->setVolume(value);
}

void Widget::modeChange()
{
    static int i = 2;
    switch (i)
    {
//        顺序播放变随机播放
    case QMediaPlaylist::Sequential: play_list->setPlaybackMode(QMediaPlaylist::Random);
        i = 4;qDebug()<<"随机播放";
        paly_mode->setStyleSheet("border-image: url(:/images/rand.png);background-color:rgba(0,0,0,0%)");
        break;

//        随机播放变顺序循环播放
    case QMediaPlaylist::Random: play_list->setPlaybackMode(QMediaPlaylist::Loop);
        paly_mode->setStyleSheet("border-image: url(:/images/cyclic.png);background-color:rgba(0,0,0,0%)");
        i = 3;qDebug()<<"顺序循序播放";                  break;

//        循环播放变单曲播放
    case QMediaPlaylist::Loop: play_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        paly_mode->setStyleSheet("border-image: url(:/images/single.png);background-color:rgba(0,0,0,0%)");
        i = 1;qDebug()<<"单曲播放";       break;

//        单曲循环变顺序播放
    case QMediaPlaylist::CurrentItemInLoop: play_list->setPlaybackMode(QMediaPlaylist::Sequential);
        paly_mode->setStyleSheet("border-image: url(:/images/order.png);background-color:rgba(0,0,0,0%)");
        i = 2;qDebug()<<"顺序播放";     break;
    }
    //    player->setPlaylist(play_list);
}

void Widget::numPage()
{
    QPushButton *btn =qobject_cast<QPushButton *> (sender());
    page = btn->text().toInt();

    if (page == 1)
    {
        pt->previous_page->setEnabled(false);
    }else
    {
        pt->previous_page->setEnabled(true);
    }

    count = 0;
    request->setUrl(QString(search_url).arg(ui->search_edit->text()).arg(page));
//    qDebug() << QString(search_url).arg(ui->search_edit->text());
    manager->get(*request);
}

void Widget::lyricShow()
{
    ui->detail_widget->setCurrentIndex(1);
}

void Widget::initPage()
{
    //设置主页为默认显示页面
    this->setWindowIcon(QIcon(":/images/logo.ico"));
    this->setWindowTitle("钟牛叉音乐");
    ui->detail_widget->setCurrentIndex(0);
    ui->tabWidget->setCurrentIndex(0);
    bgm = new QLabel(this);
    bgm->lower();
//    bgm->setScaledContents(true);
    bgm->setAutoFillBackground(true);
    bgm->setStyleSheet("border-image: url(:/images/index.png);");
    bgm->setMinimumSize(1000, 560);

    ui->listWidget->setFrameShape(QListWidget::NoFrame);

    ui->search_edit->setStyleSheet("border-radius: 3px;background-color: rgba(0,0,0,20%)");

    music_hall = new QListWidgetItem(ui->func_listWidget);
    music_hall->setText("音乐馆");
    music_hall->setSizeHint(QSize(ui->func_listWidget->width(), 40));
    music_hall->setIcon(QIcon(":/images/music1.ico"));
    video = new QListWidgetItem(ui->func_listWidget);
    video->setText("歌词");
    video->setSizeHint(QSize(ui->func_listWidget->width(), 40));
    video->setIcon(QIcon(":/images/lyric1.ico"));
    local = new QListWidgetItem(ui->func_listWidget);
    local->setText("音乐列表");
    local->setSizeHint(QSize(ui->func_listWidget->width(), 40));
    local->setIcon(QIcon(":/images/local1.ico"));

    ui->search_btn->setStyleSheet("border-image: url(:/images/search.png);background-color:rgba(0,0,0,0%)");



//    ui->func_listWidget->setStyleSheet("QListWidget{color:rgb(173,175,178); background:rgb(255,255,255);border:0px solid gray;}"
//                                       "QListWidget::Item{height:50px;border:1px solid gray;padding-left:0;}"
//                                       "QListWidget::Item:hover{color:rgb(0,0,0);background:transparent;border:0px solid gray;}"
//                                       "QListWidget::Item:selected{border-image:url(images/listwidget_h.png); color:rgb(255,255,255);border:0px solid gray;}"
//                                       "QListWidget::Item:selected:active{background:#00FFFFFF;color:#FFFFFF;border-width:0;}");

//    ui->listWidget->setStyleSheet("QListWidget{color:rgb(173,175,178); background:rgb(108,255,214);border:0px solid gray;}"
//                                  "QListWidget::Item{height:30px;border:0px solid gray;padding-left:0;}"
//                                  "QListWidget::Item:hover{color:rgb(255,255,255);background:transparent;border:0px solid gray;}"
//                                  "QListWidget::Item:selected{border-image:url(images/listwidget_h.png); color:rgb(255,255,255);border:0px solid gray;}"
//                                  "QListWidget::Item:selected:active{background:#00FFFFFF;color:#FFFFFF;border-width:0;}"); 
    bt = new MyItem(ui->listWidget);
    QSize size = bt->music_item->sizeHint();
    bt->music_item->setSizeHint(QSize(size.width(), 56));
    ui->listWidget->addItem(bt->music_item);
    bt->music_widget->setSizeIncrement(QSize(size.width(), 56));
    ui->listWidget->setItemWidget(bt->music_item, bt->music_widget);

    bt->islike->setFixedSize(0, 0);
    bt->music_name_label->setFixedSize(295, 30);
    bt->music_name_label->setText("歌曲");
    bt->video_btn->hide();
    bt->paly_btn->hide();
    bt->add_btn->hide();
    bt->down_btn->hide();
    bt->more_btn->hide();
    bt->music_author_btn->setStyleSheet("background:transparent");
    bt->special_btn->setStyleSheet("background:transparent");


    qDebug() << "总计：" << ui->listWidget->count();

    progress_slider = new QSlider(Qt::Horizontal, ui->paly_widget);
    progress_slider->setMinimumSize(560, 2);

    music_img = new QLabel(ui->paly_widget);
    music_img->setFixedSize(50, 50);

    music_name = new QLabel(ui->paly_widget);
//    music_name->setText("歌曲名");
    music_name->setFixedSize(150, 50);
    paly_mode = new QPushButton(ui->paly_widget);
//    paly_mode->setText("播放模式");
    paly_mode->setFixedSize(30, 30);
    paly_mode->setStyleSheet("border-image: url(:/images/order.png);background-color:rgba(0,0,0,0%)");

    provious_song = new QPushButton(ui->paly_widget);
//    provious_song->setText("上一曲");
    provious_song->setFixedSize(30, 30);
    provious_song->setStyleSheet("border-image: url(:/images/prev.png);background-color:rgba(0,0,0,0%)");

    paly_song = new QPushButton(ui->paly_widget);
//    paly_song->setText("播放");
    paly_song->setFixedSize(50, 50);
    paly_song->setStyleSheet("border-image: url(:/images/paly.png);background-color:rgba(0,0,0,0%)");

    next_song = new QPushButton(ui->paly_widget);
//    next_song->setText("下一曲");
    next_song->setFixedSize(30, 30);
    next_song->setStyleSheet("border-image: url(:/images/next.png);background-color:rgba(0,0,0,0%)");

    voice = new QSlider(Qt::Horizontal, ui->paly_widget);
    voice->setFixedSize(50, 2);
    voice->setRange(0, 100);
    voice->setValue(player->volume());

    time_ratio = new QLabel(ui->paly_widget);
    time_ratio->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
//    time_ratio->setText("时间");
    time_ratio->setFixedSize(90, 40);
    islyric = new QPushButton(ui->paly_widget);
//    islyric->setText("歌词");
    islyric->setFixedSize(30, 30);
    islyric->setStyleSheet("border-image: url(:/images/word.png);background-color:rgba(0,0,0,0%)");

    paly_list = new QPushButton(ui->paly_widget);
//    paly_list->setText("列表");
    paly_list->setFixedSize(30, 30);
    paly_list->setStyleSheet("border-image: url(:/images/list.png);background-color:rgba(0,0,0,0%)");

//    music_img->setStyleSheet("background-color:red");

    paly_layout = new QHBoxLayout();
    paly_layout->addWidget(music_img);
    paly_layout->addWidget(music_name);
    paly_layout->addStretch(2);
    paly_layout->addWidget(paly_mode);
    paly_layout->addWidget(provious_song);
    paly_layout->addWidget(paly_song);
    paly_layout->addWidget(next_song);
    paly_layout->addWidget(voice);
    paly_layout->addStretch(2);
    paly_layout->addWidget(time_ratio);
    paly_layout->addWidget(islyric);
    paly_layout->addWidget(paly_list);
    paly_layout->setMargin(8);
    paly_layout->setSpacing(8);

    slider_layout = new QVBoxLayout(ui->paly_widget);
    slider_layout->addWidget(progress_slider);
    slider_layout->addLayout(paly_layout);
    slider_layout->setMargin(0);
    slider_layout->setSpacing(0);

//    lyirc_widget = new QHBoxLayout(ui->lyric_page);
    connect(ui->func_listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(funcDoubleClick(QListWidgetItem*)));
    connect(ui->func_listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(funcDoubleClick(QListWidgetItem*)));
    connect(islyric, SIGNAL(clicked(bool)), this, SLOT(lyricShow()));
    connect(paly_mode, SIGNAL(clicked(bool)), this, SLOT(modeChange()));
    connect(voice, SIGNAL(valueChanged(int)), this, SLOT(voiceChange(int)));
    connect(provious_song, SIGNAL(clicked(bool)), this, SLOT(proviousSong()));
    connect(next_song, SIGNAL(clicked(bool)), this, SLOT(nextSong()));
    connect(progress_slider, SIGNAL(valueChanged(int)), this, SLOT(palyTimeChanged(int)));
    connect(progress_slider, SIGNAL(sliderMoved(int)), this, SLOT(progressMoved(int)));
    connect(paly_song, SIGNAL(clicked(bool)), this, SLOT(musicStatusChanged()));
}

void Widget::initData()
{
    player = new QMediaPlayer;
    play_list = new QMediaPlaylist;
    request = new QNetworkRequest();
    manager = new QNetworkAccessManager();
    request_music = new QNetworkRequest();
    manager_music = new QNetworkAccessManager();
    request_lyrics = new QNetworkRequest();
    manager_lyrics = new QNetworkAccessManager();
    request_img = new QNetworkRequest();
    manager_img = new QNetworkAccessManager();

    player->setPlaylist(play_list);


    for (int i = 0; i < 10; i++)
    {
        music_info[i] = new Music_Info;
        music_item[i] = NULL;
    }
    for (int i = 0; i < 7; i++)
    {
        lyric_item[i] = new LyricItem(ui->lyric_listWidget);
        QSize size =  lyric_item[i]->lyric_item->sizeHint();
        ui->lyric_listWidget->addItem(lyric_item[i]->lyric_item);
        lyric_item[i]->lyric_widget->setSizeIncrement(QSize(size.width(), 56));

        ui->lyric_listWidget->setItemWidget(lyric_item[i]->lyric_item, lyric_item[i]->lyric_widget);
    }

    lyric_item[0]->lyric_label->setStyleSheet("font-size: 26px");
    lyric_item[4]->lyric_label->setStyleSheet("color:red");
    pt = NULL;
    pm = NULL;
    page = 1;
    count = 0;

    //初始化在线播放地址和搜索地址
    play_url = PLAYURL;
    search_url = SEARCHURL;
}

void Widget::palyListAddMusic(int i)
{
    MyQMediaContent music_content(QUrl(music_info[i]->play_url));
    music_content.album_name = music_info[i]->album_name;
    music_content.author_name = music_info[i]->author_name;
    music_content.file_size = music_info[i]->file_size;
    music_content.have_mv = music_info[i]->have_mv;
    music_content.song_name = music_info[i]->song_name;
    music_content.time_length = music_info[i]->time_length;
    music_content.music_url = music_info[i]->play_url;
    music_content.hash = music_info[i]->hash;
    music_content.album_id = music_info[i]->album_id;
    music_content.img_url = music_info[i]->img_url;
    music_list << music_content;

    play_list->addMedia(music_content);
}


void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "窗口大小改变";
    if (pm != NULL)
    {
        QRect rc = ui->label->rect();

        QPixmap pm1 = pm->scaled(rc.size(), Qt::KeepAspectRatio);
        ui->label->setPixmap(pm1);
    }

    bgm->setFixedSize(this->width(), this->height());
    qDebug() << event;
}

void Widget::on_pushButton_clicked()
{
    ui->search_edit->setText("泫雅");
    emit tosearch();
}

void Widget::on_pushButton_2_clicked()
{
    ui->search_edit->setText("胡歌");
    emit tosearch();
}

void Widget::on_pushButton_3_clicked()
{
    ui->search_edit->setText("古风");
    emit tosearch();
}

void Widget::on_pushButton_4_clicked()
{
    ui->search_edit->setText("民谣");
    emit tosearch();
}

void Widget::on_pushButton_5_clicked()
{
    ui->search_edit->setText("古风");
    emit tosearch();
}

void Widget::on_pushButton_6_clicked()
{
    ui->search_edit->setText("轻音乐");
    emit tosearch();
}
