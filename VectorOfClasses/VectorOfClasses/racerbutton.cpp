#include "racerbutton.h"

//---------- CONSTRUCTOR   RacerButton ----------

RacerButton :: RacerButton(int idid, QString &text, QWidget* parent)
                            : QPushButton(text, parent)
{
    id = idid;
    connect(this, &QPushButton::clicked, this, &RacerButton::SLOT_buttonClicked);

}

//---------- SLOT_buttonClicked ----------

void RacerButton :: SLOT_buttonClicked(){

    qDebug()<<"    RacerButton :: SLOT_buttonClicked      id: "<<id;

    emit SIGNAL_Button_Clicked(id);
}






