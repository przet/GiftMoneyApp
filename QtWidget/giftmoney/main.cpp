#include "giftmoney.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    giftmoney w;
    w.show();

    return a.exec();
}
