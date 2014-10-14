#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "PaintOutput.h"

#include "TestPainter.h"

MainWindow::MainWindow(QWidget *iParent):
    QWidget(iParent)
{
    QWidget *parent = this;
    QHBoxLayout *hblayout = new QHBoxLayout(parent);
    QPushButton *bt0, *bt1;
    QWidget *leftWidget = new QWidget(parent);
    hblayout->addWidget(leftWidget);
    {
        QWidget *parent = leftWidget;
        QVBoxLayout *vlay = new QVBoxLayout(parent);
        vlay->addWidget(new QPushButton("Button 2", parent));
        vlay->addWidget(new QPushButton("Button 3", parent));
    }
    TestPainter *_painter = new TestPainter(parent);
    hblayout->addWidget(_painter);
    hblayout->addWidget(bt0 = new QPushButton("Button 0", parent));
    hblayout->addWidget(bt1 = new QPushButton("Button 1", parent));
    hblayout->addWidget(new PaintOutput(parent));

    connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click()));
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Button0 was clicked");
}

MainWindow::~MainWindow()
{
}
