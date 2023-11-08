#include <QCoreApplication>
#include "pathMaker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto s = Screenshot();
    s.save();

    auto v = WindowCapture();
    v.save();

    return a.exec();
}
