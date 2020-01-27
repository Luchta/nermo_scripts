#include <iostream>
#include "MouseCom.h"
#include <unistd.h>	// usleep


int main()
{
    std::cout << "Nermo Script\n";
    CMouseCom maus;

    maus.startUART();
    int Motor[13] = {00,01,02,03,10,11,12,13,20,21,22,23,24};

   // maus.sendNL();
    usleep(10000);
    

    //LED Check for Communication
    std::cout << "Switching Motor LEDs Communication Test\n";
    for (int i=0;i<13;i++) {
        maus.ProcessSpine(CMouseCom::SetLed, Motor[i], 0);
    }
    usleep(500000);//wait half a second
    for (int i=0;i<13;i++) {
        maus.ProcessSpine(CMouseCom::SetLed, Motor[i], 1);
        usleep(500000); //switch on each led one after another and wait half a second
    }
    usleep(500000);//wait with all leds on
    for (int i=0;i<13;i++) {
        maus.ProcessSpine(CMouseCom::SetLed, Motor[i], 0); //switch all leds off
    }


    ////Switch Motors OFF
/*  
    std::cout << "Deactivating Motors!\n";
    for (int i=0;i<13;i++) {
    maus.ProcessSpine(CMouseCom::SetMotorOff, Motor[i]);
   }
*/
    ////Switch Power to Motors OFF
   // maus.ProcessSpine(CMouseCom::MPwrOff,1);

/* 
   ////PowerCycle Motors
    std::cout << "Motor Power Cycle!\n";
    maus.MotorPwrCycle();
*/

    //Set PID Parameters
    /*
    for (int i=0;i<13;i++) {
        maus.setMotorPID(Motor[i], 'P', 26); //001A
        maus.setMotorPID(Motor[i], 'I', 3);  //old:0004
        maus.setMotorPID(Motor[i], 'D', 40); //0028
    }
    */
	/*
    for (int i=0;i<13;i++) {
        maus.setMotorSilent(Motor[i], 1); //switch motor feedback on
	usleep(10000);//now feedback is on, so delay needed
    }
*/
    return 0;
}
