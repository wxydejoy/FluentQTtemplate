#ifndef IHBHOME_H
#define IHBHOME_H

#include "ihbpage.h"
#include "qcustomplot.h"
#include <QRandomGenerator>
class ElaMenu;
class IhbHome : public IhbPage
{
    Q_OBJECT
public:
    IhbHome(QWidget* parent = nullptr);

public slots:
    void realtimeDataSlot();
private:
    ElaMenu* _homeMenu{nullptr};
    QTimer* dataTimer{nullptr};

    QCustomPlot *customPlot = new QCustomPlot();
    QRandomGenerator *generator = QRandomGenerator::global();

};

#endif // IHBHOME_H
