#include <QApplication>
#include "server_main_window.h"

int main(int argc, char* argv[])
{

    QApplication server_app(argc, argv);

    ServerMainWindow server_main_window;
    server_main_window.show();

    return server_app.exec();

}
