#ifndef RACECAR_H
#define RACECAR_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef ABSTRACTRACER_H
#include "abstractracer.h"
#endif

#ifndef SINGLETONDATA_H
#include "singletondata.h"
#endif

static const int    RC_MAX_SPEED  = 200;
static const int    RC_TIME_BETWEEN_FRAMES = 18;
static const int    RC_PAUSE_COUNT = 20;

class RaceCar : public AbstractRacer
{
    Q_OBJECT

public:
    RaceCar(QString rname, QWidget* parent);
    ~RaceCar();

    void    showSound();
    double  getSpeedFraction();
    QString getName();
    void    cleanUpAndHalt();
    void    start();

private:
    QString name;

    QTime   timer;
    bool    doSound = false;
    int     lastPause = 0;
    int     charNum;
    int     reps = 2;
    int     passNum = 1;
    int     pauseCount = 0;
    QString rootStr = "V a R o o o o m ! ! !";
    QString soundStr;

    int testCounter = 0;

protected:
    void paintEvent(QPaintEvent*);
};

#endif // RACECAR_H
