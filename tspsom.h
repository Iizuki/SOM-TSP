#ifndef TSPSOM_H
#define TSPSOM_H

#include <QMainWindow>
#include "cities.h"

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

private:
    Ui::TspSom *ui;
    Cities citiesMap;
};
#endif // TSPSOM_H
