#ifndef RACERBUTTON_H
#define RACERBUTTON_H

#ifndef GLOBALS_H
#include "globals.h"
#endif

class RacerButton : public QPushButton
{
    Q_OBJECT

public:
    RacerButton(int idid, QString &text, QWidget* parent);

    int id;

private:
    QSignalMapper *signalMapper;

public slots:
    void SLOT_buttonClicked();

signals:
    void SIGNAL_Button_Clicked(int idid);
};

#endif // RACERBUTTON_H
