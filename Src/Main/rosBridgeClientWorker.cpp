// rosbridge_client_worker.cpp
#include "rosBridgeClientWorker.h"
#include <QDebug>

ROSBridgeClientWorker::ROSBridgeClientWorker(QObject *parent)
    : QObject(parent), socket_(new QWebSocket())
{
    // 移动 socket 到工作线程
    workerThread_ = new QThread();
    socket_->moveToThread(workerThread_);

    // 连接信号和槽
    connect(socket_, &QWebSocket::connected, this, &ROSBridgeClientWorker::onConnected);
    connect(socket_, &QWebSocket::disconnected, this, &ROSBridgeClientWorker::onDisconnected);
    connect(socket_, &QWebSocket::textMessageReceived, this, &ROSBridgeClientWorker::onMessageReceived);
    connect(socket_, &QWebSocket::errorOccurred, this, &ROSBridgeClientWorker::onErrorOccurred);
}

ROSBridgeClientWorker::~ROSBridgeClientWorker()
{
    socket_->deleteLater();
    workerThread_->quit();
    workerThread_->wait();
    delete workerThread_;
}

void ROSBridgeClientWorker::connectToServer(const QUrl &url)
{
    socket_->open(url);
    workerThread_->start();
}

void ROSBridgeClientWorker::sendMessage(const QJsonObject &message)
{
    if (socket_->state() == QAbstractSocket::ConnectedState) {
        QJsonDocument doc(message);
        socket_->sendTextMessage(doc.toJson(QJsonDocument::Compact));
    } else {
        emit errorOccurred("WebSocket is not connected.");
    }
}

void ROSBridgeClientWorker::onConnected()
{
    qDebug() << "Connected to WebSocket server";
    emit connected();
}

void ROSBridgeClientWorker::onDisconnected()
{
    qDebug() << "Disconnected from WebSocket server";
    emit disconnected();
}

void ROSBridgeClientWorker::onMessageReceived(const QString &message)
{
    qDebug() << "Message received: " << message;
    emit messageReceived(message);
}

void ROSBridgeClientWorker::onErrorOccurred(QAbstractSocket::SocketError error)
{
    qDebug() << "Error occurred: " << socket_->errorString();
    emit errorOccurred(socket_->errorString());
}
