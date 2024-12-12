#ifndef IHBCONNECT_H
#define IHBCONNECT_H
#include "ihbBasePage.h"

class IhbConnect : public IhbBasePage
{
    Q_OBJECT
public:
    IhbConnect(QWidget* parent = nullptr);
};


class RosTopicConnect : public QWidget
{
    Q_OBJECT
public:
    explicit RosTopicConnect(QWidget *parent = nullptr, QString topicName = "topic");

signals:
};




#endif // IHBCONNECT_H
