#include "client_main_window.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication client_app(argc, argv);
    ClientMainWindow client_main_window;
    client_main_window.show();


    return client_app.exec();
}
