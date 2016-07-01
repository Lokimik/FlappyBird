#include "anime.h"

Anime::Anime(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(540,960);
    this->center.setX(this->width()/2);
    this->center.setY(this->height()/2);

    this->pen.setColor(Qt::black);
    this->pen.setWidth(15);
    this->pen.setJoinStyle(Qt::RoundJoin);
    this->pen.setCapStyle(Qt::RoundCap);

    this->status = SHOW_S;

    this->lineSec.length = 120;
    this->circleSec.radius = 120;

    this->init();
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()));
}

void Anime::init()
{
    switch(this->status)
    {
    case SHOW_S:
    case SHOW:
        this->lineSec.isSec1Drawing = true;
        this->lineSec.isSec2Drawing = false;
        this->lineSec.lines.clear();
        this->lineSec.lines.push_back(QLine(-this->lineSec.length/2,-this->lineSec.length/3,
                                    this->lineSec.length/2,-this->lineSec.length/3));
        this->lineSec.lines.push_back(QLine(-this->lineSec.length/2,this->lineSec.length/3,
                                    this->lineSec.length/2,this->lineSec.length/3));
        this->lineSec.lines.push_back(QLine(-this->lineSec.length/2,0,this->lineSec.length/2,0));
        this->lineSec.increase = this->lineSec.length/15;

        /* init rectangle and angle of transition arc. */
        this->arcSec.isSec1Drawing = true;
        this->arcSec.isSec2Drawing = false;
        this->arcSec.radius = (this->circleSec.radius * this->circleSec.radius - (this->lineSec.length/2)*(this->lineSec.length/2))/(2*this->circleSec.radius);
        this->arcSec.rect.setRect(this->lineSec.length/2-this->arcSec.radius,-2*this->arcSec.radius,2*this->arcSec.radius,2*this->arcSec.radius);
        this->arcSec.startAngle = -90;
        this->arcSec.lengthAngle = 0;
        this->arcSec.start = -90;
        this->arcSec.end = atan(this->arcSec.radius/(this->lineSec.length/2.0))*180/3.1415;
        this->arcSec.increase= this->arcSec.radius*3.14*2/40;

        /* init rectangle of circle. */
        this->circleSec.isDrawing = false;
        this->circleSec.rect.setRect(-this->circleSec.radius,-this->circleSec.radius,2*this->circleSec.radius,2*this->circleSec.radius);
        this->circleSec.startAngle = atan(this->arcSec.radius/(this->lineSec.length/2.0))*180/3.1415;
        this->circleSec.lengthAngle = 0;
        this->circleSec.increase= this->circleSec.radius*3.14*2/50;
        break;

    case HIDE_S:
    case HIDE:
        this->lineSec.isSec1Drawing = true;
        this->lineSec.isSec2Drawing = false;
        this->lineSec.lines.clear();
        this->lineSec.lines.push_back(QLine(-this->lineSec.length/2,this->lineSec.length/3,
                                    this->lineSec.length/2,-this->lineSec.length/3));
        this->lineSec.lines.push_back(QLine(-this->lineSec.length/2,-this->lineSec.length/3,
                                    this->lineSec.length/2,this->lineSec.length/3));
        this->lineSec.lines.push_back(QLine(this->lineSec.length/2,0,this->lineSec.length/2,0));
        this->lineSec.increase = this->lineSec.length/15;

        /* Incircle. */

        /* init rectangle of circle. */
        this->circleSec.isDrawing = true;
        this->circleSec.rect.setRect(-this->circleSec.radius,-this->circleSec.radius,2*this->circleSec.radius,2*this->circleSec.radius);
        this->circleSec.startAngle = atan(this->arcSec.radius/(this->lineSec.length/2.0))*180/3.1415;
        this->circleSec.lengthAngle = 360;
        this->circleSec.increase= this->circleSec.radius*3.14*2/50;

        /* init rectangle and angle of transition arc. */
        this->arcSec.isSec1Drawing = false;
        this->arcSec.isSec2Drawing = false;
        this->arcSec.radius = (this->circleSec.radius * this->circleSec.radius - (this->lineSec.length/2)*(this->lineSec.length/2))/(2*this->circleSec.radius);
        this->arcSec.rect.setRect(this->lineSec.length/2-this->arcSec.radius,-2*this->arcSec.radius,2*this->arcSec.radius,2*this->arcSec.radius);
        this->arcSec.startAngle = atan(this->arcSec.radius/(this->lineSec.length/2.0))*180/3.1415;
        this->arcSec.lengthAngle = 0;
        this->arcSec.start = atan(this->arcSec.radius/(this->lineSec.length/2.0))*180/3.1415;
        this->arcSec.end = -90;
        this->arcSec.increase= this->arcSec.radius*3.14*2/40;

        break;
    }
}

