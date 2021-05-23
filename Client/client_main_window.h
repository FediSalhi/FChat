#ifndef CLIENT_MAIN_WINDOW_H
#define CLIENT_MAIN_WINDOW_H

#include <QtWidgets>
#include <QtNetwork>


namespace Ui {
class ClientMainWindow;
}

class ClientMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ClientMainWindow(QWidget *parent = 0);
    ~ClientMainWindow();

private slots:
    void on_connection_pushButton_clicked();
    void on_send_pushButton_clicked();
    void on_message_lineEdit_returnPressed();
    void data_received();
    void connection_established();
    void connection_closed();
    void socket_error(QAbstractSocket::SocketError error);


private:
    Ui::ClientMainWindow *ui;
    QTcpSocket* socket;
    quint16 message_length;
};

#endif // CLIENT_MAIN_WINDOW_H
