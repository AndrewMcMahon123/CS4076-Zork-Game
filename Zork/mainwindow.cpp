#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Owner/OneDrive/Documents/Zork/images/blank_key.png");

    ui ->ivn_1->setPixmap(pix);
    ui->ivn_1->setScaledContents(true);

    ui ->ivn_2->setPixmap(pix);
    ui->ivn_2->setScaledContents(true);

    ui ->ivn_3->setPixmap(pix);
    ui->ivn_3->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//buttons for UI to be added here
