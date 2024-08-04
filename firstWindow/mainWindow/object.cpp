#include "object.h"
#include "mainwindow.h"

Object::Object(int typ , QGridLayout* mainLayout , int row , int col)   :
        classmate(row)
{
    auto* layout = new QGridLayout;
    mainLayout->addLayout(layout , row , col);
    auto* comboBox = new QComboBox;
    auto* comboBox1 = new QComboBox;
    boxes[0] = comboBox;
    boxes[1] = comboBox1;
    classmate = row;
    if(typ == type::school)
    {
        layout->addWidget(comboBox , 0 , 0);
        layout->addWidget(comboBox1 , 0 , 1);
        addItems(comboBox , true, true, 5);
        addMultipleItem(comboBox1, false);
    }else if(typ == type::dual)
    {
        layout->addWidget(comboBox, 0, 0);
        layout->addWidget(comboBox1, 0, 1);
        addItems(comboBox , false, true, 6);
        addMultipleItem(comboBox1, false);
    }else if(typ == type::tree)
    {
        auto* comboBox2 = new QComboBox;
        layout->addWidget(comboBox,  0, 0);
        layout->addWidget(comboBox1, 0, 1);
        layout->addWidget(comboBox2, 0, 2);
        addItems(comboBox ,  false, true, 6);
        addItems(comboBox1 , false, true, 6);
        addMultipleItem(comboBox2, false);
        boxes[2] = comboBox2;
        connect(comboBox2 , QOverload<int>::of(&QComboBox::currentIndexChanged) , []()
        {
            changedValue();
        });
    }else if(typ == type::onlyLabel)
    {
        layout->addWidget(comboBox);
        addMultipleItem(comboBox, true);
    }else if(typ == type::onlyLine)
    {
        auto* line = new QLineEdit;
        layout->addWidget(line);
        lineEdit = line;
    }else
    {
        auto* la = new QLabel("0");
        layout->addWidget(la);
        label = la;
    }
    if(typ >= type::school && typ <= type::onlyLabel)
    {
        connect(comboBox , QOverload<int>::of(&QComboBox::currentIndexChanged) , []()
        {
            changedValue();
        });
        connect(comboBox1 , QOverload<int>::of(&QComboBox::currentIndexChanged) , []()
        {
            changedValue();
        });
    }

}

void Object::addItems(QComboBox *box, bool zero, bool null, int maxNumber)
{
    if (null)    box->addItem("");
    if (zero)    box->addItem("0");
    for (int i = 1; i < maxNumber + 1; i++)
    {
        box->addItem(QString::number(i));
    }
}

void Object::addMultipleItem(QComboBox* box ,bool street)
{
    if (street)  box->addItem("");
    box->addItem("X1");
    box->addItem("X2");
    box->addItem("x");
}

int Object::getValue()
{
    int multiple = 1;
    if(classmate <= 6 && boxes[1]->currentText() != "x" && boxes[1]->currentText() != "")
    {
        int x = 0;
        if(boxes[1]->currentText() == "X2")     multiple = 2;
        if(boxes[0]->currentText() == "0")      x = -3;
        else if(boxes[0]->currentText() == "1")      x = -2;
        else if(boxes[0]->currentText() == "2")      x = -1;
        else if(boxes[0]->currentText() == "4")      x = 1;
        else if(boxes[0]->currentText() == "5")      x = 2;

        return x * classmate * multiple;
    }else if(classmate == 7 && boxes[1]->currentText() != "x"&& boxes[1]->currentText() != "")
    {
        if(boxes[1]->currentText() == "X2")     multiple = 2;
        return boxes[0]->currentIndex() * 2 * multiple;
    }else if(classmate == 8 && boxes[2]->currentText() != "x" && boxes[2]->currentText() != "")
    {
        if(boxes[2]->currentText() == "X2")     multiple = 2;
        return (boxes[0]->currentText().toInt() * 2 + boxes[1]->currentText().toInt() * 2) * multiple;
    }else if(classmate == 9 && boxes[1]->currentText() != "x" && boxes[1]->currentText() != "")
    {
        if(boxes[1]->currentText() == "X2")     multiple = 2;
        return boxes[0]->currentText().toInt() * 3 * multiple;
    }else if(classmate == 10 && boxes[0]->currentText() != "x" && boxes[0]->currentText() != "")
    {
        if(boxes[0]->currentText() == "X2")     multiple = 2;
        return 15 * multiple;
    }else if(classmate == 11 && boxes[0]->currentText() != "x" && boxes[0]->currentText() != "")
    {
        if(boxes[0]->currentText() == "X2")     multiple = 2;
        return 20 * multiple;
    }else if(classmate == 12 && boxes[2]->currentText() != "x"&& boxes[2]->currentText() != "")
    {
        if (boxes[2]->currentText() == "X2") multiple = 2;
        return (boxes[0]->currentText().toInt() * 3 + boxes[1]->currentText().toInt() * 2) * multiple;
    }else if(classmate == 13 && boxes[1]->currentText() != "x" && boxes[1]->currentText() != "")
    {
        if(boxes[1]->currentText() == "X2")     multiple = 2;
        return boxes[0]->currentText().toInt() * 5 * multiple;
    }else if(classmate == 14 && boxes[1]->currentText() != "x" && boxes[1]->currentText() != "")
    {
        if(boxes[1]->currentText() == "X2")     multiple = 2;
        return boxes[0]->currentText().toInt() * 4 * multiple;
    }else if(classmate == 15)
    {
        return lineEdit->text().toInt();
    }
    return 0;
}

void Object::changedValue()
{
    MainWindow::calculate();
}

void Object::setValue(int val)
{
    label->setText(QString::number(val));
}
