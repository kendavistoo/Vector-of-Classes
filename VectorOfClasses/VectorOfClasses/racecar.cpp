#include "racecar.h"


//---------- CONSTRUCTOR   RaceCar ----------

RaceCar :: RaceCar(QString rname, QWidget* parent) : AbstractRacer(parent)
{
    qDebug()<<"CONSTRUCTOR   RaceCar";
    name = rname;

    sData = SingletonData::getInstance();
}

//---------- DESTRUCTOR   RaceCar ----------

RaceCar :: ~RaceCar()
{
    qDebug()<<"DESTRUCTOR   ~RaceCar";
}

//---------- showSound ----------

void RaceCar :: showSound(){

    qDebug()<<"RaceCar :: showSound()";

    passNum     = 1;
    pauseCount  = 0;
    charNum     = 0;
    soundStr    = QString();
    doSound     = true;
    lastPause = 0;
    soundButt->setEnabled(false);

    QFont soundFont = QFont("QFont::System", 32, QFont::Bold);
    soundFont.setItalic(true);
    soundLabel->setFont(soundFont);
    soundLabel->setAlignment(Qt::AlignCenter);
    soundLabel->setVisible(true);

    update();
}

//---------- getSpeedFraction ----------

double RaceCar :: getSpeedFraction(){
    return sData->speedFraction;
}

//---------- getName ----------

QString RaceCar :: getName(){
    return name;
}

//---------- cleanUpAndHalt ----------

void RaceCar :: cleanUpAndHalt(){

    qDebug()<<"RaceCar :: cleanUpAndHalt";

    doSound = false;
    soundLabel->setVisible(false);
}

//---------- start ----------

void RaceCar :: start(){

    QString myText = "Hello, I Am A RACE CAR ! ! !";
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
    double sp = (sData->speedFraction * RC_MAX_SPEED);
    sp = (round(sp * 10.0)) / 10.0;
    sps.append(QString::number(sp));
    sps.append(" MPH");
    spfstr.append(sps);

    speedLabel->setText(spfstr);
    speedLabel->setVisible(true);

    setVisible(true);

    timer.start();
    doSound = false;
    soundButt->setEnabled(true);
}

//---------- paintEvent ----------

void RaceCar :: paintEvent(QPaintEvent*){

    QPainter *painter = new QPainter(this);

    QColor myColor = sData->getBackColor();

    QPalette pal = palette();
    pal.setColor(QPalette::Background, myColor);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    delete painter;

    //----------

    if (doSound){

        if (timer.elapsed() > RC_TIME_BETWEEN_FRAMES){

            timer.restart();

            if (passNum == 1){
                soundLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
                if (soundStr.count() < rootStr.count()){
                    soundStr.append(rootStr[charNum]);
                    soundLabel->setText(soundStr);
                    charNum++;
                }//if
                else if (pauseCount++ > RC_PAUSE_COUNT){
                    passNum++;
                    soundStr.clear();
                    charNum = 0;
                    soundLabel->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
                }//if
            }//if
            else{
                if (soundStr.count() < rootStr.count()){
                    soundStr.append(rootStr[charNum]);
                    soundLabel->setText(soundStr);
                    charNum++;
                }//if
                else{
                    if (lastPause++ > (3 * RC_PAUSE_COUNT)){
                        doSound = false;
                        soundLabel->setText("");
                        soundButt->setEnabled(true);
                    }//if
                }//else
            }//else
        }//if

        update();
    }//if

}//paintEvent

