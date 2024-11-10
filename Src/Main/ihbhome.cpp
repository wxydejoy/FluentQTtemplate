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

IhbHome::IhbHome(QWidget* parent)
    : IhbPage(parent) {
    setWindowTitle("Home1");
    setTitleVisible(true);

    qDebug() << "初始化成功";
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setWindowTitle("aaa");
    addCentralWidget(centralWidget);
}
