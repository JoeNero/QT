# liunx 下注意点

编译太慢,更改

-j 4       4为线程 <= cpu的线程

缺少:-1: error: 找不到 -lGL
sudo apt-get install libgl1-mesa-dev

使用以下模块需要 实现下载这个 qt会自动查找

sudo apt-get install qtmultimedia5-dev

如果不行则加:

sudo apt-get install libpul se-dev

视频相关控件需要安装如下内容

```
apt-get install libpulse-dev
```

```
QT       += multimedia
```

# 布局管理

## QGridLayout网格布局

```cpp
layout->setRowStretch(int row, int stretch);//设置行比例系数
layout->setColumnStretch(int column, int stretch);//设置列比例系数
```

布局示意如下:

```cpp
layout->addWidget(&TestBtn1, 0, 0);//往网格的不同坐标添加不同的组件
layout->addWidget(&TestBtn2, 0, 1);
layout->addWidget(&TestBtn3, 1, 0);
layout->addWidget(&TestBtn4, 1, 1);
```

# 控件：

## QLCDNumber：

lcd是直接通过方法value来获取当前显示的值，通过方法display来显示

QLCDNumber有以下几种模式：

[setHexMode](https://blog.csdn.net/xuancailinggan/article/details/qlcdnumber.html#setHexMode)()-十六进制

[setDecMode](https://blog.csdn.net/xuancailinggan/article/details/qlcdnumber.html#setDecMode)()-十进制

[setOctMode](https://blog.csdn.net/xuancailinggan/article/details/qlcdnumber.html#setOctMode)()-八进制

[setBinMode](https://blog.csdn.net/xuancailinggan/article/details/qlcdnumber.html#setBinMode)()-二进制

lcdNum->setDecMode();

# QTimer

Q_DECL_OVERRIDE也就是c++的override

```
# define Q_DECL_OVERRIDE override
```

在重写虚函数时会用到，

作用是防止写错虚函数：

```
void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
```



```cpp
//头文件在QTimer文件下
#include <QTimer>
...
QTimer *m_pTimer;
m_pTimer = new QTimer(this);
// 设置超时间隔
m_pTimer->setInterval(100);
...
connect(m_pTimer, SIGNAL(timeout()), this, SLOT(updateProgress()));
m_pTimer->start(1000);//这一步会覆盖之前设置的时间间隔
```

start()之后，每秒都会调用update()

可以通过设置setSingleShot(true)来让定时器只执行一次。也可以使用静态函数QTimer::singleShot()：

```
QTimer::singleShot(200, this, SLOT(updateCaption()));
```

# QChart

.pro文件添加模块

```c++
QT +=charts
```

```cpp
//使用charts模板需要加入命名控件或者宏
using namespace Qtcharts
或者一个宏 QT_CHARTS_USE_NAMESPACE
//头文件
#include <QChart>
#include <QChartView>
...
QChart *chart;
QChartView *chartView;
```

```cpp
//坐标系
#include <QValueAxis>
...
QValueAxis *axisX;
QValueAxis *axisY;
...
axisX->setRange(0, 20);    		//设置范围
axisX->setLabelFormat("%u");   	//设置刻度的格式 y轴同理
axisX->setTitleText("X");           		//设置描述
axisY->setTitleText("Y");
/************************************
    %u 无符号十进制整数
    %s 字符串
    %A 浮点数、十六进制数字和p-记法
    %c 一个字符
    %d 有符号十进制整数
    %e 浮点数、e-记数法
    %E 浮点数、E-记数法
    %f 浮点数、十进制记数法
    %g 根据数值不同自动选择％f或％e．
    %G 根据数值不同自动选择％f或％e.
    %i 有符号十进制数（与％d相同）
    %o 无符号八进制整数
    %p 指针
    %s 字符串
    %x/%X 使用十六进制数字0f的无符号十六进制整数
****************************************/
//标记的个数
    axisX->setTickCount(11);           
    axisY->setTickCount(11);
//次标记的个数
	axisX->setMinorTickCount(1);        //设置每个大格里面小刻度线的数目
//    axisY->setMinorTickCount(1);
	chart->createDefaultAxes(); //建立默认坐标轴，不需要QValueAxis 默认是4x4大格子
//	chart->axisY()->setRange(0, 10);//默认坐标轴限定范围
chart->addAxis(axisX, Qt::AlignBottom); //下：Qt::AlignBottom  上：Qt::AlignTop
chart->addAxis(axisY, Qt::AlignLeft);   //左：Qt::AlignLeft    右：Qt::AlignRight

```

```cpp
    chart->setTitle("曲线图实例");
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置曲线动画模式
    chart->legend()->hide(); 							//隐藏图例
    chart->addSeries(splineSeries);						//输入数据
    chart->setAxisX(axisX, splineSeries);
    chart->setAxisY(axisY, splineSeries);
```

需要将chart添加到chartView

```cpp
    chartView->show();
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);//防止图形走样
```

## 曲线图

QSplineSeries

```cpp
#include <QSplineSeries>
```

```cpp
splineSeries = new QSplineSeries;
//添加数据的两周方式
splineSeries->append(10, 5);
*splineSeries << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6)<< QPointF(20, 2);
//源数据添加到图表上
chart->addSeries(splineSeries);//输入数据
chart->setAxisX(axisX, splineSeries);
chart->setAxisY(axisY, splineSeries);
```

## 柱状图

先包含头文件

```cpp
#include <QBarSet> 
```

QBarSet类表示条形图中的一组条形。
一个bar集包含每个类别的一个数据值。
假设集合的第一个值属于第一个类别，
第二个属于第二个类别，依此类推。
如果集合的值小于类别的值，则假设缺失值位于集合的末尾。对于位于集合中间的缺失值，则使用0的数值。
没有显示零值集的标签。

```
#include <QBarSeries>
```

QBarSeries类表示的是柱状图数据，需要将相应的QBarSet添加进来

柱状图关系示意如下:

![柱状图示意](/media/xtt/workspace/GitHub/QT/基础/柱状图示意.png)

## 饼状图

```cpp
#include <QCharts/QPieSeries>
```

QPieSeries是一块饼图

```cpp
#include <QCharts/QPieSlice>
```

QPieSlice是饼图上的碎片

![饼状图示意](/media/xtt/workspace/GitHub/QT/基础/饼状图示意.png)

# QCustomPlot

```
QT       += core gui printsupport
```

选择项目的.pro文件，添加printsupport，如图，QCustomPlot包含了一些打印的东西，如果没有这一步，程序会报错

基类为QWidget：提升为`QCustomPlot`

这里强调一下：Qt提升控件时，通常提升的类名称中，每个单词的首字母必须大写与Qt控件命名规则保持一致，各种第三方控件都采用这种命名格式，否则无法识别，如这里必须写成`QCustomPlot`而不能写成`Qcustomplot`或`qcustomplot`

# 动态库的调用

## liunx

详细图例见dll文件

创建c++库，添加代码生成对应的.so文件

在debug文件下将.so文件后缀的复制到新建工程的debug文件下

![1582179556607](/media/xtt/workspace/GitHub/QT/基础/1582179556607.png)

并将相应的头文件添加到目标工程中![1582179823790](/media/xtt/workspace/GitHub/QT/基础/1582179823790.png)

在.pro里面添加 如下 格式 -L./lib -l(文件名)  因为直接放在debug文件下所以直接 在该文件夹下找

```
LIBS +=  -L -llibdll
```



