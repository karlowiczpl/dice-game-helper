#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QSpinBox>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QStringList>
#include <QPalette>

#include "mainWindow/mainwindow.h"

class FirstWindow : public QMainWindow {
Q_OBJECT

public:
    FirstWindow();
    void setAppearance();

private:
    QGridLayout* layout;
    QSpinBox* numberBox;
    std::vector<QLineEdit*> names;
    QStringList personNames;

private slots:
    void numberChanged();
    void ready();
};

#endif // FIRSTWINDOW_H
