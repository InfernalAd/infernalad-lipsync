#ifndef SPECTRUMTABLE_H
#define SPECTRUMTABLE_H

#include <QWidget>
#include "QTableWidget"
#include "frequencyspectrum.h"
#include "QLayout"
#include "QLabel"
#include "QScrollArea"

#include "spectrograph.h"

#include "QBoxLayout"
#include "QComboBox"

#include "spectrum.h"


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
public slots:
    void changePicture(int index);
private:
    Ui::SpectrumTable *ui;

    QVector<FrequencySpectrum> m_spectrums;
    QVector<QString> m_descriptions;

    QLayout * m_layout;
    Spectrograph * m_spectrograph;
    QScrollArea * m_scrollArea;

    QComboBox * m_combo;
};

#endif // SPECTRUMTABLE_H
