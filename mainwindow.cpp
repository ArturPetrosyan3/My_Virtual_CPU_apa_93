#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ram.h"
#include "cpu.h"
#include <QDataStream>
#include "programloader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    RAM *myRam = new RAM();

    myRam->Write(0,QByteArray::number(535));

    //qDebug() << myRam->Read(1);


//    myRam->Write(2,QByteArray::number(5));
//    myRam->Write(5,QByteArray::number(7));
//    qDebug() << myRam->Read(3);
//    qDebug() << myRam->Read(5);

//    CPU *MyCpu = new CPU(myRam);

//   // qDebug() << "run";
//    //MyCpu->Execute();
//    //qDebug() << "complite";
//    QString PathToInput = "C:\\Users\\Arturp.SYNOPSYS\\Documents\\My_Virtual_CPU_apa_93\\My_Virtual_CPU_apa_93\\sum.asm";//QDir::currentPath();
//    //PathToInput.append("/sum.asm");

//    ProgramLoader Prog(myRam, 2);

//    Prog.loadFile(PathToInput);


//    MyCpu->Execute();

}

MainWindow::~MainWindow()
{
    delete ui;
}
