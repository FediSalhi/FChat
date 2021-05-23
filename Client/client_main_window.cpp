#include "client_main_window.h"
#include "ui_client_main_window.h"
#include <QObject>

ClientMainWindow::ClientMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientMainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(data_received()));
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(connection_established()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(connection_closed()));
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socket_error(QAbstractSocket::SocketError)));

    message_length = 0;
}

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}

void ClientMainWindow::on_connection_pushButton_clicked()
{
   ui->sent_message_textBrowser->append("Trying to connect to the server ...");
   ui->connection_pushButton->setEnabled(false);

   /* abort previous connections if exist */
   socket->abort();
   socket->connectToHost(ui->server_ip_lineEdit->text(), ui->server_port_spinBox->value());
}

void ClientMainWindow::on_send_pushButton_clicked()
{
    QByteArray frame;
    QString message_to_send = "<strong>" + ui->pseudo_lineEdit->text() + "</strong> :   " + ui->message_lineEdit->text();

    QDataStream out(&frame, QIODevice::WriteOnly);
    out << (quint16) 0 ;
    out << message_to_send;
    out.device()->seek(0);
    out << (quint16)(frame.size() - (int)sizeof(quint16));
    socket->write(frame);
    ui->message_lineEdit->clear();
    message_length = 0;

}

void ClientMainWindow::on_message_lineEdit_returnPressed()
{
    on_send_pushButton_clicked();
}

void ClientMainWindow::data_received()
{
    QDataStream in(socket);

    if (socket->bytesAvailable() < (int)sizeof(quint16))
    {
        /* the message length is not completely received */
        return;
    }
    /* message length is received */
    in >> message_length;

    if (socket->bytesAvailable() < message_length)
    {
        /* message is not completely received, wait :( .. */
        return;
    }
    /* if we make to here, it means the message is completely received */
    QString received_message;
    in >> received_message;
    ui->sent_message_textBrowser->append(received_message);

    message_length = 0;
}

void ClientMainWindow::connection_established()
{
    ui->sent_message_textBrowser->append("Successfully connected !");
    ui->connection_pushButton->setEnabled(true);
}

void ClientMainWindow::connection_closed()
{
    ui->sent_message_textBrowser->append("Connection Closed !");
}

void ClientMainWindow::socket_error(QAbstractSocket::SocketError error)
{
    switch (error)
    {
    case QAbstractSocket::HostNotFoundError:
    {
        ui->sent_message_textBrowser->append("Host not found !");
        break;
    }
    case QAbstractSocket::ConnectionRefusedError:
    {
        ui->sent_message_textBrowser->append("Connection refused !");
        break;
    }
    case QAbstractSocket::RemoteHostClosedError:
    {
        ui->sent_message_textBrowser->append("Remote host closed!");
        break;
    }
    default:
    {
        ui->sent_message_textBrowser->append("Error:  " + socket->errorString());
    }

    }

     ui->connection_pushButton->setEnabled(true);
}
