#ifndef KOCI_MAINWINDOW_H
#define KOCI_MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QDebug>
#include <vector>
#include <memory>
#include <utility>

#include "object.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(int sizeOfPerson, QStringList  personNames, QWidget *parent = nullptr);

public:
    [[maybe_unused]] static void calculate();

private:
    int sizeOfPerson;
    QStringList persons;

    QWidget *centralWidget;
    QGridLayout *mainLayout;

    static std::shared_ptr<MainWindow> staticClass;
    static void setStaticInstance(MainWindow* ptr);

    typedef struct
    {
        std::vector<Object*> obj;
    }OBJ_T;
    OBJ_T* object;

    int prefix[16] = { 0 , 0 , 0 , 0 , 0 , 0,
                       1 , 2 , 1 , 3 , 3 , 2,
                       1 , 1 , 4 , 5};

    QString spaces[17] = {"", "1", "2", "3", "4", "5",
                          "6", "para", "dwie pary", "trójka",
                          "mały street", "duży street", "full",
                          "kareta", "poker", "szansa", "suma"};

};

#endif // KOCI_MAINWINDOW_H
