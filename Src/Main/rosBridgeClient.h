#ifndef ROSBRIDGECLIENT_H
#define ROSBRIDGECLIENT_H

#include <QObject>
#include <QWebSocket>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>

class ROSBridgeClient : public QObject
{
    Q_OBJECT

public:
    static ROSBridgeClient* instance();  // 获取单例实例
    static void destroyInstance();  // 销毁单例实例

    void connectToServer(const QUrl &url);
    void disconnectFromServer();
    void publishMessage(const QString &topic, const QJsonObject &message);

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString &message);
    void errorOccurred(const QString &errorString);

private slots:
    void onConnected();
    void onDisconnected();
    void onMessageReceived(const QString &message);
    void onErrorOccurred(QAbstractSocket::SocketError error);
    void publishToROS();  // 定时发布消息

private:
    explicit ROSBridgeClient(QObject *parent = nullptr);
    ~ROSBridgeClient();

    static ROSBridgeClient *instance_;  // 单例实例

    QWebSocket *webSocket_;   // WebSocket 客户端
    QTimer *publishTimer_;    // 定时器
};

#endif // ROSBRIDGE_CLIENT_H
