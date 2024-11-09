#include "ihbhome.h"
#include "ihbpage.h"
#include "ElaWidgetTools/include/ElaAcrylicUrlCard.h"
#include "ElaWidgetTools/include/ElaFlowLayout.h"
#include "ElaWidgetTools/include/ElaImageCard.h"
#include "ElaWidgetTools/include/ElaMenu.h"
#include "ElaWidgetTools/include/ElaMessageBar.h"
#include "ElaWidgetTools/include/ElaNavigationRouter.h"
#include "ElaWidgetTools/include/ElaPopularCard.h"
#include "ElaWidgetTools/include/ElaScrollArea.h"
#include "ElaWidgetTools/include/ElaText.h"
#include "ElaWidgetTools/include/ElaToolTip.h"


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
