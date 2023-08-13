#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

void Widget::updateButtonState()
{
    ui->pbCoffee->setEnabled(balance >= 100);
    ui->pbTea->setEnabled(Widget::balance >= 150);
    ui->pbMilk->setEnabled(Widget::balance >= 200);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeBalance(int diff)
{
    balance += diff;
    ui->lcdNumber->display(balance);
    updateButtonState();
}


void Widget::on_pb10_clicked()
{
    changeBalance(10);
}


void Widget::on_pb50_clicked()
{
    changeBalance(50);
}


void Widget::on_pb100_clicked()
{
    changeBalance(100);
}


void Widget::on_pbCoffee_clicked()
{
    changeBalance(-100);
}


void Widget::on_pbTea_clicked()
{
    changeBalance(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeBalance(-200);
}

void Widget::returnBalance(int balance, int& coin_500, int& coin_100, int& coin_50, int& coin_10) {
    coin_500 = balance / 500;
    balance %= 500;

    coin_100 = balance / 100;
    balance %= 100;

    coin_50 = balance / 50;
    balance %= 50;

    coin_10 = balance / 10;
}

void Widget::on_pbReset_clicked()
{
    int coin_500, coin_100, coin_50, coin_10;
    returnBalance(balance, coin_500, coin_100, coin_50, coin_10);
    QString balanceFormat = QString("500won coin : %1, 100won coin : %2, 50won coin: %3, 10won coin : %4")
                                .arg(coin_500).arg(coin_100).arg(coin_50).arg(coin_10);
    QMessageBox mb;
    mb.information(nullptr, "Exchange state", balanceFormat);

    balance = 0;
    ui->lcdNumber->display(balance);
    updateButtonState();
}

