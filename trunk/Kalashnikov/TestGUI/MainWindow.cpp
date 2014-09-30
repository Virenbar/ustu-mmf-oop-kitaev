#include "MainWindow.h"
#include <QHBoxLayout> // диспетчер горизонталь
#include <QVBoxLayout> // диспетчер вертикаль
#include <QPushButton>

#include <paintoutput.h>

MainWindow::MainWindow(QWidget *iParent):
    QWidget(iParent)
{
    QWidget *parent = this;

    QHBoxLayout *hblayout = new QHBoxLayout(this); // this - тип main windows *
    QPushButton *bt0, *bt1;

    QWidget *topWidget = new QWidget(parent);

    hblayout->addWidget(topWidget);
    {
        QWidget *parent = topWidget;
        QVBoxLayout *vlay = new QVBoxLayout (parent);
        vlay->addWidget(new QPushButton("Button 2", parent));
        vlay->addWidget(new QPushButton("Button 3", parent));
    }
    //Добавим в диспетчер размещений родителем будет окошечко.
    // кнопки

    hblayout->addWidget(bt0 = new QPushButton("Кнопка 0", this));
    hblayout->addWidget(bt1 = new QPushButton("Кнопка 1", this));
    hblayout->addWidget();

    connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click())); //отправитель, какой сигнал, куда
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Button 0 was click");
}

MainWindow::~MainWindow()
{
}
