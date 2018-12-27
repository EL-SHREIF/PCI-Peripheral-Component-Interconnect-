#include "pci.h"
#include <QApplication>


mem DV_A(QString::fromStdString("12FF5823"),QString::fromStdString("33333322"));
mem DV_B(QString::fromStdString("88888888"),QString::fromStdString("00000000"));
mem DV_C(QString::fromStdString("00000000"),QString::fromStdString("28582233"));
int x=3;
bus BUS(x);
//QChart *chart = new QChart();
//QChartView *chartView = new QChartView(chart);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PCI w;
    //====================================================

    //====================================================
    w.show();
    return a.exec();
}
