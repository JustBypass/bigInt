

#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    menu* c = new menu();

    c->setWindowTitle("My first product");
    c->setGeometry(500,500,500,500);
    c->show();




    return app.exec();
}