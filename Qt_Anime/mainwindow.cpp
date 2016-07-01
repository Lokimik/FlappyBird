#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->anime = new Anime(this);

    this->setFixedSize(540,960);

    this->showButton = new QPushButton(this);
    this->showButton->setGeometry(QRect(this->width()/2-50,this->height()/2+400,100,50));
    this->increaseCircleButton = new QPushButton("+",this);
    this->increaseCircleButton->setGeometry(QRect(this->width()/2-150,this->height()/2+250,100,50));
    this->decreaseCircleButton = new QPushButton("-",this);
    this->decreaseCircleButton->setGeometry(QRect(this->width()/2+50,this->height()/2+250,100,50));
    this->increaseLineButton = new QPushButton("+",this);
    this->increaseLineButton->setGeometry(QRect(this->width()/2-150,this->height()/2+320,100,50));
    this->decreaseLineButton = new QPushButton("-",this);
    this->decreaseLineButton->setGeometry(QRect(this->width()/2+50,this->height()/2+320,100,50));

    connect(this->showButton,SIGNAL(clicked()),this->anime,SLOT(show()));
    connect(this->increaseCircleButton,SIGNAL(clicked()),this->anime,SLOT(increaseCircle()));
    connect(this->decreaseCircleButton,SIGNAL(clicked()),this->anime,SLOT(decreaseCircle()));
    connect(this->increaseLineButton,SIGNAL(clicked()),this->anime,SLOT(increaseLine()));
    connect(this->decreaseLineButton,SIGNAL(clicked()),this->anime,SLOT(decreaseLine()));
}

MainWindow::~MainWindow()
{

}
