#include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include
#include <QMessageBox>

#include "ElaWindow.h"



#include "ElaContentDialog.h"
#include "ElaDockWidget.h"
#include "ElaEventBus.h"
#include "ElaLog.h"
#include "ElaMenu.h"
#include "ElaMenuBar.h"
#include "ElaProgressBar.h"
#include "ElaStatusBar.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaToolBar.h"
#include "ElaToolButton.h"
#include <QDebug>

#include "ihbHome.h"
#include "ihbConnect.h"
#include "IhbDebug.h"
#include "ihbControl.h"
MainWindow::MainWindow(QWidget *parent) :
    ElaWindow(parent)//,
    // ui(new Ui::MainWindow)
{
    // setIsEnableMica(true);
    // setIsCentralStackedWidgetTransparent(true);
    setWindowIcon(QIcon(":/include/Image/shoreKeeper200.png"));
    resize(1200, 800);
    // ElaLog::getInstance()->initMessageLog(true);
    // eTheme->setThemeMode(ElaThemeType::Dark);
    // setIsNavigationBarEnable(false);
    setNavigationBarDisplayMode(ElaNavigationType::Compact);
    // setWindowButtonFlag(ElaAppBarType::MinimizeButtonHint, false);
    setUserInfoCardPixmap(QPixmap(":/include/Image/shoreKeeper200.png"));
    setUserInfoCardTitle("Weiekko");
    setUserInfoCardSubTitle("Weiekko@gmail.com");
    setWindowTitle("IHB");
    setIsStayTop(true);
    // setUserInfoCardVisible(false);
    moveToCenter();
    homePage = new IhbHome(this);

    // IhbHome* errpage = new IhbHome(this);

    IhbConnect* connectpage = new IhbConnect(this);
    IhbDebug* debugpage = new IhbDebug(this);
    IhbControl* controlpage = new IhbControl(this);
    qDebug() << "初始化成功2";
    addPageNode("HOME", homePage, ElaIconType::House);
    // addPageNode("ERR", errpage, ElaIconType::House);
    addPageNode("CONNECT", connectpage, ElaIconType::ChartNetwork);
    addPageNode("DEBUG", debugpage, ElaIconType::GameBoard);
    addPageNode("CONTROL", controlpage, ElaIconType::Gear);
    qDebug() << "初始化成功3";
    // page = new ihbBasePage(this);
    // addPageNode("HOME", page, ElaIconType::House);
    // addPageNode()




    ElaMenuBar* menuBar = new ElaMenuBar(this);
    menuBar->setFixedHeight(30);
    QWidget* customWidget = new QWidget(this);
    QVBoxLayout* customLayout = new QVBoxLayout(customWidget);
    customLayout->setContentsMargins(0, 0, 0, 0);
    customLayout->addWidget(menuBar);
    customLayout->addStretch();
    // this->setMenuBar(menuBar);
    this->setCustomWidget(ElaAppBarType::MiddleArea, customWidget);
    this->setCustomWidgetMaximumWidth(500);

    menuBar->addElaIconAction(ElaIconType::AtomSimple, "急停(空格)");








    //状态栏
    ElaStatusBar* statusBar = new ElaStatusBar(this);
    ElaText* statusText = new ElaText("初始化成功！", this);
    statusText->setTextPixelSize(14);
    statusBar->addWidget(statusText);
    this->setStatusBar(statusBar);
}

MainWindow::~MainWindow()
{
    // delete ui;
}
