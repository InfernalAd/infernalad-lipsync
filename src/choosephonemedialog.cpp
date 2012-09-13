#include "choosephonemedialog.h"
#include "ui_choosephonemedialog.h"

ChoosePhonemeDialog::ChoosePhonemeDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoosePhonemeDialog)
{
    ui->setupUi(this);
    for (char ch='a';ch<='z';ch++)
    {
        ui->comboBox->addItem(QString(ch));
    }
    QObject::connect(ui->comboBox,SIGNAL(activated(QString)),this,SLOT(charChoosed(QString)));

    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(choiceSubmitted()));

}

ChoosePhonemeDialog::~ChoosePhonemeDialog()
{
    delete ui;
}

void ChoosePhonemeDialog::closeEvent(QCloseEvent * evt)
{
    evt->accept();
}

void ChoosePhonemeDialog::charChoosed(QString descr)
{
    m_phoneme = descr.at(0).toAscii();
}

void ChoosePhonemeDialog::choiceSubmitted()
{
    qDebug() << "choice submitted";
    emit phonemeChoosed(m_phoneme);
    this->close();
}
