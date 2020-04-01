#ifndef TSPSOM_H
#define TSPSOM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TspSom; }
QT_END_NAMESPACE

class TspSom : public QMainWindow
{
    Q_OBJECT

public:
    TspSom(QWidget *parent = nullptr);
    ~TspSom();

private:
    Ui::TspSom *ui;
};
#endif // TSPSOM_H
