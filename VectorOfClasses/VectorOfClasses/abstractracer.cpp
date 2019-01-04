

#include "abstractracer.h"

//---------- CONSTRUCTOR   AbstractRacer ----------

AbstractRacer :: AbstractRacer(QWidget* parent) : QWidget(parent)
{
    qDebug()<<"CONSTRUCTOR   AbstractRacer";

    sData = SingletonData::getInstance();

    //----------

    titleFont = QFont("Times", 24, QFont::Bold);
    titleFont.setItalic(true);

    titleLabel = new QLabel(this);
    titleLabel->setFont(titleFont);
    titleLabel->setVisible(true);

    //----------

    speedLabel = new QLabel(this);
    speedLabel->setGeometry(G_LEFT_MARGIN, 150, 120, 80);

    //----------

    soundButt = new QPushButton("Show Sound", this);
    soundButt->setGeometry(G_LEFT_MARGIN, 240, 80, 24);
    soundButt->setVisible(true);

    connect(soundButt, &QPushButton::clicked, this, &AbstractRacer::showSound);

    soundLabel = new QLabel(this);
    int xxx = G_LEFT_MARGIN;
    int yyy = 400;
    int www = G_CHILD_WIDTH - 2 * G_LEFT_MARGIN;
    int hhh = 100;
    soundLabel->setGeometry(xxx, yyy, www, hhh);
}

//---------- DESTRUCTOR   AbstractRacer ----------

AbstractRacer :: ~AbstractRacer(){

    qDebug()<<"DESTRUCTOR   ~AbstractRacer";

}


