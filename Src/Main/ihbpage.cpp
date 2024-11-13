#include "ihbpage.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>


#include "ElaMenu.h"
#include "ElaText.h"
#include "ElaTheme.h"
#include "ElaToolButton.h"

IhbPage::IhbPage(QWidget *parent)
    : ElaScrollPage(parent)
{

    connect(eTheme, &ElaTheme::themeModeChanged, this, [=]() {
        if (!parent)
        {
            update();
        }
    });

    // QWidget* centralWidget = new QWidget(this);
    // addCentralWidget(centralWidget);
    // addCentralWidget(centralWidget);

    qDebug() << "初始化成功";
}


