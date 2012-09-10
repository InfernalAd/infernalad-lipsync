#include "lipwidget.h"
#include "ui_lipwidget.h"

LipWidget::LipWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LipWidget)
{
    ui->setupUi(this);
    _pictures.insert('o',new QImage("images/o.png"));
    _pictures.insert('e',new QImage("images/e.png"));
    _pictures.insert('a',new QImage("images/a.png"));
    _pictures.insert('u',new QImage("images/u.png"));

    _defaultPic = QImage("images/default.png");
    this->changePicture('~');
}

LipWidget::~LipWidget()
{
    delete ui;
}

void LipWidget::changePicture(char picKey)
{
    qDebug() << "chpic" << picKey;
    if (_pictures.contains(picKey))
    {
        //qDebug() << "setted" << picKey;
        ui->label->setPixmap(QPixmap::fromImage(*_pictures.value(picKey)));
        ui->label->adjustSize();
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(_defaultPic));
        ui->label->adjustSize();
    }
}
