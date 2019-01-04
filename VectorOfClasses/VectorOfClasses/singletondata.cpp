#include "singletondata.h"


//---------- CONSTRUCTOR ----------

SingletonData :: SingletonData(){

    qDebug()<<"CONSTRUCTOR   SingletonData";

    setBackColor(Qt::lightGray);

    setCurrentIndex(SD_INVALID_INDEX);

}//CONSTRUCTOR

//---------- DESTRUCTOR ----------

SingletonData :: ~SingletonData(){

    qDebug()<<"DESTRUCTOR   ~SingletonData";

}//DESTRUCTOR

//----------

SingletonData* SingletonData :: instance = 0;

//---------- getInstance ----------

SingletonData* SingletonData :: getInstance()
{
    if (instance == 0)
    {
        instance = new SingletonData();
    }//if
    return instance;
}

//---------- setCurrentIndex ----------

void SingletonData :: setCurrentIndex(int dex){

    currentIndex = dex;
}

//---------- setBackColor ----------

void SingletonData :: setBackColor(QColor color){

    backColor = color;
}


//---------- getCurrentIndex ----------

int SingletonData :: getCurrentIndex(){

    return currentIndex;
}

//---------- getBackColor ----------

QColor SingletonData :: getBackColor(){

    return backColor;
}







