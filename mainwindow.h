#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "mybutton.h"
#include "ship.h"
#include <QUdpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Ship s4_1;
    Ship s3_1;
    Ship s3_2;
    Ship s2_1;
    Ship s2_2;
    Ship s2_3;
    quint16 my_port;
    QUdpSocket* otherPlayer;
    QVector<MyButton*> bVector;
   // bool readytoplay;
    QVector<Ship*> sVector;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void buttonClicked();
    void ship4_1placed();
    void ship3_1placed();
    void ship3_2placed();
    void ship2_1placed();
    void ship2_2placed();
    void ship2_3placed();
    void donePlacing();
    void processData();
    void check();
    //void move();
};

#endif // MAINWINDOW_H
