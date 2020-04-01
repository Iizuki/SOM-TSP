#include "tspsom.h"
#include "ui_tspsom.h"

TspSom::TspSom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TspSom)
{
    ui->setupUi(this);
}

TspSom::~TspSom()
{
    delete ui;
}

