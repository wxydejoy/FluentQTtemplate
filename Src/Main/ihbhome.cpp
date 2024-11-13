#include "ihbhome.h"
#include "ihbpage.h"
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


IhbHome::IhbHome(QWidget* parent)
    : IhbPage(parent) {
    setWindowTitle("Home1");
    setTitleVisible(true);


    // 创建主容器 QWidget
    // QWidget mainWidget;
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setWindowTitle("QCustomPlot in QWidget 示例");

    // 创建一个垂直布局
    QVBoxLayout *layout = new QVBoxLayout();

    // 创建 QCustomPlot 对象

    customPlot->setBackground(QColor("#F8F8F8"));



    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    customPlot->addGraph(); // red line
    customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    customPlot->xAxis->setTicker(timeTicker);
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->yAxis->setRange(-1.2, 1.2);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));


    dataTimer = new QTimer();

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer->start(0); // Interval 0 means to refresh as fast as possible
    // 将 QCustomPlot 添加到布局中
    layout->addWidget(customPlot);

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
