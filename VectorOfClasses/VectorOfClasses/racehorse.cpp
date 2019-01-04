#include "racehorse.h"

//---------- CONSTRUCTOR   RaceHorse ----------

RaceHorse :: RaceHorse(QString rname, QWidget* parent) : AbstractRacer(parent)
{
    qDebug()<<"CONSTRUCTOR   RaceHorse";

    name = rname;

    sData = SingletonData::getInstance();

    soundLabel->setText("RaceHorse Text");
    soundLabel->setVisible(true);

    colorDiaButt = new QPushButton("Background Color",this);

    int xxx = G_LEFT_MARGIN;
    int yyy = soundButt->y() + soundButt->height() + G_SPACE_BETWEEN_BUTTS;
    int www = 130;
    int hhh = 24;
    colorDiaButt->setGeometry(xxx, yyy, www, hhh);
    colorDiaButt->setVisible(true);

    connect(colorDiaButt, &QPushButton::clicked, this, &RaceHorse::SLOT_setBackgroundColor);

}

//---------- DESTRUCTOR   RaceHorse ----------

RaceHorse :: ~RaceHorse()
{
    qDebug()<<"DESTRUCTOR   ~RaceHorse";
}

//---------- showSound ----------

void RaceHorse :: showSound(){

    qDebug()<<"RaceHorse :: showSound()";

    this->soundLabel->setVisible(true);
}

//---------- getSpeedFraction ----------

double RaceHorse :: getSpeedFraction(){

    return speedFraction;
}

//---------- getName ----------

QString RaceHorse :: getName(){
    return name;
}

//---------- cleanUpAndHalt ----------
void RaceHorse :: cleanUpAndHalt(){
    //TODO
}

//---------- start ----------

void RaceHorse :: start(){

    QString myText = "Hello, I Am A RACEHORSE ! ! !";
    QFontMetrics fm(titleFont);
    int width = fm.width(myText);

    int xxx = (this->width() - width) / 2;
    int yyy = 40;
    int www = width ;
    int hhh = 26;

    titleLabel->setText(myText);
    titleLabel->setGeometry(xxx, yyy, www, hhh);

    //----------

    QString spfstr = "SpeedFraction:  ";
    spfstr.append(QString::number(sData->speedFraction));
    QString sps = "\nSpeed:  ";
    double sp = (sData->speedFraction * RH_MAX_SPEED);
    sp = (round(sp * 10.0)) / 10.0;
    sps.append(QString::number(sp));
    sps.append(" MPH");
    spfstr.append(sps);

    speedLabel->setText(spfstr);
    speedLabel->setVisible(true);

    timer.start();
    doSound = false;
    soundButt->setEnabled(true);

    setVisible(true);
}

//---------- paintEvent ----------

void RaceHorse :: paintEvent(QPaintEvent*){

    QPainter *painter = new QPainter(this);

    int x = 10 + (int)(50 + (rand() % 10));
    int y = (this->height() - 40);
    QRect myRect(x,y,8,8);
    painter->fillRect(myRect, Qt::red);

    //----------

    QColor myColor = sData->getBackColor();

    QPalette pal = palette();
    pal.setColor(QPalette::Background, myColor);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    //----------

    delete painter;

    update();
}

//---------- SLOT_setBackgroundColor ----------

void RaceHorse :: SLOT_setBackgroundColor(){

    qDebug()<<"RaceHorse :: SLOT_setBackgroundColor";

    QColorDialog cdialog(this);
    cdialog.setOption(QColorDialog::DontUseNativeDialog);
    cdialog.raise();
    cdialog.exec();
    QColor color = cdialog.selectedColor();

    sData->setBackColor(color);
}



