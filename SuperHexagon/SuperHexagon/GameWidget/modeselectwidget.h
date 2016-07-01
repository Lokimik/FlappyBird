#ifndef MODESELECTWIDGET_H
#define MODESELECTWIDGET_H

#include <QGLWidget>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

#include "gameinfo.h"
#include "GameElement/ebackgroundback.h"
#include "GameElement/ebackgroundfore.h"
#include "GameElement/ecentralhexagon.h"
#include "GameElement/emodebutton.h"
#include "GameElement/emodeinfo.h"

class ModeSelectWidget : public QGLWidget
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    EBackGroundFore *backgroundFore;
    EBackGroundBack *backgroundBack;
    EModeButton *modeButton;
    ECentralHexagon *centralHexagon;
    EModeInfo *modeInfo;

public:
    explicit ModeSelectWidget(QWidget *parent = 0);
    ~ModeSelectWidget();
    void initialize();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

signals:
    void KEY_ESCAPE();
    void KEY_SPACE();

public slots:
};

#endif // MODESELECTWIDGET_H
