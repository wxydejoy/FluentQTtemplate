// rosbridge_client_worker.h
#ifndef ROSBRIDGECLIENTWORKER_H
#define ROSBRIDGECLIENTWORKER_H

#include <QObject>
#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QThread>

class ROSBridgeClientWorker : public QObject
{
    Q_OBJECT

public:
    explicit ROSBridgeClientWorker(QObject *parent = nullptr);
    ~ROSBridgeClientWorker();

    void connectToServer(const QUrl &url);
    void sendMessage(const QJsonObject &message);

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

private:
    QWebSocket *socket_;
    QThread *workerThread_;
};

#endif // ROSBRIDGE_CLIENT_WORKER_H
