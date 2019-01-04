#include "mainwindow.h"


//----------- CONSTRUCTOR   MainWindow ----------

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent)
{
    qDebug()<<"CONSTRUCTOR   MainWindow";

    sData = SingletonData::getInstance();
    sData->speedFraction = MW_DEFAULT_SPEED_FRAC;

    setFixedSize(MW_WIDTH, MW_HEIGHT);

    raceCar     = new RaceCar("Race Car", this);
    raceHorse   = new RaceHorse("Race Horse", this);
    racePlane   = new RacePlane("Race Plane", this);

    racerVector.append(raceCar);
    racerVector.append(raceHorse);
    racerVector.append(racePlane);

    //----------

    int yyy = MW_BUTTLOC_Y;
    for (int n=0; n<racerVector.count(); n++){
        QString objName = racerVector[n]->getName();

        RacerButton* mybutt = new RacerButton(n, objName, this);

        connect(mybutt, &RacerButton::SIGNAL_Button_Clicked, this, &MainWindow::SLOT_RacerButtonClicked);

        racerButtons.append(mybutt);

        racerButtons[n]->setGeometry(MW_BUTTLOC_X, yyy, MW_BUTT_WIDTH, MW_BUTT_HEIGHT);
        yyy = yyy + MW_BUTT_HEIGHT + MW_SPACE_BETWEEN_BUTTS;
        racerButtons[n]->setVisible(true);
    }//for n

    //----------

    for (int i=0; i<racerVector.count(); i++){
        racerVector[i]->setVisible(false);
    }//for i

    raceCar->setGeometry(MW_CHILD_X, MW_CHILD_Y, MW_CHILD_WIDTH, MW_CHILD_HEIGHT);
    raceCar->setVisible(true);

    hideAll();
    setCommonGeometry();
}

//----------- DESTRUCTOR   ~MainWindow ----------

MainWindow  :: ~MainWindow()
{
    qDebug()<<"DESTRUCTOR   ~MainWindow";
}

//----------- hideAll ----------

void MainWindow  :: hideAll(){

    for (int i=0; i<racerVector.count(); i++){
        QWidget* myWidget = racerVector[i];
        myWidget->setVisible(false);
    }//for i
}

//----------- setCommonGeometry ----------

void MainWindow  :: setCommonGeometry(){

    for (int i=0; i<racerVector.count(); i++){
        QWidget* myWidget = racerVector[i];
        myWidget->setGeometry(MW_CHILD_X, MW_CHILD_Y, MW_CHILD_WIDTH, MW_CHILD_HEIGHT);
    }//for i
}

//----------- SLOT_RacerButtonClicked ----------

void MainWindow  :: SLOT_RacerButtonClicked(int idid){

    int index = sData->getCurrentIndex();

    if (index == SD_INVALID_INDEX){
        sData->setCurrentIndex(idid);
        AbstractRacer* myRacer = racerVector[idid];
        myRacer->start();
    }//if
    else{
        AbstractRacer* oldRacer = racerVector[index];
        oldRacer->cleanUpAndHalt();
        hideAll();
        sData->setCurrentIndex(idid);
        AbstractRacer* newRacer = racerVector[idid];
        newRacer->start();
    }//else

    for (int i=0; i<racerButtons.count(); i++){
        if (i == idid){
            racerButtons[i]->setEnabled(false);
        }//if
        else{
            racerButtons[i]->setEnabled(true);
        }//else

        racerVector[i]->soundLabel->setVisible(false);
    }//for i

    qDebug()<<"    MainWindow  :: SLOT_RacerButtonClicked   id: "<<idid;
}





