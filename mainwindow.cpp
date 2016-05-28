#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"
//#include <QDebug>
#include <coord.h>
#include <QDataStream>
#include <stdlib.h>
#include <time.h>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), s4_1(4),s3_1(3),s3_2(3),s2_1(2),s2_2(2),s2_3(2),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SEAFIGHT");
    srand(time(0));
    my_port = rand() % 1000 + 12000;
    //qDebug() << port << "bp ";
    ui->Portlabel->setText(QString::number(my_port));
    otherPlayer = new QUdpSocket;
    otherPlayer->bind(QHostAddress::Any, my_port);
    sVector.append(&s4_1);
    sVector.append(&s3_1);
    sVector.append(&s3_2);
    sVector.append(&s2_1);
    sVector.append(&s2_2);
    sVector.append(&s2_3);
    MyButton *b;
    int j;
    for(int i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            b = new MyButton(j,i);
            connect(b,SIGNAL(clicked(bool)),this,SLOT(buttonClicked()));
            ui->gridLayout->addWidget(b,i,j);
            bVector.append(b);
        }
    }
    connect(ui->ship4_1,SIGNAL(clicked(bool)),this,SLOT(ship4_1placed()));
    connect(ui->ship3_1,SIGNAL(clicked(bool)),this,SLOT(ship3_1placed()));
    connect(ui->ship3_2,SIGNAL(clicked(bool)),this,SLOT(ship3_2placed()));
    connect(ui->ship2_1,SIGNAL(clicked(bool)),this,SLOT(ship2_1placed()));
    connect(ui->ship2_2,SIGNAL(clicked(bool)),this,SLOT(ship2_2placed()));
    connect(ui->ship2_3,SIGNAL(clicked(bool)),this,SLOT(ship2_3placed()));
    connect(ui->doneButton,SIGNAL(clicked(bool)),this,SLOT(donePlacing()));
    connect(otherPlayer,SIGNAL(readyRead()),this,SLOT(processData()));
    connect(ui->checkButton,SIGNAL(clicked(bool)),this,SLOT(check()));
 //   connect(ui->doneButton,SIGNAL(clicked(bool)),this,SLOT(ready()));
    connect(ui->doneButton,SIGNAL(clicked(bool)),this,SLOT(donePlacing()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked()
{
    MyButton* button = dynamic_cast<MyButton*>(sender());
    //beginning of the ship placing code
    if((!s4_1.isPlaced())&&(ui->ship4_1->isChecked()) && (!ui->ship3_1->isChecked())&&(!ui->ship3_2->isChecked()) &&(!ui->ship2_1->isChecked())&&(!ui->ship2_2->isChecked())&&(!ui->ship2_3->isChecked()))
    {
    if(s4_1.getcoords().size() >=4) return;
    coord temp(button->getx(),button->gety(),button);
    s4_1.addcoord(temp);
    button->setText("X");

    }
    if((!s3_1.isPlaced()) && (ui->ship3_1->isChecked()) && (!ui->ship4_1->isChecked())&&(!ui->ship3_2->isChecked()) &&(!ui->ship2_1->isChecked())&&(!ui->ship2_2->isChecked())&&(!ui->ship2_3->isChecked()) )
    {
        if(s3_1.getcoords().size() >=3) return;
        coord temp(button->getx(),button->gety(),button);
        s3_1.addcoord(temp);
        button->setText("X");
    }
    if((!s3_2.isPlaced()) && (ui->ship3_2->isChecked()) && (!ui->ship4_1->isChecked())&&(!ui->ship3_1->isChecked()) &&(!ui->ship2_1->isChecked())&&(!ui->ship2_2->isChecked())&&(!ui->ship2_3->isChecked()) )
    {
        if(s3_2.getcoords().size() >=3) return;
        coord temp(button->getx(),button->gety(),button);
        s3_2.addcoord(temp);
        button->setText("X");
    }
    if((!s2_1.isPlaced()) && (ui->ship2_1->isChecked()) && (!ui->ship4_1->isChecked())&&(!ui->ship3_1->isChecked()) &&(!ui->ship3_2->isChecked())&&(!ui->ship2_2->isChecked())&&(!ui->ship2_3->isChecked()) )
    {
        if(s2_1.getcoords().size() >=2) return;
        coord temp(button->getx(),button->gety(),button);
        s2_1.addcoord(temp);
        button->setText("X");
    }
    if((!s2_2.isPlaced()) && (ui->ship2_2->isChecked()) && (!ui->ship4_1->isChecked())&&(!ui->ship3_1->isChecked()) &&(!ui->ship3_2->isChecked())&&(!ui->ship2_1->isChecked())&&(!ui->ship2_3->isChecked()) )
    {
        if(s2_2.getcoords().size() >=2) return;
        coord temp(button->getx(),button->gety(),button);
        s2_2.addcoord(temp);
        button->setText("X");
    }
    if((!s2_3.isPlaced()) && (ui->ship2_3->isChecked()) && (!ui->ship4_1->isChecked())&&(!ui->ship3_1->isChecked()) &&(!ui->ship3_2->isChecked())&&(!ui->ship2_2->isChecked())&&(!ui->ship2_1->isChecked()) )
    {
        if(s2_3.getcoords().size() >=2) return;
        coord temp(button->getx(),button->gety(),button);
        s2_3.addcoord(temp);
        button->setText("X");
    }
    //end of the ship placing code

    //beginning of the turn code
    if((ui->moveButton->isChecked()) && (sVector.size() >= 6))
    {
        ui->moveButton->click();
        QByteArray arr;
        QDataStream steam(&arr,QIODevice::WriteOnly);
        steam << 228 << button->getx() << button->gety();
        //qDebug()<< arr;
        QHostAddress addr(ui->ipEdit->text());
        quint16 port= ui->portEdit->text().toInt();
        //qDebug() << port<< " port";
       otherPlayer->writeDatagram(arr,addr,port);
        //qDebug() <<a;
    }
}

void MainWindow::ship4_1placed()
{
    s4_1.place();
}

void MainWindow::ship3_1placed()
{
    s3_1.place();
}

void MainWindow::ship3_2placed()
{
    s3_2.place();
}

void MainWindow::ship2_1placed()
{
    s2_1.place();
}

void MainWindow::ship2_2placed()
{
    s2_2.place();
}

void MainWindow::ship2_3placed()
{
    s2_3.place();
}

void MainWindow::donePlacing()
{
    /*int wrongpos;
    QVector<coord> v = s4_1.sortVX();
    //QVector<coord>::iterator it = v.begin();
    for(int i=0;i<v.size()-1;i++){
        if((v[i].getx() - v[i+1].getx()) >=2 )
        {
        qDebug() << "your ship sucks!";
        wrongpos = i+1;
        break;
        }
    }

    for(int i=0;i<v.size();i++)
    {
        qDebug() << v[i].getx();
    }*/
}

void MainWindow::processData()
{


    QString text;
    int type,x,y;
    //qDebug() << "process";
    QByteArray data;
    quint16 senderPort;
    QHostAddress addr;
    QDataStream stream(&data,QIODevice::ReadOnly);
    data.resize(otherPlayer->pendingDatagramSize());
    while(otherPlayer->hasPendingDatagrams())
    {
       otherPlayer->readDatagram(data.data(),data.size(),&addr,&senderPort);
       stream>>type;
       stream>>x;
       stream>>y;
       //qDebug() << data;
       //qDebug() << text<< "text";
    };
    //ui->displayer->setText(QString::number(type)+" "+QString::number(x)+QString::number(y));
    switch (type)
    {
    case 1337:
    {
        quint16 p = ui->portEdit->text().toInt();
        QHostAddress a(ui->ipEdit->text());
        QByteArray array;
        QDataStream str(&array,QIODevice::WriteOnly);
        str << 322<<-1<<-1;
        otherPlayer->writeDatagram(array,a,p);
        break;
     }
    case 322 :
    {
        ui->Statuslabel->setText("Player found");
        break;
    }
    case 228 :
    {
        int i = 0,t =0,x1=-1,y1=-1;
        for(i=0;i<bVector.size();i++)
        {
            if(( s4_1.buttonBelongsTo(x,y) || s3_2.buttonBelongsTo(x,y) || s3_1.buttonBelongsTo(x,y) || s2_1.buttonBelongsTo(x,y) || s2_2.buttonBelongsTo(x,y) || s2_3.buttonBelongsTo(x,y))&&(bVector[i]->getx()==x)&&(bVector[i]->gety() == y))
            {
                x1=x;
                y1=y;

                if(ui->portEdit->text().toInt()!= my_port)
                {
                QByteArray ar;
                QDataStream st(&ar,QIODevice::WriteOnly);
                st<<-2;
                st<< x;
                st<<y;
                QHostAddress ad(ui->ipEdit->text());
                quint16 port = ui->portEdit->text().toInt();
                otherPlayer->writeDatagram(ar,ad,port);
                }
                break;

            }
        };
      //  ui->displayer->setText("size "+ QString::number(sVector.size()));
   if(x1 !=-1 && y1!=-1)
   {
        for(t=0;t<sVector.size();t++)
        {
            int del_index = -1;
            for(i=0;i<sVector[t]->getcoords().size();i++)
            {
             if((sVector[t]->getcoords()[i].getx() ==x1)&&(sVector[t]->getcoords()[i].gety() ==y1))
             {
                 //qDebug() << sVector.size() << sVector[t]->getcoords().size();
                 sVector[t]->getcoords()[i].getButton()->setText("█");
                 del_index = i;
             }

            }
            if (del_index != -1) {
               sVector[t]->getcoords().remove(del_index);
            }
            if(sVector[t]->getcoords().isEmpty())
            {
                sVector.remove(t);
            //    ui->displayer->setText("size 2 " + QString::number(sVector.size()));
                break;
            }
        }
        if(sVector.isEmpty()) {
            ui->displayer->setText(" you lose");
        }
    }
        break;
    }
   case -2:
    {

        for(int i=0;i<bVector.size();i++)
        {
            if((bVector[i]->getx() == x)&&(bVector[i]->gety() ==y))
            {
                bVector[i]->setText("0");
                break;
            }
        }
    break;
    }

    }
}

void MainWindow::check()
{
      quint16 p = ui->portEdit->text().toInt();
      QHostAddress a(ui->ipEdit->text());
      QByteArray array;
      QDataStream str(&array,QIODevice::WriteOnly);
      str << 1337<< -1<< -1;
      otherPlayer->writeDatagram(array,a,p);
}



/*void MainWindow::move()
{

}*/
