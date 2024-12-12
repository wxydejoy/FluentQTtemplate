// rosbridge_client.h
#ifndef ROSBRIDGE_CLIENT_H
#define ROSBRIDGE_CLIENT_H

#include <QObject>
#include <QUrl>
#include <QTimer>
#include "rosBridgeClientWorker.h"

class ROSBridgeClient : public QObject
{
    Q_OBJECT

public:
    explicit ROSBridgeClient(QObject *parent = nullptr);
    static ROSBridgeClient* instance();  // 单例方法
    ~ROSBridgeClient();

    void connectToServer(const QUrl &url);
    void publishMessage(const QString &message, const QString &topic);
    void startPublishing(int interval); // 启动定时发布

signals:
    void connected();
    void disconnected();
    void messageReceived(const QString &message);
    void errorOccurred(const QString &errorString);

private slots:
    void onConnected();
    void onDisconnected();
    void onMessageReceived(const QString &message);
    void onErrorOccurred(const QString &errorString);
    void onTimeout(); // 定时器超时，发布消息

private:
    ROSBridgeClientWorker *worker_;
    QTimer *timer_; // 定时器
    static ROSBridgeClient* m_instance;  // 单例实例
};

#endif // ROSBRIDGE_CLIENT_H
