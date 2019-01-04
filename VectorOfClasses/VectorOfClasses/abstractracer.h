#ifndef ABSTRACTRACER_H
#define ABSTRACTRACER_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef VCSLIDER_H
#include "vcslider.h"
#endif



static const int    AR_DEFAULT_SPEED_FRAC   = 0.5;

class AbstractRacer : public QWidget
{
    Q_OBJECT

public:
    SingletonData       *sData;

    explicit AbstractRacer(QWidget *parent = nullptr);
    virtual ~AbstractRacer();

    virtual void    showSound() = 0;
    virtual double  getSpeedFraction() = 0;;
    virtual QString getName() = 0;
    virtual void    cleanUpAndHalt() = 0;
    virtual void    start() = 0;

    QPushButton *soundButt;
    QLabel      *soundLabel;

protected:
    QLabel  *titleLabel;
    QFont   titleFont;

    int     racerSpeed;
    QLabel  *speedLabel;

private:

};

#endif // ABSTRACTRACER_H
