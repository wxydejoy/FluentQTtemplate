#include "ihbHome.h"
#include "ihbBasePage.h"
#include "ElaAcrylicUrlCard.h"
#include "ElaFlowLayout.h"
#include "ElaImageCard.h"
#include "ElaMenu.h"
#include "ElaMessageBar.h"
#include "ElaNavigationRouter.h"
#include "ElaPopularCard.h"
#include "ElaScrollArea.h"
#include "ElaText.h"
#include "ElaToolTip.h"
#include "ElaPromotionCard.h"
#include "ElaPromotionView.h"
#include "ElaScrollPageArea.h"
#include "ElaToggleSwitch.h"

// #include "

// #include "

#include <QDebug>
#include <QDesktopServices>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QVBoxLayout>
#include <QElapsedTimer>
#include <QtGlobal>
#include <QRandomGenerator>

#include "qcustomplot.h"
// #include "rclcpp/rclcpp.hpp"

IhbHome::IhbHome(QWidget* parent)
    : IhbBasePage(parent) {
    // setWindowTitle("Home");
    setTitleVisible(true);



    _promotionView = new ElaPromotionView(this);
    // _promotionView->setCardExpandWidth(1);


    ElaPromotionCard* exampleCard1 = new ElaPromotionCard(this);
    exampleCard1->setHorizontalCardPixmapRatio(20);
    exampleCard1->setCardPixmap(QPixmap(":/include/Image/Cirno.jpg"));
    exampleCard1->setCardTitle("MiKu");
    exampleCard1->setPromotionTitle("SONG~");
    exampleCard1->setTitle("STYX HELIX");
    exampleCard1->setSubTitle("Never close your eyes, Searching for a true fate");

    ElaPromotionCard* exampleCard2 = new ElaPromotionCard(this);
    exampleCard2->setCardPixmap(QPixmap(":/include/Image/Cirno.jpg"));
    exampleCard2->setCardTitle("Beach");
    exampleCard2->setPromotionTitle("SONG~");
    exampleCard2->setTitle("STYX HELIX");
    exampleCard2->setSubTitle("Never close your eyes, Searching for a true fate");

    ElaPromotionCard* exampleCard3 = new ElaPromotionCard(this);
    exampleCard3->setCardPixmap(QPixmap(":/include/Image/Cirno.jpg"));
    exampleCard3->setCardTitle("Dream");
    exampleCard3->setPromotionTitle("SONG~");
    exampleCard3->setTitle("STYX HELIX");
    exampleCard3->setSubTitle("Never close your eyes, Searching for a true fate");

    ElaPromotionCard* exampleCard4 = new ElaPromotionCard(this);
    exampleCard4->setCardPixmap(QPixmap(":/include/Image/Cirno.jpg"));
    exampleCard4->setCardTitle("Classroom");
    exampleCard4->setPromotionTitle("SONG~");
    exampleCard4->setTitle("STYX HELIX");
    exampleCard4->setSubTitle("Never close your eyes, Searching for a true fate");

    _promotionView->appendPromotionCard(exampleCard1);
    _promotionView->appendPromotionCard(exampleCard2);
    _promotionView->appendPromotionCard(exampleCard3);
    _promotionView->appendPromotionCard(exampleCard4);
    _promotionView->setIsAutoScroll(true);


    // 基础模块节点组
    ElaToggleSwitch* _toggleSwitch = new ElaToggleSwitch(this);
    ElaScrollPageArea* toggleSwitchArea = new ElaScrollPageArea(this);
    QHBoxLayout* toggleSwitchLayout = new QHBoxLayout(toggleSwitchArea);
    ElaText* toggleSwitchText = new ElaText("启动X5基础模块节点组（请先确认电源是否连接）", this);
    toggleSwitchText->setTextPixelSize(15);
    toggleSwitchLayout->addWidget(toggleSwitchText);
    toggleSwitchLayout->addWidget(_toggleSwitch);
    toggleSwitchLayout->addStretch();
    ElaToggleSwitch* toggleSwitchDisableSwitch = new ElaToggleSwitch(this);
    ElaText* toggleSwitchDisableText = new ElaText("禁用", this);
    toggleSwitchDisableText->setTextPixelSize(15);

    toggleSwitchLayout->addWidget(toggleSwitchDisableSwitch);
    toggleSwitchLayout->addWidget(toggleSwitchDisableText);
    toggleSwitchLayout->addSpacing(10);

    // 大模型节点组
    ElaToggleSwitch* _toggleSwitch2 = new ElaToggleSwitch(this);
    ElaScrollPageArea* toggleSwitchArea2 = new ElaScrollPageArea(this);
    QHBoxLayout* toggleSwitchLayout2 = new QHBoxLayout(toggleSwitchArea2);
    ElaText* toggleSwitchText2 = new ElaText("启动X5大模型节点组", this);
    toggleSwitchText2->setTextPixelSize(15);
    toggleSwitchLayout2->addWidget(toggleSwitchText2);
    toggleSwitchLayout2->addWidget(_toggleSwitch2);

    toggleSwitchLayout2->addStretch();  
    toggleSwitchLayout2->addWidget(toggleSwitchDisableSwitch);
    toggleSwitchLayout2->addWidget(toggleSwitchDisableText);
    toggleSwitchLayout2->addSpacing(10);



    // 创建一个垂直布局
    QVBoxLayout *layout = new QVBoxLayout();





    // 将 QCustomPlot 添加到布局中
    layout->addWidget(_promotionView);
    layout->addWidget(toggleSwitchArea);
    layout->addWidget(toggleSwitchArea2);

    // 创建主容器 QWidget
    // QWidget mainWidget;
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setWindowTitle("功能导航");

    // 将布局设置到主容器
    mainWidget->setLayout(layout);

    qDebug() << "初始化成功";
    // QWidget* centralWidget = new QWidget(this);
    // centralWidget->setWindowTitle("aaa");
    addCentralWidget(mainWidget);
}



void IhbHome::realtimeDataSlot(){
    // qDebug() << "slot";
    // static QTime time(QTime::currentTime());
    static QElapsedTimer timer;
    static bool started;
    // static void startTimer()
    // {
        if (!started) {
            timer.start();  // 启动计时器
            started = true;  // 设置标志位，确保计时器只启动一次
            qDebug() << "Timer started!";
        }
    // }

    // calculate two new data points:
    double key = timer.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    // qDebug() << key;
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.002) // at most add point every 2 ms
    {
        // add data to lines:
        double randomDouble1 = generator->generateDouble();
        double randomDouble2 = generator->generateDouble();
        customPlot->graph(0)->addData(key, qSin(key)+0.1*randomDouble1);
        customPlot->graph(1)->addData(key, qCos(key)+0.1*randomDouble2);
        // rescale value (vertical) axis to fit the current data:
        //ui->customPlot->graph(0)->rescaleValueAxis();
        //ui->customPlot->graph(1)->rescaleValueAxis(true);
        lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
    customPlot->replot();

    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
        // ui->statusBar->showMessage(
        //     QString("%1 FPS, Total Data points: %2")
        //         .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
        //         .arg(ui->customPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
        //     , 0);
        lastFpsKey = key;
        frameCount = 0;
    }
}
