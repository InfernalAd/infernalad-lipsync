#include "lipwidget.h"
#include "ui_lipwidget.h"

LipWidget::LipWidget(QWidget *parent) :
    QWidget(parent,Qt::Dialog),
    ui(new Ui::LipWidget)
{
    ui->setupUi(this);
    _pictures.insert('o',new QImage("images/o.png"));
    _pictures.insert('e',new QImage("images/EHGJK.png"));
    _pictures.insert('a',new QImage("images/a.png"));
    _pictures.insert('i',new QImage("images/JEEI.png"));
    _pictures.insert('u',new QImage("images/OOUQW.png"));

    _defaultPic = QImage("images/BDMP.png");
    this->changePicture('~');
}

LipWidget::~LipWidget()
{
    delete ui;
}

void LipWidget::changePicture(char picKey)
{
    qDebug() << "Change picture to" << picKey;
    ui->label->setText(QString(picKey));
    if (_pictures.contains(picKey))
    {
        ui->picLabel->setPixmap(QPixmap::fromImage(*_pictures.value(picKey)));
        ui->picLabel->adjustSize();
    }
    else
    {
        ui->picLabel->setPixmap(QPixmap::fromImage(_defaultPic));
        ui->picLabel->adjustSize();
    }
}
