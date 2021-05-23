/********************************************************************************
** Form generated from reading UI file 'server_main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_MAIN_WINDOW_H
#define UI_SERVER_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerMainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *server_status_textBrowser;
    QPushButton *quit_pushButton;

    void setupUi(QWidget *ServerMainWindow)
    {
        if (ServerMainWindow->objectName().isEmpty())
            ServerMainWindow->setObjectName(QStringLiteral("ServerMainWindow"));
        ServerMainWindow->resize(411, 119);
        verticalLayout = new QVBoxLayout(ServerMainWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        server_status_textBrowser = new QTextBrowser(ServerMainWindow);
        server_status_textBrowser->setObjectName(QStringLiteral("server_status_textBrowser"));

        verticalLayout->addWidget(server_status_textBrowser);

        quit_pushButton = new QPushButton(ServerMainWindow);
        quit_pushButton->setObjectName(QStringLiteral("quit_pushButton"));

        verticalLayout->addWidget(quit_pushButton);


        retranslateUi(ServerMainWindow);

        QMetaObject::connectSlotsByName(ServerMainWindow);
    } // setupUi

    void retranslateUi(QWidget *ServerMainWindow)
    {
        ServerMainWindow->setWindowTitle(QApplication::translate("ServerMainWindow", "FChat - Server", Q_NULLPTR));
        quit_pushButton->setText(QApplication::translate("ServerMainWindow", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerMainWindow: public Ui_ServerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_MAIN_WINDOW_H
