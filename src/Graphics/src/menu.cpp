//
// Created by Admin on 06.11.2021.
//

#include "menu.h"

menu::menu(QWidget* parent ):parent(new QWidget){

    sec = new second(this);
    //  this->setMenuBar(menuBar);
    //   parent->setCentralWidget(parent);

    QMenuBar* menuBar = new QMenuBar(this);
    QMenu *menu= new QMenu("Меню",menuBar);
    QMenu *menu1= new QMenu("Другая информация",menuBar);

    menu1->addAction("Мои работы",this,SLOT(calc()));
    menu1->addAction("Обо мне",this,SLOT(close()));

    menu->addAction("Вывести",this,SLOT(calc()));
    menu->addAction("Выход",this,SLOT(close()));

    menuBar->addMenu(menu);
    menuBar->addMenu(menu1);

    e = new QLineEdit(this);
    e->setPlaceholderText("Вводите число...");

    qgs = new QGraphicsScene(0,0,100,100,this);
    qgs->addRect(qgs->sceneRect());
    //   setScene(qgs);
    qgv = new QGraphicsView(qgs,this);

    //  qgs->addItem(new figure(qgs->sceneRect().width()));
    qgv->setScene(qgs);
    animTimer = new QTimer(this);


    animTimer->start(1000/60);
    genTimer = new QTimer(this);
    genTimer->start(1000);
    connect(animTimer,SIGNAL(timeout()),qgs,SLOT(advance()));//Переопределить advance
    connect(genTimer,SIGNAL(timeout()),this,SLOT(addSq()));//Переопределить advance


    qgv->show();
    QPixmap *picture = new QPixmap("C:\\Users\\Admin\\CLionProjects\\untitled12\\bigInt\\src\\Graphics\\forms\\oboi.jpg");
    QPalette *palette = new QPalette();
    palette->setBrush(QPalette::Background, *picture);
    this->setPalette(*palette);

    a = new QPushButton("Plus",this);
    QPixmap pixmap("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\icon.png");
    QIcon ButtonIcon(pixmap);
    a->setIcon(ButtonIcon);
    a->setStyleSheet(
            " QPushButton {\n"
            "     border: 2px solid #8f8f91;\n"
            "     border-radius: 6px;\n"

            "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
            "     min-width: 80px;\n"
            "     background-image: url(C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\border.png)"
            " }"

    );

    qs = new QSound("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\zvuk41.wav");
    //  news = new QSound("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\sungha.wav");
    //  news->play();
    QPushButton *qp = new QPushButton("Minus", this);
    QIcon ButtonIcon1(pixmap);
    qp->setIcon(ButtonIcon);
    qp->setStyleSheet(
            " QPushButton {\n"
            "     border: 2px solid #8f8f91;\n"
            "     border-radius: 6px;\n"
            "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
            "     min-width: 80px;\n"
            " }"

    );
    QPushButton *qp1 = new QPushButton("DelTen", this);
    QIcon ButtonIco2(pixmap);
    qp1->setIcon(ButtonIcon);
    qp1->setStyleSheet(
            " QPushButton {\n"
            "     border: 2px solid #8f8f91;\n"
            "     border-radius: 6px;\n"
            "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
            "     min-width: 80px;\n"
            " }"

    );
    QPushButton *qp2 = new QPushButton("MulTen", this);
    QIcon ButtonIcon3(pixmap);
    qp2->setIcon(ButtonIcon3);
    qp2->setStyleSheet(
            " QPushButton {\n"
            "     border: 2px solid #8f8f91;\n"
            "     border-radius: 6px;\n"
            "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
            "     min-width: 80px;\n"
            " }"

    );
    QPushButton *exit = new QPushButton("Exit", this);
    QPixmap pixmap2("C:\\Qt\\Qt5.12.10\\cmake_tur\\src\\Graphics\\forms\\exit.png");

    QIcon ButtonIcon4(pixmap2);
    exit->setIcon(ButtonIcon4);
    exit->setStyleSheet(
            " QPushButton {\n"
            "     border: 2px solid #8f8f91;\n"
            "     border-radius: 6px;\n"
            "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
            "     min-width: 80px;\n"
            " }"

    );
    QPushButton *myGit = new QPushButton("Github", this);
    QIcon ButtonIcon5(pixmap);
    myGit->setIcon(ButtonIcon5);
    myGit->setStyleSheet(
            " QPushButton {\n"
            "     border: 2px solid #8f8f91;\n"
            "     border-radius: 6px;\n"
            "     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
            "                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
            "     min-width: 80px;\n"
            " }"

    );
    QVBoxLayout *vbox = new QVBoxLayout;
    QHBoxLayout *vbox2 = new QHBoxLayout;
    QPushButton *appInfo = new QPushButton("Info", this);
    lbl = new QLabel("0", this);
    lbl->setStyleSheet("border-style: solid; border-width: 1px; border-color: black;");

    vbox2->addWidget(lbl);
    vbox2->addWidget(menuBar);
    vbox->setSpacing(3);
    vbox->addStretch(10);

    vbox->addWidget(e);
    vbox->addWidget(a);

    vbox->addWidget(qp);
    vbox->addWidget(qp1);
    vbox->addWidget(qp2);
    vbox->setSpacing(3);
    vbox->addWidget(myGit);
    vbox->addWidget(appInfo);
    vbox->addStretch(10);
    vbox->addWidget(exit);
    vbox->addStretch(3);
    vbox->addWidget(qgv);//Хочу какую то анимацию тут
    QLabel *label = new QLabel(this);
    // setLayout(vbox);
    vbox2->addLayout(vbox);
    setLayout(vbox2);

    connect(a, &QPushButton::clicked, this, &menu::plus);
    connect(qp, &QPushButton::clicked, this, &menu::minus);
    // connect(a,&QPushButton::pressed,this,&menu::pressedFunc);
    //  connect(a,SIGNAL(toggled(true)),this,SLOT(changeBut(true)));
    // connect(a,SIGNAL(toggled(false)),this,SLOT(changeBut(false)));
    connect(qp1, &QPushButton::clicked, this, &menu::delten);
    connect(qp2, &QPushButton::clicked, this, &menu::multen);
    connect(exit, &QPushButton::clicked, this, &menu::qui);
    connect(myGit, &QPushButton::clicked, this, &menu::link);
    connect(appInfo, &QPushButton::clicked, this, &menu::openNew);
    connect(sec, &second::openFirst, this, &QWidget::show);
    err = new errors();
}

void figure::advance(int phase)
{
    if(phase)
    {
        std::cout<<"move";
        this->moveBy(0,0.5);
    }
}

