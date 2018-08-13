#ifndef GIFTMONEY_H
#define GIFTMONEY_H

#include <QWidget>
#include <QString>
#include <string>

namespace Ui
{
    class giftmoney;
}

class giftmoney : public QWidget
{
    Q_OBJECT

public:
    explicit giftmoney(QWidget *parent = 0);
    ~giftmoney();

private slots:
    void on_populateButton_clicked();
    void on_openFileButton_clicked();

private:
    Ui::giftmoney *ui;
    void updateAmounts();
    void readAmounts();
    void addDescription(double price);
    QString description_qstr;
    std::string description;
    QString amount1_str;
    double amount1;
    QString amount2_str;
    double amount2;
    QString itemPrice_str;
    double itemPrice;
    QString itemDescription;
    QString newAmount_str;
    double newAmount;
    std::string filename = "..\\..\\..\\amounts.txt";


};

#endif // GIFTMONEY_H
