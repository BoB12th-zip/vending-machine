#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

void Widget::updateState()
{
    if(Widget::money >= 100)
    {
        ui->pbCoffee->setEnabled(true);
    }
    else
    {
        ui->pbCoffee->setEnabled(false);
    }
    if(Widget::money >= 150)
    {
        ui->pbTea->setEnabled(true);
    }
    else
    {
        ui->pbTea->setEnabled(false);
    }
    if(Widget::money >= 200)
    {
        ui->pbMilk->setEnabled(true);
    }
    else
    {
        ui->pbMilk->setEnabled(false);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    Widget::money += diff;
    ui->lcdNumber->display(Widget::money);
    updateState();
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}



void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    mb.information(nullptr, "title","text");
    Widget::money = 0;
    updateState();
}

