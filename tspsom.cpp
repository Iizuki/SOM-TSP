#include "tspsom.h"
#include "ui_tspsom.h"
#include <QVector>
#include <QVariant>

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
    int nodes = ui->iterations_spinBox->value();
    //TODO a call to som class
}
