/*-----------------------------------------------------------------------------------*/
/* FILE			: INITIALIZE.C												         */
/* MODULE		: INITIALIZE HEADER										             */
/* AUTHOR		: HGU SASLAB 												         */
/* DATE			: 2016. 2.29.												         */
/*-----------------------------------------------------------------------------------*/

#ifndef SOURCE_INITIALIZE
#define SOURCE_INITIALIZE

/*-----------------------------------------------------------------------------------*/

#include "Function.h"
#include "Unit.h"
#include "Initialize.h"
#include "Declaration.h"
#include "SharedMem.h"
/*-----------------------------------------------------------------------------------*/
/* 1. Initialize                                                                     */
/*-----------------------------------------------------------------------------------*/

void Initialize(void)
{
	
	ini_Struct();
	ini_ControlFlag();
	ini_Phase();
	ini_Time();
	ini_Model();   //LMS511

	SharedMem_CREATE();
	
	Manage.StopCond = CheckStop();   

	/*printf("Press Enter to Start...\n");
	getchar();*/
}

/*-----------------------------------------------------------------------------------*/
/* 1.1. Struct Initialization                                                        */
/*-----------------------------------------------------------------------------------*/

void ini_Struct(void)
{
	INIT_BUF(Time);
	INIT_BUF(Phase);
	INIT_BUF(Manage);
	INIT_BUF(Error);
	INIT_BUF(bfOutLaser);
}

/*-----------------------------------------------------------------------------------*/
/* 1.2. Control Flag Initialize                                                      */
/*-----------------------------------------------------------------------------------*/

void ini_ControlFlag(void)
{
	Manage.RunCount = 0;
	Manage.StopCond = GO_NEXT;
}

/*-----------------------------------------------------------------------------------*/
/* 1.3. Missile Phase Initialize                                                     */
/*-----------------------------------------------------------------------------------*/

void ini_Phase(void)
{
	//Phase.Laser = LSR_INIT;

}


/*-----------------------------------------------------------------------------------*/
/* 1.4. Time Buffer Initialize                                                       */
/*-----------------------------------------------------------------------------------*/

void ini_Time(void)
{
	Time.Run = DataTime.Tstart;
	Time.count = 0;
}

/*-----------------------------------------------------------------------------------*/
/* 1.5. Model Initialize                                                             */
/*-----------------------------------------------------------------------------------*/

void ini_Model(void)
{
	lsr_Initialize();
}

/*-----------------------------------------------------------------------------------*/

#endif