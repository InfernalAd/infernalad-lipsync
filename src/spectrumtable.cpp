#include "spectrumtable.h"
#include "ui_spectrumtable.h"

SpectrumTable::SpectrumTable(QWidget *parent) :
    QWidget(parent),
    m_spectrograph(NULL),
    ui(new Ui::SpectrumTable)
{
    this->setWindowTitle("spectrum table");

    ui->setupUi(this);

    m_combo = new QComboBox;




    m_layout = new QBoxLayout(QBoxLayout::TopToBottom);



    m_layout->addWidget(m_combo);
    this->setLayout(m_layout);

    QObject::connect(m_combo,SIGNAL(activated(int)),this,SLOT(changePicture(int)));
}

void SpectrumTable::addSpectrum(FrequencySpectrum &spectrum, QString description)
{
    m_spectrums.push_back(spectrum);
    m_descriptions.push_back(description);

    m_combo->addItem(description);
}

SpectrumTable::~SpectrumTable()
{
    delete ui;
}

void SpectrumTable::changePicture(int index)
{
    this->setWindowTitle(QString("sample spectrum: ") + QString(m_spectrums[index].phoneme()));

    Spectrograph * s = new Spectrograph();
    s->resize(100,100);
    s->setParams(SpectrumNumBands, SpectrumLowFreq, SpectrumHighFreq);
    s->spectrumChanged(m_spectrums[index]);

    if (m_spectrograph == NULL)
    {
        m_spectrograph = s;
        m_layout->addWidget(m_spectrograph);
    }
    else
    {
        m_layout->removeWidget(m_spectrograph);
        m_spectrograph = s;
        m_layout->addWidget(m_spectrograph);
    }
}
