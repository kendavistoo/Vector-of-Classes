#include "vcslider.h"


//---------- VCSlider CONSTRUCTOR ----------

VCSlider :: VCSlider(QString text, Qt::Orientation orientation, QWidget *parent, int textPosition) : QSlider(orientation, parent){

    qDebug()<<"CONSTRUCTOR   VCSlider";

    sliderText = QString(text);
    appendedText.clear();
    aboveBelow = textPosition;

    setGeometry(20, 20, VCSLIDER_DEFAULT_WIDTH, VCSLIDER_DEFAULT_HEIGHT);

    sData = SingletonData::getInstance();
}

//---------- ~VCSlider DESTRUCTOR ----------

VCSlider :: ~VCSlider(){

        qDebug()<<"DESTRUCTOR   ~VCSlider";
}

//---------- paintEvent ----------

void VCSlider :: paintEvent(QPaintEvent* event) {

    QPainter* painter = new QPainter(this);

    QFont font = painter->font();

    font.setPixelSize(10);

    painter->setFont(font);

    //QFontInfo info = painter->fontInfo();
    QFontMetrics metrics(font, this);

    QString text = sliderText + appendedText;

    QString numstr = QString::number(this->value());
    int nspaces = 5 - numstr.count();

    if ((showValue) && (text.count() > 0) && (nspaces > 0)){

        text.append(" ");

        for (int k=0; k<nspaces; k++){
            text.append(' ');
        }//for

        text.append(numstr);
    }//if

    QRect textRect = metrics.boundingRect(text);

    textX = (int)((this->width() - textRect.width()) / 2.0);

    if (aboveBelow == VCSLIDER_TEXT_ABOVE){
        textY = 9;
    }
    else{
        textY = this->height() - 2;
    }

    painter->drawText(textX, textY, text);

    font.setPixelSize(12);
    painter->setFont(font);

    delete painter;

    QSlider::paintEvent(event);
}

//---------- setSliderWidth ----------

void VCSlider :: setSliderWidth(int w){

    int x = this->x();
    int y = this->y();
    int h = this->height();
    this->setGeometry(x, y, w, h);
}

//---------- setSliderXYLocation ----------

void VCSlider :: setSliderXYLocation(int x, int y){

    int w = this->width();
    int h = this->height();
    this->setGeometry(x, y, w, h);
}

//---------- showTextValue ----------

void VCSlider :: showTextValue(bool appendValueToText){

    showValue = appendValueToText;
}

//---------- setAppendedText ----------

void VCSlider :: setAppendedText(QString newText){

    appendedText.clear();
    appendedText = newText;
}










