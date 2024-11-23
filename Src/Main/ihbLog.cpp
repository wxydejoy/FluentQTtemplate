#include "IhbLog.h"
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
#include "ElaPlainTextEdit.h"
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
// #include "rclcpp/rclcpp.hpp"

IhbLog::IhbLog(QWidget* parent)
    : IhbBasePage(parent) {



    // 创建主容器 QWidget
    // QWidget mainWidget;
    QWidget* mainWidget = new QWidget(this);
    mainWidget->setWindowTitle("");
    // mainWidget->

    // 创建一个垂直布局
    QVBoxLayout *layout = new QVBoxLayout();

    ElaPlainTextEdit *plainTextEdit = new ElaPlainTextEdit(mainWidget);
    
    layout->addWidget(plainTextEdit);


    // 将布局设置到主容器
    mainWidget->setLayout(layout);

    // qDebug() << "初始化成功";
    // QWidget* centralWidget = new QWidget(this);
    // centralWidget->setWindowTitle("aaa");
    addCentralWidget(mainWidget);
}


