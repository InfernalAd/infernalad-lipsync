#ifndef CHOOSEPHONEMEDIALOG_H
#define CHOOSEPHONEMEDIALOG_H

#include <QWidget>
#include "QDebug"
#include "QCloseEvent"

namespace Ui {
class ChoosePhonemeDialog;
}

class ChoosePhonemeDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChoosePhonemeDialog(QWidget *parent = 0);
    ~ChoosePhonemeDialog();
    void closeEvent(QCloseEvent *);
public slots:
    void charChoosed(QString descr);
    void choiceSubmitted();
signals:
    void phonemeChoosed(char);
private:
    Ui::ChoosePhonemeDialog *ui;

    char m_phoneme;
};

#endif // CHOOSEPHONEMEDIALOG_H
