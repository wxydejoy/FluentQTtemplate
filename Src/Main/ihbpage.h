#ifndef IHBPAGE_H
#define IHBPAGE_H

#include <QWidget>
#include "ElaWidgetTools/include/ElaScrollPage.h"
class QVBoxLayout;
class IhbPage :public ElaScrollPage
{
    Q_OBJECT
public:
    explicit IhbPage(QWidget *parent = nullptr);

signals:

// protected:
    // void createCustomWidget(QString desText);
};

#endif // IHBPAGE_H
