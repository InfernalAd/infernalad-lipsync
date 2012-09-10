#ifndef LIPWIDGET_H
#define LIPWIDGET_H

#include <QWidget>
#include "QMap"
#include "QDebug"


namespace Ui {
class LipWidget;
}

class LipWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit LipWidget(QWidget *parent = 0);
    ~LipWidget();
public slots:
    void changePicture(char picKey);
private:
    Ui::LipWidget *ui;
    QMap<char,QImage *> _pictures;
    QImage _defaultPic;
};

#endif // LIPWIDGET_H
