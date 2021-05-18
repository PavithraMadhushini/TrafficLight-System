#include <QApplication>
#include "trafficlightwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CTrafficlightWidget oTrafficLight;
    oTrafficLight.show();
    oTrafficLight.Run();

    return a.exec();
}
