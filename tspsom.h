#ifndef TSPSOM_H
#define TSPSOM_H

#include <QMainWindow>
#include "cities.h"
#include "som.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TspSom; }
QT_END_NAMESPACE

class TspSom : public QMainWindow
{
    Q_OBJECT

public:
    TspSom(QWidget *parent = nullptr);
    ~TspSom();

public slots:


private slots:
    void generateMapClicked();
    void initializeSOM_clicked();
    void trainClicked();
    void updatePlot();
    void enableButtons(bool b);

private:
    Ui::TspSom *ui;
    Cities citiesMap;
    SOM som;
    QCPCurve* somCurve;
};
#endif // TSPSOM_H
