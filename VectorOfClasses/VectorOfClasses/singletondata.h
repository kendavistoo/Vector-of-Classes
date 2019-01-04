#ifndef SINGLETONDATA_H
#define SINGLETONDATA_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

static const int    SD_INVALID_INDEX    = -1;

class SingletonData
{
private:
    /* instance stored here */
    static SingletonData* instance;

    /* Private constructor to prevent instancing. */
    SingletonData();
    ~SingletonData();

    int     currentIndex = SD_INVALID_INDEX;

    QColor  backColor;

public:
    friend class MainWindow;

    static SingletonData* getInstance();

    double speedFraction;

    void setCurrentIndex(int dex);
    void setBackColor(QColor);

    int     getCurrentIndex();
    QColor  getBackColor();
};

#endif // SINGLETONDATA_H

