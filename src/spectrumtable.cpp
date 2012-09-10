#include "spectrumtable.h"
#include "ui_spectrumtable.h"

SpectrumTable::SpectrumTable(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::SpectrumTable)
{
    this->setWindowTitle("spectrum table");
    m_layout = new QGridLayout();
    ui->setupUi(this);

    this->setLayout(m_layout);
}

void SpectrumTable::addSpectrum(FrequencySpectrum &spectrum, QString description)
{
    m_spectrums.push_back(spectrum);
    m_descriptions.push_back(description);

    Spectrograph * s = new Spectrograph();

    s->setWindowTitle(QString("sample spectrum:")+QChar(spectrum.phoneme()));
    s->resize(100,100);
    s->setParams(10,0,1000);
    s->spectrumChanged(spectrum);

    m_layout->addWidget(new QLabel(description));
    m_layout->addWidget(s);

}

SpectrumTable::~SpectrumTable()
{
    delete ui;
}
