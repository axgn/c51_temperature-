#include<REGX52.H>
#include "delay.h"

unsigned char key_check(void)
{
    unsigned char keynumber = 0;
    if(P3_1 == 0){Delayms(10);while(P3_1 == 0);Delayms(10);keynumber = 1;}
    if(P3_0 == 0){Delayms(10);while(P3_0 == 0);Delayms(10);keynumber = 2;}
    if(P3_2 == 0){Delayms(10);while(P3_2 == 0);Delayms(10);keynumber = 3;}
    if(P3_3 == 0){Delayms(10);while(P3_3 == 0);Delayms(10);keynumber = 4;}
    return keynumber;
}