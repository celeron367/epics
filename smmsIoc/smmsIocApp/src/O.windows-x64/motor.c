/* C code for program motor, generated by snc from ../motor.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 2 "../motor.stt"

#include "stdlib.h"
#include "math.h"

# line 16 "../motor.stt"
static const EF_ID flag_go = 1;
# line 21 "../motor.stt"

static void isReached(float x,float y,float xrb,float yrb,float *flag)
   {
      if (fabs(x-xrb)<0.02 && fabs(y-yrb)<0.02 )
	  {
	      *flag=1;
	  }
	  else{
	      *flag=0;
	  }       
   }


/* Variable declarations */
struct seqg_vars {
# line 7 "../motor.stt"
	float x;
# line 8 "../motor.stt"
	float y;
# line 9 "../motor.stt"
	float x_rbv;
# line 10 "../motor.stt"
	float y_rbv;
# line 12 "../motor.stt"
	float move;
# line 13 "../motor.stt"
	float status;
# line 15 "../motor.stt"
	float go;
# line 19 "../motor.stt"
	float stopFlag;
};


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 19 "../motor.stt"
	static float seqg_initvar_stopFlag = 0;
	memcpy(&seqg_var->stopFlag, &seqg_initvar_stopFlag, sizeof(seqg_initvar_stopFlag));
	}
}

/****** Code for state "init" in state set "ramp_tar" ******/

/* Event function for state "init" in state set "ramp_tar" */
static seqBool seqg_event_ramp_tar_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "ramp_tar" */
static void seqg_action_ramp_tar_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "stop" in state set "ramp_tar" ******/

/* Event function for state "stop" in state set "ramp_tar" */
static seqBool seqg_event_ramp_tar_0_stop(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 41 "../motor.stt"
	if (seq_efTestAndClear(seqg_env, flag_go) && seqg_var->go == 1)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "stop" in state set "ramp_tar" */
static void seqg_action_ramp_tar_0_stop(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 42 "../motor.stt"
			seqg_var->move = 1;
# line 43 "../motor.stt"
			seq_pvPutTmo(seqg_env, 4/*move*/, DEFAULT, DEFAULT_TIMEOUT);
# line 44 "../motor.stt"
			seqg_var->status = 1;
# line 45 "../motor.stt"
			seq_pvPutTmo(seqg_env, 5/*status*/, DEFAULT, DEFAULT_TIMEOUT);
# line 46 "../motor.stt"
			seqg_var->stopFlag = 0;
		}
		return;
	}
}

/****** Code for state "moveing" in state set "ramp_tar" ******/

/* Event function for state "moveing" in state set "ramp_tar" */
static seqBool seqg_event_ramp_tar_0_moveing(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 50 "../motor.stt"
	if (seqg_var->stopFlag == 1)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 56 "../motor.stt"
	if (seq_delay(seqg_env, 0.5))
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "moveing" in state set "ramp_tar" */
static void seqg_action_ramp_tar_0_moveing(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 51 "../motor.stt"
			seqg_var->status = 0;
# line 52 "../motor.stt"
			seq_pvPutTmo(seqg_env, 5/*status*/, DEFAULT, DEFAULT_TIMEOUT);
# line 53 "../motor.stt"
			seqg_var->go = 0;
# line 54 "../motor.stt"
			seq_pvPutTmo(seqg_env, 6/*go*/, DEFAULT, DEFAULT_TIMEOUT);
		}
		return;
	case 1:
		{
# line 57 "../motor.stt"
			seq_pvGetTmo(seqg_env, 0/*x*/, DEFAULT, DEFAULT_TIMEOUT);
# line 57 "../motor.stt"
			seq_pvGetTmo(seqg_env, 1/*y*/, DEFAULT, DEFAULT_TIMEOUT);
# line 57 "../motor.stt"
			seq_pvGetTmo(seqg_env, 2/*x_rbv*/, DEFAULT, DEFAULT_TIMEOUT);
# line 57 "../motor.stt"
			seq_pvGetTmo(seqg_env, 3/*y_rbv*/, DEFAULT, DEFAULT_TIMEOUT);
# line 58 "../motor.stt"
			isReached(pVar->x, pVar->y, pVar->x_rbv, pVar->y_rbv, &(pVar->stopFlag));
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"MOTOR:SET:X", offsetof(struct seqg_vars, x), "x", P_FLOAT, 1, 2, 0, 0, 0, 0},
	{"MOTOR:SET:Y", offsetof(struct seqg_vars, y), "y", P_FLOAT, 1, 3, 0, 0, 0, 0},
	{"MOTOR:X:RBV", offsetof(struct seqg_vars, x_rbv), "x_rbv", P_FLOAT, 1, 4, 0, 1, 0, 0},
	{"MOTOR:Y:RBV", offsetof(struct seqg_vars, y_rbv), "y_rbv", P_FLOAT, 1, 5, 0, 1, 0, 0},
	{"MOTOR:MOVE", offsetof(struct seqg_vars, move), "move", P_FLOAT, 1, 6, 0, 0, 0, 0},
	{"MOTOR:STATUS", offsetof(struct seqg_vars, status), "status", P_FLOAT, 1, 7, 0, 0, 0, 0},
	{"CMD:GO", offsetof(struct seqg_vars, go), "go", P_FLOAT, 1, 8, 1, 1, 0, 0},
};

/* Event masks for state set "ramp_tar" */
static const seqMask seqg_mask_ramp_tar_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_ramp_tar_0_stop[] = {
	0x00000102,
};
static const seqMask seqg_mask_ramp_tar_0_moveing[] = {
	0x00000000,
};

/* State table for state set "ramp_tar" */
static seqState seqg_states_ramp_tar[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_ramp_tar_0_init,
	/* event function */    seqg_event_ramp_tar_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_ramp_tar_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "stop",
	/* action function */   seqg_action_ramp_tar_0_stop,
	/* event function */    seqg_event_ramp_tar_0_stop,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_ramp_tar_0_stop,
	/* state options */     (0)
	},
	{
	/* state name */        "moveing",
	/* action function */   seqg_action_ramp_tar_0_moveing,
	/* event function */    seqg_event_ramp_tar_0_moveing,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_ramp_tar_0_moveing,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "ramp_tar",
	/* states */            seqg_states_ramp_tar,
	/* number of states */  3
	},
};

/* Program table (global) */
seqProgram motor = {
	/* magic number */      2002005,
	/* program name */      "motor",
	/* channels */          seqg_chans,
	/* num. channels */     7,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct seqg_vars),
	/* param */             "",
	/* num. event flags */  1,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void motorRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&motor);
}
epicsExportRegistrar(motorRegistrar);
