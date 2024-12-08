#include <QApplication>
#include "start.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    // Initialize the Qt application
    START startDialog;               // Create an instance of the START dialog
    startDialog.show();              // Show the START dialog as the first screen

    return app.exec();               // Start the event loop
}
