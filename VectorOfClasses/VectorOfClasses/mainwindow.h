#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

#ifndef SINGLETONDATA_H
#include "singletondata.h"
#endif

#ifndef VCSLIDER_H
#include "vcslider.h"
#endif

#ifndef RACERBUTTON_H
#include "racerbutton.h"
#endif

#ifndef ABSTRACTRACER_H
#include "abstractracer.h"
#endif

#ifndef RACECAR_H
#include "racecar.h"
#endif

#ifndef RACEHORSE_H
#include "racehorse.h"
#endif

#ifndef RACEPLANE_H
#include "raceplane.h"
#endif

static const int    MW_WIDTH    = 1000;
static const int    MW_HEIGHT   = 700;

static const int    MW_CHILD_X      = 200;
static const int    MW_CHILD_Y      = 80;
static const int    MW_CHILD_WIDTH  = G_CHILD_WIDTH;
static const int    MW_CHILD_HEIGHT = 580;

static const int    MW_BUTTLOC_X            = 60;
static const int    MW_BUTTLOC_Y            = MW_CHILD_Y;
static const int    MW_SPACE_BETWEEN_BUTTS  = G_SPACE_BETWEEN_BUTTS;
static const int    MW_BUTT_WIDTH           = 100;
static const int    MW_BUTT_HEIGHT          = 24;

static const double MW_DEFAULT_SPEED_FRAC   = 0.5;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    SingletonData       *sData;

    RaceCar     *raceCar;
    RaceHorse   *raceHorse;
    RacePlane   *racePlane;

    QVector<AbstractRacer*> racerVector;

    QVector<RacerButton*>   racerButtons;

    void hideAll();
    void setCommonGeometry();

public slots:
    void SLOT_RacerButtonClicked(int idid);
};

#endif // MAINWINDOW_H

