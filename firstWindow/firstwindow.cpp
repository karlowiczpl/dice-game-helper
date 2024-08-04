#include "firstwindow.h"

FirstWindow::FirstWindow() {
    resize(400, 300);
    show();
    setWindowTitle("Set Game Property");
    setAppearance();

    auto* centralWidget = new QWidget(this);
    auto* pLayout = new QGridLayout;

    centralWidget->setLayout(pLayout);
    layout = new QGridLayout;
    auto* button = new QPushButton("OK");
    pLayout->addLayout(layout , 1 , 1);
    pLayout->addWidget(button);

    numberBox = new QSpinBox;
    pLayout->addWidget(numberBox);

    setCentralWidget(centralWidget);
    numberBox->setMaximum(9);

    connect(numberBox , &QSpinBox::textChanged , this , &FirstWindow::numberChanged);
    connect(button , &QPushButton::clicked , this , &FirstWindow::ready);
}
void FirstWindow::numberChanged()
{
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr)
    {
        QWidget* widget = item->widget();
        if(widget)
        {
            widget->deleteLater();
        }
        delete item;
    }

    for(int i = 0; i < numberBox->text().toInt(); i++)
    {
        auto* line = new QLineEdit;
        layout->addWidget(line);
        names.push_back(line);
    }

}

void FirstWindow::ready()
{
    personNames.clear();
    personNames.push_back("");
    for (auto & name : names) {
        personNames.push_back(name->text());
    }

    auto* window1 = new MainWindow((int)names.size() , personNames);
    window1->show();
    this->close();
}
