#ifndef SPECTRUMTABLE_H
#define SPECTRUMTABLE_H

#include <QWidget>
#include "QTableWidget"
#include "frequencyspectrum.h"
#include "QLayout"
#include "QLabel"
#include "spectrograph.h"


namespace Ui {
class SpectrumTable;
}

class SpectrumTable : public QWidget
{
    Q_OBJECT
    
public:
    explicit SpectrumTable(QWidget *parent = 0);

    void addSpectrum(FrequencySpectrum & spectrum,QString description);
    ~SpectrumTable();
    
private:
    Ui::SpectrumTable *ui;

    QVector<FrequencySpectrum> m_spectrums;
    QVector<QString> m_descriptions;

    QLayout * m_layout;
};

#endif // SPECTRUMTABLE_H
