

#include "menu.h"
//#include <C:\Users\Admin\CLionProjects\untitled12\bigInt\Box2D-cmake\Box2D\Box2D\Box2D.h>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    menu* c = new menu();

    c->setWindowTitle("My first product");
    c->setGeometry(500,500,500,500);
    c->show();




    return app.exec();
/*   b2Vec2 gravity(0.00f,10.00f);
   return 0;*/


}
