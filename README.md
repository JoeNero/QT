#  QT学习笔记

	qcustomplot:官方画图
	
	QTPrj：自己的qt工程
	
	VS：
	
	基础:QT基础
	
	自定义控件:看该文件下README.md
	
	QWidgetDemo文件夹下是他人写好的自定义控件，可以直接使用。也有demo文件
	
	自定义控件：
	
			
# 1 基础

	快捷键:
	f4切换 cpp和h
	f5运行
	ctrl + /  注释
	f1 说明文档
	
	## 1.1qmake

    qmake是创建出来用于为不同的平台和编译器书写Makefile的工具。
	手写Makefile是比较困难并且容易出错的，
	尤其是需要给不同的平台和编译器组合写几个Makefile。
	使用qmake，开发者创建一个简单的项目文件并且运行qmake生成适当的Makefile。
	qmake会注意所有的编译器和平台的依赖性，可以把开发者解放出来只关心他们的代码。
																——qmake用户手册
	## 1.2项目.pro文件
	
	
    注释
    项目(.pro)文件中使用“#”作为注释
    模板(TEMPLATE)
    模板变量告诉qmake为这个应用程序生成哪种makefile。下面是可供使用的选择：
        app - 建立一个应用程序的makefile。这是默认值，所以如果模板没有被指定，这个将被使用。示例如下：TEMPLATE = app
        lib - 建立一个库的makefile
        vcapp - 建立一个应用程序的Visual Studio项目文件
        vclib - 建立一个库的Visual Studio项目文件
        subdirs - 这是一个特殊的模板，它可以创建一个能够进入特定目录并且为一个项目文件生成makefile，并且为它调用make的makefile。

	
	一个项目文件是用来告诉qmake关于为这个应用程序创建makefile所需要的细节。
	例如，一个源文件和头文件的列表、任何应用程序特定配置。
	例如，一个必需链接的额外库或者一个额外的包含路径、都应该放到项目文件中。
	
	HEADERS：应用程序中所有头文件的列表。
	SOURCES：应用程序中所有源文件的列表。
	FORMS：应用程序中的所有.ui文件(由Qt设计器生成)的列表。
	TARGET：可执行应用程序的名称。默认值为项目文件的名称。
	INCLUDEPATH：应用程序所需的额外的包含路径的列表。
				 比如：INCLUDEPATH += $$FFMPEG_INCLUDE，
				 其实$$FFMPEG_INCLUDE中的FFMPEG_INCLUDE是自定义变量，
				 表示ffmpeg的头文件路径
	LIBS：指定链接到项目中的库列表。
		  比如：LIBS += $$FFMPEG_LIB/libavcodec.so，
		  表示链接FFmpeg的库目录下的libavcodec.so这个动态库。

	——————————————————————————————————————————————————————————————————————————————————————————————————————————————————
	
	config变量指定编译器所要使用的选项和所需要被连接的库。配置变量中可以添加任何东西，但只有下面这些选项可以被qmake识别。
	下面这些选项控制着使用哪些编译器标志：

    release - 应用程序将以release模式联编。如果”debug”被指定，它将被忽略。
    debug - 应用程序将以debug模式联编
    warn_on - 编译器会输出尽可能多的警告信息。如果”warn_off”被指定，它将被忽略。
    warn_off - 编译器会输出尽可能少的警告信息。
    下面这些选项定义了所要联编的库/应用程序的类型：
    qt - 应用程序是一个Qt应用程序，并且Qt库将会被连接，也就是其实我们可以使用QtCreator来创建Qt程序，这时候会添加Qt库的支持。我们也可以不使用Qt的库，编写和Qt无关的程序，然后写项目(.pro)文件，来帮我们生成makefile，而不需要我们自己写makefile。有时间可以尝试一下，感觉自己写一个makefile还是比较麻烦的。
    thread - 应用程序是一个多线程应用程序
    x11 - 应用程序是一个x11应用程序或库
	CONFIG +=C++11
	——————————————————————————————————————————————————————————————————————————————————————————————————————————————————
	## 1.3 信号和槽
	
		QT信号槽机制的优缺点 
		1）QT信号槽机制的引用精简了程序员的代码量 
		2）QT的信号可以对应多个槽（但他们的调用顺序随机），也可以多个槽映射一个信号 
		3）QT的信号槽的建立和解除绑定十分自由 
		4）信号槽同真正的回调函数比起来时间的耗损还是很大的，所有在嵌入式实时系统中应当慎用 
		5）信号槽的参数限定很多例如不能携带模板类参数，不能出现宏定义等等

		test2				:信号发送者
		Test2::MySignal 	:发送的信号
		this				:信号接收者(this在这里接收)
		&Widget::dealSub2	:接收的槽函数
		
		connect(&test2,Test2::MySignal,this,&Widget::dealSub2);
		
		lamda表达式:(需要在.pro中加入CONFIG +=C++11)
		    connect(btn,&QPushButton::clicked,
            [=]()
			{
				qDebug() << "111";
			}
            );
			
		
# 2 控件
	
	QPushButton
	
# 3 事件过程
	

# 网络编程
	
	## TCP

		QT如果要进行网络编程首先需要在.pro中添加如下代码：
		QT += network 
		在头文件中包含相关头文件
		
		|#include <QHostInfo> 
		|#include <QNetworkInterface> 
		
	## UDP
		

	

# CRM 客户管理系统 (实现)

# M_SQL MySql qt的实现(实现)

# Snake 贪吃蛇	(未完成)

# Tetris 俄罗斯方块(实现)
