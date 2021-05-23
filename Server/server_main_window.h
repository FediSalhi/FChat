#ifndef SERVER_MAIN_WINDOW_H
#define SERVER_MAIN_WINDOW_H

#include <QWidget>
#include <QTcpServer>
#include <QObject>

namespace Ui {
class ServerMainWindow;
}

class ServerMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ServerMainWindow(QWidget *parent = 0);
    ~ServerMainWindow();
    void send_to_all(const QString& message);

private:
    Ui::ServerMainWindow *ui;

private slots:
    void new_connection();
    void data_received();
    void client_disconnected();

private:
    QTcpServer* server;
    QList<QTcpSocket*> clients;
    quint16 message_length;

};

#endif // SERVER_MAIN_WINDOW_H
