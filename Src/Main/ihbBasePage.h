#ifndef IHBBASEPAGE_H
#define IHBBASEPAGE_H

#include <QWidget>
// #include "ElaWidgetTools/include/ElaScrollPage.h"
#include "ElaScrollPage.h"
class QVBoxLayout;
class IhbBasePage :public ElaScrollPage
{
    Q_OBJECT
public:
    explicit IhbBasePage(QWidget *parent = nullptr);

signals:

// protected:
    // void createCustomWidget(QString desText);
};

#endif // ihbBasePage_H
