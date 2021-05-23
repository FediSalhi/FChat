/********************************************************************************
** Form generated from reading UI file 'client_main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_MAIN_WINDOW_H
#define UI_CLIENT_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientMainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *server_ip_label;
    QLineEdit *server_ip_lineEdit;
    QLabel *server_port_label;
    QSpinBox *server_port_spinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *connection_pushButton;
    QTextBrowser *sent_message_textBrowser;
    QHBoxLayout *horizontalLayout;
    QLabel *pseudo_label;
    QLineEdit *pseudo_lineEdit;
    QLabel *message_label;
    QLineEdit *message_lineEdit;
    QPushButton *send_pushButton;

    void setupUi(QWidget *ClientMainWindow)
    {
        if (ClientMainWindow->objectName().isEmpty())
            ClientMainWindow->setObjectName(QStringLiteral("ClientMainWindow"));
        ClientMainWindow->resize(601, 448);
        verticalLayout = new QVBoxLayout(ClientMainWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        server_ip_label = new QLabel(ClientMainWindow);
        server_ip_label->setObjectName(QStringLiteral("server_ip_label"));

        horizontalLayout_2->addWidget(server_ip_label);

        server_ip_lineEdit = new QLineEdit(ClientMainWindow);
        server_ip_lineEdit->setObjectName(QStringLiteral("server_ip_lineEdit"));

        horizontalLayout_2->addWidget(server_ip_lineEdit);

        server_port_label = new QLabel(ClientMainWindow);
        server_port_label->setObjectName(QStringLiteral("server_port_label"));

        horizontalLayout_2->addWidget(server_port_label);

        server_port_spinBox = new QSpinBox(ClientMainWindow);
        server_port_spinBox->setObjectName(QStringLiteral("server_port_spinBox"));
        server_port_spinBox->setMaximum(60000);

        horizontalLayout_2->addWidget(server_port_spinBox);

        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_2->addItem(verticalSpacer);

        connection_pushButton = new QPushButton(ClientMainWindow);
        connection_pushButton->setObjectName(QStringLiteral("connection_pushButton"));

        horizontalLayout_2->addWidget(connection_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        sent_message_textBrowser = new QTextBrowser(ClientMainWindow);
        sent_message_textBrowser->setObjectName(QStringLiteral("sent_message_textBrowser"));

        verticalLayout->addWidget(sent_message_textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pseudo_label = new QLabel(ClientMainWindow);
        pseudo_label->setObjectName(QStringLiteral("pseudo_label"));

        horizontalLayout->addWidget(pseudo_label);

        pseudo_lineEdit = new QLineEdit(ClientMainWindow);
        pseudo_lineEdit->setObjectName(QStringLiteral("pseudo_lineEdit"));
        pseudo_lineEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(pseudo_lineEdit);

        message_label = new QLabel(ClientMainWindow);
        message_label->setObjectName(QStringLiteral("message_label"));

        horizontalLayout->addWidget(message_label);

        message_lineEdit = new QLineEdit(ClientMainWindow);
        message_lineEdit->setObjectName(QStringLiteral("message_lineEdit"));

        horizontalLayout->addWidget(message_lineEdit);

        send_pushButton = new QPushButton(ClientMainWindow);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));

        horizontalLayout->addWidget(send_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ClientMainWindow);

        QMetaObject::connectSlotsByName(ClientMainWindow);
    } // setupUi

    void retranslateUi(QWidget *ClientMainWindow)
    {
        ClientMainWindow->setWindowTitle(QApplication::translate("ClientMainWindow", "FChat - Client", Q_NULLPTR));
        server_ip_label->setText(QApplication::translate("ClientMainWindow", "Server IP : ", Q_NULLPTR));
        server_port_label->setText(QApplication::translate("ClientMainWindow", "Server Port", Q_NULLPTR));
        connection_pushButton->setText(QApplication::translate("ClientMainWindow", "Connect", Q_NULLPTR));
        pseudo_label->setText(QApplication::translate("ClientMainWindow", "Pseudo : ", Q_NULLPTR));
        pseudo_lineEdit->setInputMask(QString());
        pseudo_lineEdit->setText(QString());
        pseudo_lineEdit->setPlaceholderText(QString());
        message_label->setText(QApplication::translate("ClientMainWindow", "Message : ", Q_NULLPTR));
        send_pushButton->setText(QApplication::translate("ClientMainWindow", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientMainWindow: public Ui_ClientMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_MAIN_WINDOW_H
