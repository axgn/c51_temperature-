#include "delay.h"
#include "reg52.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit k1 = P1 ^ 0;
sbit k2 = P1 ^ 1;
sbit k3 = P1 ^ 2;
sbit k4 = P1 ^ 3;
sbit k5 = P1 ^ 4;
sbit k6 = P1 ^ 5;
sbit k7 = P1 ^ 6;
sbit k8 = P1 ^ 7;

int cheak_k1()
{
    if (k1 == 0)
    {
        Delayms_11(1);
        if (k1 == 0)
        {
            return 1;
        }
    }return 0;
}

int cheak_k2()
{
    if (k2 == 0)
    {
        Delayms_11(1);
        if (k2 == 0)
        {
            return 1;
        }
    }return 0;
}

int cheak_k3()
{
    if (k3 == 0)
    {
        Delayms_11(1);
        if (k3 == 0)
        {
            return 1;
        }
    }return 0;
}

int cheak_k4()
{
    if (k4 == 0)
    {
        Delayms_11(1);
        if (k4 == 0)
        {
            return 1;
        }
    }return 0;
}

int cheak_k5()
{
    if (k5 == 0)
    {
        Delayms_11(1);
        if (k5 == 0)
        {
            return 1;
        }
    }return 0;
}

int cheak_k6()
{
    if (k6 == 0)
    {
        Delayms_11(1);
        if (k6 == 0)
        {
            return 1;
        }
    }return 0;
}


int cheak_k7()
{
    if (k7 == 0)
    {
        Delayms_11(1);
        if (k7 == 0)
        {
            return 1;
        }
    }return 0;
}

int cheak_k8()
{
    if (k8 == 0)
    {
        Delayms_11(1);
        if (k8 == 0)
        {
            return 1;
        }
    }return 0;
}
