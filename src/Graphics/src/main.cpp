

#include "menu.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    menu* c = new menu();
    c->show();
    c->setWindowTitle("My first product");
    c->setGeometry(500,500,500,500);
//    QMenuBar menuBar;
//    QMenu *menu= new QMenu("Menu");
//    menu->addAction("Display",&app,SLOT(calc()));
//    menu->addAction("Exit",&app,SLOT(close()));
//    menuBar.addMenu(menu);
//    menuBar.show();
    return app.exec();
}