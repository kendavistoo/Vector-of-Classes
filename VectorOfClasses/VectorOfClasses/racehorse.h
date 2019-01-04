#ifndef RACEHORSE_H
#define RACEHORSE_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef ABSTRACTRACER_H
#include "abstractracer.h"
#endif

#ifndef SINGLETONDATA_H
#include "singletondata.h"
#endif


static const int    RH_MAX_SPEED  = 40;

class RaceHorse : public AbstractRacer
{
    Q_OBJECT

public:
    RaceHorse(QString rname, QWidget* parent);
    ~RaceHorse();

    void    showSound();
    double  getSpeedFraction();
    QString getName();
    void    cleanUpAndHalt();
    void    start();

    QPushButton     *colorDiaButt;

private:
    QString name;

    double  speedFraction;
    int     speed;
    int     maxSpeed = RH_MAX_SPEED;

    QTime timer;
    bool  doSound = false;

private slots:
    void SLOT_setBackgroundColor();

protected:
    void paintEvent(QPaintEvent*);
};

#endif // RACEHORSE_H
