#ifndef IHBHOME_H
#define IHBHOME_H

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
class IhbHome : public IhbBasePage
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
