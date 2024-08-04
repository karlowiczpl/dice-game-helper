#ifndef KOCI_OBJECT_H
#define KOCI_OBJECT_H

#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>

class MainWindow;

namespace type
{
    enum
    {
        school,
        dual,
        tree,
        onlyLabel,
        onlyLine
    };
}

class Object : public QWidget {
Q_OBJECT
public:
    Object(int type , QGridLayout* mainLayout , int row , int col);
    Object();
    int getValue();
    void setValue(int value);

private:
    static void addItems(QComboBox* box , bool zero , bool null , int maxNumber);
    static void addMultipleItem(QComboBox* box ,bool street);

    int classmate{};
    int value{};
    QComboBox* boxes[3]{};
    QLabel* label{};
    QLineEdit* lineEdit{};

//    MainWindow

private slots:
    static void changedValue() ;
};

#endif //KOCI_OBJECT_H
