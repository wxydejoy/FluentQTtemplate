#include "rosBridgeClient.h"
#include <QDebug>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>

// 初始化静态成员变量
ROSBridgeClient* ROSBridgeClient::instance_ = nullptr;

ROSBridgeClient::ROSBridgeClient(QObject *parent)
    : QObject(parent), webSocket_(new QWebSocket()), publishTimer_(new QTimer(this))
{
    // 设置连接信号与槽
    connect(webSocket_, &QWebSocket::connected, this, &ROSBridgeClient::onConnected);
    connect(webSocket_, &QWebSocket::disconnected, this, &ROSBridgeClient::onDisconnected);
    connect(webSocket_, &QWebSocket::textMessageReceived, this, &ROSBridgeClient::onMessageReceived);
    connect(webSocket_, &QWebSocket::errorOccurred, this, &ROSBridgeClient::onErrorOccurred);

    // 定时器设置，每隔 5 秒发布一次消息
    connect(publishTimer_, &QTimer::timeout, this, &ROSBridgeClient::publishToROS);
    publishTimer_->start(5000);  // 每 5 秒触发一次定时器
}

ROSBridgeClient::~ROSBridgeClient()
{
    if (webSocket_->state() == QAbstractSocket::ConnectedState) {
        webSocket_->close();
    }
    delete webSocket_;
}

ROSBridgeClient* ROSBridgeClient::instance()
{
    if (!instance_) {
        instance_ = new ROSBridgeClient();
    }
    return instance_;
}

void ROSBridgeClient::destroyInstance()
{
    delete instance_;
    instance_ = nullptr;
}

void ROSBridgeClient::connectToServer(const QUrl &url)
{
    qDebug() << "Connecting to WebSocket server: " << url.toString();
    webSocket_->open(url);
}

void ROSBridgeClient::disconnectFromServer()
{
    qDebug() << "Disconnecting from WebSocket server...";
    webSocket_->close();
}

void ROSBridgeClient::onConnected()
{
    qDebug() << "Connected to WebSocket server";
    emit connected();

    // 一旦连接成功，自动发布消息
    QJsonObject message;
    message["data"] = "Hello, ROS!";
    publishMessage("/chatter", message);  // 向 /chatter 话题发布初始消息
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

void ROSBridgeClient::onErrorOccurred(QAbstractSocket::SocketError error)
{
    qDebug() << "Error occurred: " << error;
    emit errorOccurred(webSocket_->errorString());
}

void ROSBridgeClient::publishMessage(const QString &topic, const QJsonObject &message)
{
    // 构建 WebSocket 消息
    QJsonObject json;
    json["op"] = "publish";
    json["topic"] = topic;
    json["msg"] = message;

    // 将 JSON 对象转换为字符串并发布
    QJsonDocument doc(json);
    QString messageStr = doc.toJson(QJsonDocument::Compact);
    webSocket_->sendTextMessage(messageStr);  // 发送消息到 ROS
    qDebug() << "Publishing message to ROS: " << messageStr;
}

void ROSBridgeClient::publishToROS()
{
    // 定期发布消息到多个话题
    // static int counter = 0;
    QJsonObject message;
    message["data"] = "counter++";
    
    // 发布到多个话题
    publishMessage("/chatter", message);
    publishMessage("/another_topic", message);
}
