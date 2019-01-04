#ifndef VCSLIDER_H
#define VCSLIDER_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef SINGLETONDATA_H
#include "singletondata.h"
#endif

static const int VCSLIDER_TEXT_ABOVE = 0;
static const int VCSLIDER_TEXT_BELOW = 1;

static const int VCSLIDER_DEFAULT_WIDTH  = 140;
static const int VCSLIDER_DEFAULT_HEIGHT = 35;

//----- class VCSlider -----

class VCSlider : public QSlider
{
public:
    VCSlider(QString text, Qt::Orientation orientation = Qt::Horizontal,
                                QWidget *parent = nullptr, int textPosition = VCSLIDER_TEXT_BELOW);
    ~VCSlider();

    void setSliderWidth(int w);
    void setSliderXYLocation(int x, int y);
    void showTextValue(bool appendValueToText = false);
    void setAppendedText(QString newText);

    QString sliderText;
    QString appendedText;
    int     aboveBelow;
    int     textX, textY;
    bool    showValue;

protected:
    void paintEvent(QPaintEvent *e);

private:
    SingletonData* sData;
};


#endif // VCSLIDER_H
