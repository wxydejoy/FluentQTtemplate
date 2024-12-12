// rosbridge_client.cpp
#include "rosBridgeClient.h"
#include <QJsonObject>
#include <QDebug>
ROSBridgeClient* ROSBridgeClient::m_instance = nullptr;  // 初始化静态成员
ROSBridgeClient::ROSBridgeClient(QObject *parent)
    : QObject(parent), worker_(new ROSBridgeClientWorker()), timer_(new QTimer(this))
{
    // 连接工作线程的信号和槽
    connect(worker_, &ROSBridgeClientWorker::connected, this, &ROSBridgeClient::onConnected);
    connect(worker_, &ROSBridgeClientWorker::disconnected, this, &ROSBridgeClient::onDisconnected);
    connect(worker_, &ROSBridgeClientWorker::messageReceived, this, &ROSBridgeClient::onMessageReceived);
    connect(worker_, &ROSBridgeClientWorker::errorOccurred, this, &ROSBridgeClient::onErrorOccurred);

    // 设置定时器
    connect(timer_, &QTimer::timeout, this, &ROSBridgeClient::onTimeout);
}

ROSBridgeClient::~ROSBridgeClient()
{
    delete worker_;
    delete timer_;
}

void ROSBridgeClient::connectToServer(const QUrl &url)
{
    worker_->connectToServer(url);
}
ROSBridgeClient* ROSBridgeClient::instance()
{
    if (m_instance == nullptr) {
        m_instance = new ROSBridgeClient();
    }
    return m_instance;
}

void ROSBridgeClient::publishMessage(const QString &message, const QString &topic)
{
    QJsonObject json;
    json["op"] = "publish";
    json["topic"] = topic;
    json["msg"] = QJsonObject{{"data", message}};
    
    worker_->sendMessage(json);
}

void ROSBridgeClient::startPublishing(int interval)
{
    // 设置定时器间隔（毫秒）
    timer_->start(interval);
}

void ROSBridgeClient::onTimeout()
{
    // 定时发布消息
    qDebug() << "Publishing message...";
    // 获取当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 发布消息
    publishMessage(currentTime, "/chatter");
}

void ROSBridgeClient::onConnected()
{
    qDebug() << "Connected to WebSocket server";
    emit connected();

    // 在连接成功后启动定时发布
    startPublishing(5000);  // 每5秒发布一次
}

void ROSBridgeClient::onDisconnected()
{
    qDebug() << "Disconnected from WebSocket server";
    emit disconnected();
}

void ROSBridgeClient::onMessageReceived(const QString &message)
{
    qDebug() << "Message received: " << message;
    emit messageReceived(message);
}

void ROSBridgeClient::onErrorOccurred(const QString &errorString)
{
    qDebug() << "Error occurred: " << errorString;
    emit errorOccurred(errorString);
}
