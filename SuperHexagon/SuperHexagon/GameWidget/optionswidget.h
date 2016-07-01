#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QGLWidget>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

#include "gameinfo.h"
#include "GameElement/ebackgroundback.h"
#include "GameElement/ebackgroundfore.h"
#include "GameElement/eoptionsbutton.h"

class OptionsWidget : public QGLWidget
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    EBackGroundFore *backgroundFore;
    EBackGroundBack *backgroundBack;
    EOptionsButton *optionsButton;

public:
    explicit OptionsWidget(QWidget *parent = 0);
    ~OptionsWidget();
    void initialize();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
    void KEY_ESCAPE();

public slots:
};

#endif // OPTIONSWIDGET_H
