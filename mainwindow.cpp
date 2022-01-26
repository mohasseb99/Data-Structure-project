#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "algorithms.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbPlot_clicked()
{
    /* boolean values of all checkboxes */
    bool insertion = ui->CBInsertion->isChecked();
    bool merge = ui->CBMerge->isChecked();
    bool heap = ui->CBHeap->isChecked();
    bool quick = ui->CBQuick->isChecked();
    bool counting = ui->CBCounting->isChecked();
    bool radix = ui->CBRadix->isChecked();
    bool insertionAsm = ui->CBInsertionAsm->isChecked();
    bool mergeAsm = ui->CBMergeAsm->isChecked();
    bool heapAsm = ui->CBHeapAsm->isChecked();
    bool quickAsm = ui->CBQuickAsm->isChecked();
    bool countingAsm = ui->CBCountingAsm->isChecked();
    bool radixAsm = ui->CBRadixAsm->isChecked();

    /* if user does not choose any option */
    if((!insertion) && (!merge) && (!heap) && (!quick) && (!counting) && (!radix) && (!insertionAsm) && (!mergeAsm) &&
            (!heapAsm) && (!quickAsm) && (!countingAsm) && (!radixAsm)){
        QMessageBox::critical(this, "Plot", "Please select at least one!");
        //qDebug() << size << " " << step;
        return;
    }

    QMessageBox::information(this, "Plot", "wait for processing");

    /* take size value from text edit and convert to int */
    QString STRsize = ui->TESize->toPlainText();
    int size = STRsize.toInt();

    /* take step value from text edit and convert to int */
    QString STRstep = ui->TEStep->toPlainText();
    int step = STRstep.toInt();

    writeRandomNumbersToFile(size);

    /* to make x axis */
    vector<int> x;
    for(int i = 1; i <= size; i+=step){
        x.push_back(i);
    }

    vector<int> y1;
    vector<int> y2;
    vector<int> y3;
    vector<int> y4;
    vector<int> y5;
    vector<int> y6;
    int n = 0;
    /* to make y*/
    if(insertion){
        y1 = selectInsertion(size, step);
        QVector<double> xPlot(x.size()), y1Plot(y1.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y1Plot[i] = y1[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::blue));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y1Plot);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(merge) {
        y2 = selectMerge(size, step);
        QVector<double> xPlot(x.size()), y2Plot(y2.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y2Plot[i] = y2[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::red));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y2Plot);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(heap) {
        y3 = selectHeap(size, step);
        QVector<double> xPlot(x.size()), y3Plot(y3.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y3Plot[i] = y3[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::green));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y3Plot);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(quick) {
        y4 = selectQuick(size, step);
        QVector<double> xPlot(x.size()), y4Plot(y4.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y4Plot[i] = y4[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::yellow));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y4Plot);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(counting) {
        y5 = selectCounting(size, step);
        QVector<double> xPlot(x.size()), y5Plot(y5.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y5Plot[i] = y5[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::cyan));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y5Plot);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(radix) {
        y6 = selectRadix(size, step);
        QVector<double> xPlot(x.size()), y6Plot(y6.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y6Plot[i] = y6[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::magenta));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y6Plot);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }


    vector<int> asm_Insertion;
    vector<int> asm_Merge;
    vector<int> asm_Heap;
    vector<int> asm_Quick;
    vector<int> asm_Counting;
    vector<int> asm_Radix;
    /* to make y */
    if(insertionAsm) {
        asm_Insertion = asymptoticInsertion(size, step);
        QVector<double> xPlot(x.size()), y1Asm(asm_Insertion.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y1Asm[i] = asm_Insertion[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::darkBlue));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y1Asm);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(mergeAsm) {
        asm_Merge = asymptoticMerge(size, step);
        QVector<double> xPlot(x.size()), y2Asm(asm_Merge.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y2Asm[i] = asm_Merge[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::darkRed));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y2Asm);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(heapAsm) {
        asm_Heap = asymptoticHeap(size, step);
        QVector<double> xPlot(x.size()), y3Asm(asm_Heap.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y3Asm[i] = asm_Heap[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::darkGreen));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y3Asm);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(quickAsm) {
        asm_Quick = asymptoticQuick(size, step);
        QVector<double> xPlot(x.size()), y4Asm(asm_Quick.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y4Asm[i] = asm_Quick[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::darkYellow));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y4Asm);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(countingAsm) {
        asm_Counting = asymptoticCounting(size, step);
        QVector<double> xPlot(x.size()), y5Asm(asm_Counting.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y5Asm[i] = asm_Counting[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::darkCyan));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y5Asm);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
    if(radixAsm) {
        asm_Radix = asymptoticRadix(size, step);
        QVector<double> xPlot(x.size()), y6Asm(asm_Radix.size());
        for (int i=0; i<xPlot.size(); ++i)
        {
          xPlot[i] = x[i];
          y6Asm[i] = asm_Radix[i];
        }
        ui->wPlot->addGraph();
        ui->wPlot->graph(n)->setPen(QPen(Qt::darkMagenta));
        ui->wPlot->xAxis->setLabel("size");
        ui->wPlot->yAxis->setLabel("Steps");
        ui->wPlot->graph(n)->setData(xPlot, y6Asm);
        ui->wPlot->graph(n)->rescaleAxes(true);
        ui->wPlot->replot();
        n++;
    }
}

