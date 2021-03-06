/************************************************************** 
* FILE:         PWM_drv.c
* DESCRIPTION:  PWM driver for TMS320F28069
* AUTHOR:       Andra� Kontar�ek
*
****************************************************************/
#ifndef     __PWM_DRV_H__
#define     __PWM_DRV_H__

#include    "DSP28x_Project.h"

#include    "define.h"
#include    "globals.h"

/* Definicije */
// delovanje modula ob debug-dogodkih
// (0-stop at zero, 1-stop immediately, 2-run free)
#define     PWM_DEBUG       DEBUG_STOP

// perioda casovnika (v procesorskih cikilh) 
#define     PWM_PERIOD      (CPU_FREQ/(SAMPLE_FREQ * SAMP_PRESCALE))

// prescaler za prekinitev
#define     PWM_INT_PSCL    SAMP_PRESCALE

/**************************************************************
* Funkcija, pokli�e funkciji PWM_PWM_init in PWM_ADC_init; kli�emo
* jo iz main-a
* return: void
**************************************************************/
extern void PWM_init(void);

/**************************************************************
* Funkcija, ki popi�e registre za PWM1,. Znotraj funkcije
* se omogo�i interrupt za pro�enje ADC, popi�e se perioda, compare
* register, omogo�i se izhode za PWM...
* return:void
**************************************************************/
extern void PWM_update(float duty);

/**************************************************************
* Funkcija, ki starta PWM1. Znotraj funkcije nastavimo
* na�in �tetja �asovnikov (up-down-count mode)
* return: void
**************************************************************/
extern void PWM_start(void);

/**************************************************************
* Funkcija, ki nastavi periodo, za doseganje zeljene periode
* in je natancna na cikel natancno
* return: void
* arg1: zelena perioda
**************************************************************/
extern void PWM_period(float perioda);

/**************************************************************
* Funkcija, ki nastavi periodo, za doseganje zeljene frekvence
* in je natancna na cikel natancno
* return: void
* arg1: zelena frekvenca
**************************************************************/
extern void PWM_frequency(float frekvenca);

#endif  // end of __PWM_DRV_H__ definition