void Anime::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(this->pen);
    painter.translate(this->center);
    switch(this->status)
    {
    case SHOW_S:
        painter.drawLines(this->lineSec.lines);
        break;
    case SHOW:
        if(this->lineSec.isSec1Drawing)
        {
            if(this->lineSec.lines[2].x1()<this->lineSec.lines[2].x2())
                this->lineSec.lines[2].setP1(QPoint(this->lineSec.lines[2].x1()+this->lineSec.increase,this->lineSec.lines[2].y2()));
            else
            {
                this->lineSec.lines[2].setP1(QPoint(this->lineSec.lines[2].x2(),this->lineSec.lines[2].y1()));
                this->lineSec.isSec1Drawing = false;
                this->arcSec.isSec2Drawing = true;
            }
        }
        if(this->arcSec.isSec1Drawing)
        {
            if(this->arcSec.lengthAngle+this->arcSec.startAngle-this->arcSec.start<(this->arcSec.end-this->arcSec.start))
                this->arcSec.lengthAngle += this->arcSec.increase;
            else
            {
                this->arcSec.lengthAngle = this->arcSec.end-this->arcSec.start;
                this->arcSec.isSec1Drawing = false;
                this->circleSec.isDrawing = true;
            }
        }
        if(this->arcSec.isSec2Drawing)
        {
            if(this->arcSec.startAngle<this->arcSec.end)
            {
                this->arcSec.startAngle += this->arcSec.increase;
                this->arcSec.lengthAngle = this->arcSec.end - this->arcSec.startAngle;
            }
            else
            {
                this->arcSec.start = this->arcSec.end;
                this->arcSec.lengthAngle = 0;
                this->arcSec.isSec2Drawing = false;
            }
        }

        if(this->circleSec.isDrawing)
        {
            if(this->circleSec.lengthAngle < 360)
                this->circleSec.lengthAngle += this->circleSec.increase;
            else
                this->lineSec.isSec2Drawing = true;
        }

        if(this->lineSec.isSec2Drawing)
        {
            if(this->lineSec.lines[0].y1() < this->lineSec.lines[1].y2()
                    ||this->lineSec.lines[1].y1() > this->lineSec.lines[0].y2())
            {
                this->lineSec.lines[0].setP1(QPoint(this->lineSec.lines[0].x1(),this->lineSec.lines[0].y1()+this->lineSec.increase));
                this->lineSec.lines[1].setP1(QPoint(this->lineSec.lines[1].x1(),this->lineSec.lines[1].y1()-this->lineSec.increase));
            }
            else
            {
                this->lineSec.lines[0].setP1(QPoint(this->lineSec.lines[0].x1(),this->lineSec.lines[1].y2()));
                this->lineSec.lines[1].setP1(QPoint(this->lineSec.lines[1].x1(),this->lineSec.lines[0].y2()));
                this->timer.stop();
                this->status = HIDE_S;
            }
        }

        painter.drawLine(this->lineSec.lines[0]);
        painter.drawLine(this->lineSec.lines[1]);
        if(this->lineSec.isSec1Drawing)
            painter.drawLine(this->lineSec.lines[2]);

        if(this->arcSec.isSec1Drawing || this->arcSec.isSec2Drawing)
            painter.drawArc(this->arcSec.rect,this->arcSec.startAngle*16,this->arcSec.lengthAngle*16);

        if(this->circleSec.isDrawing)
            painter.drawArc(this->circleSec.rect,this->circleSec.startAngle*16,this->circleSec.lengthAngle*16);
        break;

    case HIDE_S:
        painter.drawLines(this->lineSec.lines);
        painter.drawArc(this->circleSec.rect,this->circleSec.startAngle*16,this->circleSec.lengthAngle*16);
        break;
    case HIDE:
        if(this->lineSec.isSec1Drawing)
        {
            if(this->lineSec.lines[0].y1() > this->lineSec.lines[0].y2()
                    ||this->lineSec.lines[1].y1() < this->lineSec.lines[1].y2())
            {
                this->lineSec.lines[0].setP1(QPoint(this->lineSec.lines[0].x1(),this->lineSec.lines[0].y1()-this->lineSec.increase));
                this->lineSec.lines[1].setP1(QPoint(this->lineSec.lines[1].x1(),this->lineSec.lines[1].y1()+this->lineSec.increase));
            }
            else
            {
                this->lineSec.lines[0].setP1(QPoint(this->lineSec.lines[0].x1(),this->lineSec.lines[0].y2()));
                this->lineSec.lines[1].setP1(QPoint(this->lineSec.lines[1].x1(),this->lineSec.lines[1].y2()));
                this->lineSec.isSec1Drawing = false;
                this->circleSec.isDrawing = true;
                this->arcSec.isSec1Drawing = true;
            }
        }

        if(this->circleSec.isDrawing)
        {
            if(this->circleSec.lengthAngle > 0)
                this->circleSec.lengthAngle -= this->circleSec.increase;
            else
            {
                this->circleSec.lengthAngle = 0;
                this->arcSec.isSec2Drawing = true;
            }
        }

        if(this->arcSec.isSec1Drawing)
        {
            if(this->arcSec.lengthAngle+this->arcSec.startAngle-this->arcSec.start>(this->arcSec.end-this->arcSec.start))
                this->arcSec.lengthAngle -= this->arcSec.increase;
            else
            {
                this->arcSec.lengthAngle = this->arcSec.end-this->arcSec.start;
                this->lineSec.isSec2Drawing = true;
            }
        }

        if(this->arcSec.isSec2Drawing)
        {
            if(this->arcSec.startAngle>this->arcSec.end)
            {
                this->arcSec.startAngle -= this->arcSec.increase;
                this->arcSec.lengthAngle = this->arcSec.end - this->arcSec.startAngle;
            }
            else
            {
                this->arcSec.start = this->arcSec.end;
                this->arcSec.lengthAngle = 0;
                this->arcSec.isSec2Drawing = false;
                this->arcSec.isSec1Drawing = false;
                this->timer.stop();
                this->status = SHOW_S;
            }
        }

        if(this->lineSec.isSec2Drawing)
        {
            if(this->lineSec.lines[2].x1()>this->lineSec.lines[0].x1())
                this->lineSec.lines[2].setP1(QPoint(this->lineSec.lines[2].x1()-this->lineSec.increase,this->lineSec.lines[2].y1()));
            else
            {
                this->lineSec.lines[2].setP1(QPoint(this->lineSec.lines[0].x1(),this->lineSec.lines[2].y1()));
                this->lineSec.isSec2Drawing = false;
            }
        }

        painter.drawLines(this->lineSec.lines);

        if(this->arcSec.isSec1Drawing || this->arcSec.isSec2Drawing)
            painter.drawArc(this->arcSec.rect,this->arcSec.startAngle*16,this->arcSec.lengthAngle*16);

        if(this->circleSec.isDrawing)
            painter.drawArc(this->circleSec.rect,this->circleSec.startAngle*16,this->circleSec.lengthAngle*16);
        break;
    }
}

bool Anime::setParameters(int _lengthOfLine, int _radius)
{
    this->lineSec.length = _lengthOfLine;
    this->circleSec.radius = _radius;
    this->init();
    return true;
}

void Anime::show()
{
    switch(this->status)
    {
    case SHOW_S:
    case SHOW:
        this->status = SHOW;
        break;
    case HIDE_S:
    case HIDE:
        this->status = HIDE;
        break;
    }

    this->init();
    this->timer.start(16);
}


void Anime::increaseCircle()
{
    this->circleSec.radius += 5;
    this->init();
    this->update();
}

void Anime::decreaseCircle()
{
    this->circleSec.radius -= 5;
    this->init();
    this->update();
}

void Anime::increaseLine()
{
    this->lineSec.length += 5;
    this->init();
    this->update();
}

void Anime::decreaseLine()
{
    this->lineSec.length -= 5;
    this->init();
    this->update();
}

