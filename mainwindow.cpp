#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ram.h"

#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QByteArray baData;
    QString str;


    str = "4dgdfgdfgdfgdfgdsfgsdfg";

    baData.insert(0, str.toLocal8Bit());
    baData.resize(str.size());


    qDebug() << baData;

    RAM *myRam = new RAM();
    myRam->Write(2,baData);

    qDebug() << myRam->Read(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
