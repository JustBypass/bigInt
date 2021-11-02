//
// Created by Admin on 02.11.2021.
//

#ifndef CMAKE_TUR_SECOND_H
#define CMAKE_TUR_SECOND_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
class second :public QWidget{
    Q_OBJECT
private:
    QWidget* parent = {};
    QPushButton* qpb = {};
    QLabel* lbl = {};
public:
    second(QWidget* parent = nullptr){
        parent = new QWidget();
        qpb = new QPushButton("Home",this);
        QString a = "This is info about my calculator, whicj uses bigInt dynamic library";
        lbl = new QLabel(a);
        QVBoxLayout* vbox = new QVBoxLayout();
        vbox->addWidget(lbl);
        vbox->addWidget(qpb);
        setLayout(vbox);
        connect(qpb,&QPushButton::clicked,this,&second::openF);
    }
signals:
    void openFirst();
public slots:
    void openF()
    {
        this->close();
        emit openFirst();
    }
};


#endif //CMAKE_TUR_SECOND_H
