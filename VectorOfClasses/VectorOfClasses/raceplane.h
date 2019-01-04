#ifndef RACEPLANE_H
#define RACEPLANE_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef ABSTRACTRACER_H
#include "abstractracer.h"
#endif

#ifndef SINGLETONDATA_H
#include "singletondata.h"
#endif


static const int    RP_MAX_SPEED  = 500;

class RacePlane : public AbstractRacer
{
    Q_OBJECT

public:
    RacePlane(QString rname, QWidget* parent);
    ~RacePlane();

    void    showSound();
    double  getSpeedFraction();
    QString getName();
    void    cleanUpAndHalt();
    void    start();

private:
    QString name;

    int         maxSpeed = RP_MAX_SPEED;
    VCSlider    *speedSlider;

    void AdjustSpeedLabel();

    QTime   timer;
    bool    doSound = false;

protected:
    void paintEvent(QPaintEvent*);

protected slots:
    void SLOT_ChangeSpeedFraction(int);

};

#endif // RACEPLANE_H
