#include <QApplication>

#include "firstWindow/firstwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FirstWindow f1;

    return QApplication::exec();
}
