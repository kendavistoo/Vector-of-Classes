#include "raceplane.h"

//---------- CONSTRUCTOR   RacePlane ----------

RacePlane :: RacePlane(QString rname, QWidget* parent) : AbstractRacer(parent)
{
    qDebug()<<"CONSTRUCTOR   RacePlane";

    speedSlider = new VCSlider("Fraction of Max Speed", Qt::Horizontal, this, VCSLIDER_TEXT_ABOVE);
    speedSlider->setSliderWidth(160);
    speedSlider->setSliderXYLocation(G_LEFT_MARGIN, 120);
    speedSlider->setMinimum(0);
    speedSlider->setMaximum(100);
    speedSlider->setValue(50);
    speedSlider->setVisible(true);

    connect(speedSlider, &QSlider::valueChanged, this, &RacePlane::SLOT_ChangeSpeedFraction);

    //----------

    name = rname;

    sData = SingletonData::getInstance();
}

//---------- DESTRUCTOR   RacePlane ----------

RacePlane :: ~RacePlane()
{
    qDebug()<<"DESTRUCTOR   ~RacePlane";
}


//---------- showSound ----------

void RacePlane :: showSound(){

    qDebug()<<"RacePlane :: showSound()";

    this->soundLabel->setVisible(true);
    soundLabel->setText("ZOOM ! !");

    update();
}

//---------- getSpeedFraction ----------

double RacePlane :: getSpeedFraction(){
    return sData->speedFraction;
}

//---------- getName ----------

QString RacePlane :: getName(){
    return name;
}

//---------- cleanUpAndHalt ----------

void RacePlane :: cleanUpAndHalt(){
    qDebug()<<"RacePlane :: cleanUpAndHalt";
    soundLabel->setVisible(false);
}

//---------- start ----------

void RacePlane :: start(){

    QString myText = "Hello, I Am An UNLIMITED RACE PLANE ! ! !";
    QFontMetrics fm(titleFont);
    int width = fm.width(myText);

    int xxx = (this->width() - width) / 2;
    int yyy = 40;
    int www = width ;
    int hhh = 26;

    titleLabel->setText(myText);
    titleLabel->setGeometry(xxx, yyy, www, hhh);

    AdjustSpeedLabel();

    setVisible(true);

    timer.start();
    doSound = false;
    soundButt->setEnabled(true);
}

//---------- paintEvent ----------

void RacePlane :: paintEvent(QPaintEvent*){

    QPainter *painter = new QPainter(this);

    QColor myColor = sData->getBackColor();

    QPalette pal = palette();
    pal.setColor(QPalette::Background, myColor);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    delete painter;

    update();
}

//---------- AdjustSpeedLabel ----------

void RacePlane :: AdjustSpeedLabel(){

    QString spfstr = "SpeedFraction:  ";
    spfstr.append(QString::number(getSpeedFraction()));
    QString sps = "\nSpeed:  ";
    double sp = (sData->speedFraction * RP_MAX_SPEED);
    sp = (round(sp * 10.0)) / 10.0;
    sps.append(QString::number(sp));
    sps.append(" MPH");
    spfstr.append(sps);

    speedLabel->setText(spfstr);
    speedLabel->setVisible(true);
}

//---------- SLOT_ChangeSpeedFraction ----------

void RacePlane :: SLOT_ChangeSpeedFraction(int val){

    double num = (double)val / 100.0;

    sData->speedFraction = num;

    QString myNumText = "   ";
    myNumText.append(QString::number(num));
    speedSlider->setAppendedText(myNumText);

    AdjustSpeedLabel();
}


