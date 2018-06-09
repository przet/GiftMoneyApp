#include "giftmoney.h"
#include "ui_giftmoney.h"
#include <fstream>
#include <string>
#include <iostream> //std::cerr
#include <QFile>
#include <QIODevice>
#include <QString>
#include <QTextStream>
#include <stdexcept>
#include <QDesktopServices>
#include <QUrl>
giftmoney::giftmoney(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giftmoney)
{
    ui->setupUi(this);
    readAmounts();
    ui->openFileButton->setEnabled(true);
    ui->itemDescriptionLineEdit->setEnabled(true);
}

giftmoney::~giftmoney()
{
    delete ui;
}

void giftmoney::on_populateButton_clicked()
{
    itemPrice_str = ui->itemPriceLineEdit->text();
    itemPrice = itemPrice_str.toDouble();

    if(amount1 !=0)
    {
        if (itemPrice <= amount1)
            amount1 -= itemPrice;
        else
        {
            amount2 += (amount1-itemPrice);
            amount1 = 0;

        }
    }
    else
        amount2 -= itemPrice;

    if(amount2 <= 0)
    {
        double amount2_overflow_store = amount2;
        amount2 = 0;
        ui->giftMoney2LineEdit->setText(amount2_str);
        ui->itemDescriptionLineEdit->setText("out of money!");
        ui->itemPriceLineEdit->setText("out of money!");
        ui->populateButton->setEnabled(false);
    }


    updateAmounts();
    addDescription(itemPrice);
    ui->itemPriceLineEdit->clear();
    ui->itemDescriptionLineEdit->clear();
}

void giftmoney::updateAmounts()
{
    amount1_str = QString::number(amount1);
    amount2_str = QString::number(amount2);
    ui->giftMoney1LineEdit->setText(amount1_str);
    ui->giftMoney2LineEdit->setText(amount2_str);

    std::fstream amountsFile(filename,std::ios::in | std::ios::out);
    if(amountsFile.fail())
        std::runtime_error("can't open file");
    amountsFile << amount1 <<'\n' << amount2;
    amountsFile.close();


}

void giftmoney::readAmounts()
{
    std::fstream amountsFile(filename,std::ios::in);
    if (amountsFile.fail())
        std::runtime_error("File cannot open");
    amountsFile >> amount1 >> amount2;
    amountsFile.close();

    amount1_str = QString::number(amount1);
    amount2_str = QString::number(amount2);
    ui->giftMoney1LineEdit->setText(amount1_str);
    ui->giftMoney2LineEdit->setText(amount2_str);


}

void giftmoney::on_openFileButton_clicked()
{
   QDesktopServices::openUrl(
               QUrl("file:///n:/programming/"
                    "GiftMoneyApp/amounts.txt"));
}

void giftmoney::addDescription(double price)
{
    description_qstr = ui->itemDescriptionLineEdit->text();
    description = description_qstr.toStdString();
    std::fstream amountsFile(filename,std::ios::app);
    amountsFile <<'\n'<< description<<"    $" << price;
    amountsFile.close();
}
