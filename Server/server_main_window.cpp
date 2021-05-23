#include "server_main_window.h"
#include "ui_server_main_window.h"
#include <QTcpSocket>
#include <QDataStream>

ServerMainWindow::ServerMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerMainWindow)
{
    ui->setupUi(this);


    /* server */
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::Any, 50885))
    {
        ui->server_status_textBrowser->setText("Server cannot be started: " + server->errorString());
    }
    else
    {
        ui->server_status_textBrowser->setText("Server is started in port <strong>" + QString::number(server->serverPort()) +
                                               " </strong> clients can now be connected");
        QObject::connect(server, SIGNAL(newConnection()), this, SLOT(new_connection()));
    }

    message_length = 0;




    /* all connections are here, no connection is built using Qt designer */
    QObject::connect(ui->quit_pushButton, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

ServerMainWindow::~ServerMainWindow()
{
    delete ui;
}

void ServerMainWindow::new_connection()
{
    send_to_all("A new connection established");
    QTcpSocket* new_client = server->nextPendingConnection();
    clients << new_client;

    QObject::connect(new_client, SIGNAL(readyRead()), this, SLOT(data_received()));
    QObject::connect(new_client, SIGNAL(disconnected()), this, SLOT(client_disconnected()));

}

void ServerMainWindow::send_to_all(const QString &message)
{
    QByteArray frame;
    QDataStream out(&frame, QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);
    out << (quint16)(frame.size() - sizeof(quint16));

    /* send frame to all client connected to the server */
    for (int i = 0; i<clients.size(); i++)
    {
        clients[i]->write(frame);
    }
}

void ServerMainWindow::data_received()
{
    QTcpSocket* socket= qobject_cast<QTcpSocket*>(sender());
    if (!socket)
    {
        return;
    }
    QDataStream in(socket);

    if (message_length == 0)
    {
        /* message length is not already captured */
        if (socket->bytesAvailable() < ((int)sizeof(quint16)))
        {
            return;
        }

        in >> message_length;
    }
    if (socket->bytesAvailable() < message_length)
    {
        return;
    }

    QString message;
    in >> message;

    send_to_all(message);
    message_length = 0;

}

void ServerMainWindow::client_disconnected()
{
    send_to_all("A client is disconnected");

    /* let's determine which client is disconnected */
    QTcpSocket* socket = qobject_cast<QTcpSocket* >(sender());
    if (!socket)
    {
        return;
    }

    /* remove the socket from the list of clients */
    clients.removeOne(socket);

    /* destroy the socket */
    socket->deleteLater();

}
