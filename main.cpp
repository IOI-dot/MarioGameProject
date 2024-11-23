#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    // Initialize the Qt application
    MainWindow w;                     // Create an instance of the main window
    w.show();                         // Show the main window

    return app.exec();                // Start the event loop
}
