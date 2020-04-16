#include "tspsom.h"
#include "ui_tspsom.h"
#include <QVector>

TspSom::TspSom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TspSom)
    , citiesMap()
{
    ui->setupUi(this);

    //Setting up the plotting area
    ui->graph_qcustomplot->xAxis->setRange(0,1);
    ui->graph_qcustomplot->yAxis->setRange(0,1);

    ui->graph_qcustomplot->addGraph(); //Cities (dots)
    ui->graph_qcustomplot->addGraph(); //The som curve

    ui->graph_qcustomplot->graph(0)->setLineStyle(QCPGraph::lsNone); //Dots
    ui->graph_qcustomplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 7));

}

TspSom::~TspSom()
{
    delete ui;
}


/**
 * @brief TspSom::generateMapClicked Qt Slot that handless the "generate map" -button press.
 * Generates the appropriate amount of cites.
 */
void TspSom::generateMapClicked()
{
    int numberOfCities = ui->cities_spinBox->value();
    citiesMap.Initialize(numberOfCities);

    QVector<double> x = citiesMap.getXaxis();
    QVector<double> y = citiesMap.getYaxis();

    ui->graph_qcustomplot->graph(0)->setData(x, y);
    ui->graph_qcustomplot->replot();
}
