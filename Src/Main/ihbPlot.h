#ifndef IHBPLOT_H
#define IHBPLOT_H

#include "ihbBasePage.h"
#include "qcustomplot.h"
#include <QRandomGenerator>
// #include "rclcpp/rclcpp.hpp"
// class RosThread : public QThread
// {
// public:
//     RosThread() : node_(std::make_shared<rclcpp::Node>("qt_node")) {}

//     // add pub


//     void run() override
//     {
//         rclcpp::spin(node_);
//     }

//     rclcpp::Node::SharedPtr get_node()
//     {
//         return node_;
//     }

// private:
//     rclcpp::Node::SharedPtr node_;
// };

class ElaMenu;
class IhbPlot : public IhbBasePage
{
    Q_OBJECT
public:
    IhbPlot(QWidget* parent = nullptr);

public slots:
    void realtimeDataSlot();
private:
    ElaMenu* _homeMenu{nullptr};
    QTimer* dataTimer{nullptr};

    QCustomPlot *customPlot = new QCustomPlot();
    QRandomGenerator *generator = QRandomGenerator::global();

};

#endif // IhbPlot_H
