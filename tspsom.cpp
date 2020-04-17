#include "tspsom.h"
#include "ui_tspsom.h"
#include <QVector>
#include <QVariant>

TspSom::TspSom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TspSom)
    , citiesMap()
    , som()
{
    ui->setupUi(this);

    //Setting up the plotting area
    ui->graph_qcustomplot->xAxis->setRange(0,1);
    ui->graph_qcustomplot->yAxis->setRange(0,1);



    //Citites graph configuration
    ui->graph_qcustomplot->addGraph();
    ui->graph_qcustomplot->graph(0)->setLineStyle(QCPGraph::lsNone); //Dots
    ui->graph_qcustomplot->graph(0)->setPen(QPen(Qt::black)); //Color black
    ui->graph_qcustomplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssStar, 10)); //Stars

    //SOM graph configuration (a graph with loops needs to be defined as QCPCurve)
    //Qcustomplot takes ownership of the new curve so no direct managing is required.
    somCurve = new QCPCurve(ui->graph_qcustomplot->xAxis, ui->graph_qcustomplot->yAxis);
    somCurve->setPen(QPen(Qt::blue)); //color blue
    somCurve->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3)); //Filled circles


    //Populate combobox
    ui->initialization_comboBox->addItem("Circular", QVariant(true));
    ui->initialization_comboBox->addItem("Random", QVariant(false));
}

TspSom::~TspSom()
{
    delete ui;
}


/**
 * @brief TspSom::generateMapClicked Qt Slot that handless the "generate map" -button click.
 * Generates the appropriate amount of cites.
 */
void TspSom::generateMapClicked()
{
    int numberOfCities = ui->cities_spinBox->value();
    citiesMap.InitializeRandom(numberOfCities);

    QVector<double> x = citiesMap.getXaxis();
    QVector<double> y = citiesMap.getYaxis();

    ui->graph_qcustomplot->graph(0)->setData(x, y);
    ui->graph_qcustomplot->replot();
}

/**
 * @brief TspSom::initializeSOM_clicked Qt slot that handles the "Initialize SOM" -button click.
 * Initializes the SOM according to parmeters in form.
 */
void TspSom::initializeSOM_clicked()
{
    bool initMode = ui->initialization_comboBox->currentData().toBool();
    int nodes = ui->nodes_spinBox->value();

    if (!initMode) {
        som.InitializeRandom(nodes);
    }else {
        som.InitializeCircular(nodes);
    }

    QVector<double> x = som.getXaxis();
    QVector<double> y = som.getYaxis();

    somCurve->setData(x, y);
    ui->graph_qcustomplot->replot();
}
