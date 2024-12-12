#ifndef IHBDEBUG_H
#define IHBDEBUG_H
#include "ihbBasePage.h"

class IhbDebug : public IhbBasePage
{
    Q_OBJECT
public:
    IhbDebug(QWidget* parent = nullptr);
};

class MotorDebug : public QWidget
{
    Q_OBJECT
public:
    MotorDebug(QWidget* parent = nullptr,int motorIndex = 0);
};

class ARMDebug : public QWidget
{
    Q_OBJECT
public:
    ARMDebug(QWidget* parent = nullptr);
};


class JointDebug : public QWidget
{
    Q_OBJECT
public:
    JointDebug(QWidget* parent = nullptr,int jointIndex = 0);
};

#endif // IHBDEBUG_H
