#include "mainwindow.h"

std::shared_ptr<MainWindow> MainWindow::staticClass = nullptr;

MainWindow::MainWindow(int sizeOfPerson, QStringList personNames, QWidget *parent)
        : QMainWindow(parent), sizeOfPerson(sizeOfPerson), persons(std::move(personNames)) {

    resize(1000, 600);
    show();

    static OBJ_T objT[3];
    object = objT;

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    setWindowTitle("Kości");


    MainWindow::setStaticInstance(this);

    mainLayout = new QGridLayout(centralWidget);

    for(int i = 0; i < 17; i++)
    {
        auto* label = new QLabel(spaces[i]);
        mainLayout->addWidget(label , i , 0);
    }
    for(int i = 0; i < sizeOfPerson + 1; i++)
    {
        auto* label = new QLabel(persons[i]);
        mainLayout->addWidget(label , 0 , i);
    }
    for(int col = 1; col < sizeOfPerson + 1; ++col)
    {

        for(int row = 1 ; row < 17; row++)
        {
            auto* obj = new Object(prefix[row - 1] , mainLayout , row , col);
            object[col - 1].obj.push_back(obj);
        }
    }
}

[[maybe_unused]] void MainWindow::calculate() {
    int suma[staticClass->sizeOfPerson];
    for(int i = 0; i < staticClass->sizeOfPerson; i++)   suma[i] = 0;
    for(int x = 0; x < staticClass->sizeOfPerson; x++)
    {
        for(int i = 0; i < 16; i++)
        {
            suma[x] += staticClass->object[x].obj[i]->getValue();
        }
        staticClass->object[x].obj[15]->setValue(suma[x]);
    }
}
void MainWindow::setStaticInstance(MainWindow *ptr)
{
    staticClass = std::shared_ptr<MainWindow>(ptr, [](MainWindow*) {
    });
}