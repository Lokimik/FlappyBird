#ifndef CREDITSWIDGET_H
#define CREDITSWIDGET_H

#include <QGLWidget>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>

#include "gameinfo.h"
#include "GameElement/ebackgroundback.h"
#include "GameElement/ebackgroundfore.h"

class CreditsWidget : public QGLWidget
{
    Q_OBJECT
private:
    QPixmap *bufferPixmap;

    EBackGroundFore *backgroundFore;
    EBackGroundBack *backgroundBack;

public:
    explicit CreditsWidget(QWidget *parent = 0);
    ~CreditsWidget();
    void initialize();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

signals:
        void KEY_ESCAPE();
public slots:
};

#endif // CREDITSWIDGET_H
