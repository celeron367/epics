/* C code for program noraceTest, generated by snc from ../norace.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 7 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
#include "../testSupport.h"

/* Variable declarations */
struct seqg_vars {
# line 9 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	string x;
# line 13 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	string y;
	struct seqg_vars_race1 {
# line 24 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
		string z;
	} seqg_vars_race1;
	struct seqg_vars_race3 {
# line 101 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
		string z;
	} seqg_vars_race3;
	struct seqg_vars_stop {
# line 132 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
		int seconds;
	} seqg_vars_stop;
};


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 132 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	static int seqg_initvar_seconds = 10;
	memcpy(&seqg_var->seqg_vars_stop.seconds, &seqg_initvar_seconds, sizeof(seqg_initvar_seconds));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 19 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	seq_test_init(10);
# line 20 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	testDiag("This test will run for %d seconds...", 10);
}

/****** Code for state "init" in state set "race1" ******/

/* Event function for state "init" in state set "race1" */
static seqBool seqg_event_race1_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "race1" */
static void seqg_action_race1_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 28 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			seqg_var->x[0] = 0;
		}
		return;
	}
}

/****** Code for state "wait" in state set "race1" ******/

/* Event function for state "wait" in state set "race1" */
static seqBool seqg_event_race1_0_wait(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 32 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seq_delay(seqg_env, 0.001))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 49 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if ((seqg_var->x[0] && seqg_var->x[1] && seqg_var->x[0] != seqg_var->x[1]) || (seqg_var->y[0] && seqg_var->y[1] && seqg_var->y[0] != seqg_var->y[1]) || (seqg_var->seqg_vars_race1.z[0] && seqg_var->seqg_vars_race1.z[1] && seqg_var->seqg_vars_race1.z[0] != seqg_var->seqg_vars_race1.z[1]))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "race1" */
static void seqg_action_race1_0_wait(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 33 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			int j;
# line 34 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 35 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				int i;
# line 36 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 38 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (!seqg_var->x[i])
						break;
# line 39 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (seqg_var->x[i] != seqg_var->x[0])
					{
# line 41 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", seqg_var->x[0], seqg_var->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 1:
		{
# line 51 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			testFail("%c/%c", seqg_var->x[0], seqg_var->x[1]);
		}
		return;
	}
}

/****** Code for state "init" in state set "race2" ******/

/* Event function for state "init" in state set "race2" */
static seqBool seqg_event_race2_1_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "race2" */
static void seqg_action_race2_1_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 59 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			seqg_var->x[0] = 0;
		}
		return;
	}
}

/****** Code for state "wait" in state set "race2" ******/

/* Event function for state "wait" in state set "race2" */
static seqBool seqg_event_race2_1_wait(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 63 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seq_delay(seqg_env, 0.001))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 78 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seq_delay(seqg_env, 0.002))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 93 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seqg_var->x[0] && seqg_var->x[1] && seqg_var->x[0] != seqg_var->x[1])
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "race2" */
static void seqg_action_race2_1_wait(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 64 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			int j;
# line 65 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 66 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				int i;
# line 67 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 69 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (!seqg_var->x[i])
						break;
# line 70 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (seqg_var->x[i] != seqg_var->x[0])
					{
# line 72 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", seqg_var->x[0], seqg_var->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 1:
		{
# line 79 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			int j;
# line 80 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 81 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				int i;
# line 82 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 84 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (!seqg_var->x[i])
						break;
# line 85 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (seqg_var->x[i] != seqg_var->x[0])
					{
# line 87 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", seqg_var->x[0], seqg_var->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 2:
		{
# line 95 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			testFail("x[0]=%c!=%c=x[1]", seqg_var->x[0], seqg_var->x[1]);
		}
		return;
	}
}

/****** Code for state "init" in state set "race3" ******/

/* Event function for state "init" in state set "race3" */
static seqBool seqg_event_race3_2_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "race3" */
static void seqg_action_race3_2_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 105 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			seqg_var->x[0] = 0;
		}
		return;
	}
}

/****** Code for state "wait" in state set "race3" ******/

/* Event function for state "wait" in state set "race3" */
static seqBool seqg_event_race3_2_wait(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 109 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seq_delay(seqg_env, 0.001))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 124 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seqg_var->x[0] && seqg_var->x[1] && seqg_var->x[0] != seqg_var->x[1])
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "wait" in state set "race3" */
static void seqg_action_race3_2_wait(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 110 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			int j;
# line 111 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			for (j = 0; j < 1000; j++)
			{
# line 112 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				int i;
# line 113 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
				for (i = 0; i < MAX_STRING_SIZE; i++)
				{
# line 115 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (!seqg_var->x[i])
						break;
# line 116 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
					if (seqg_var->x[i] != seqg_var->x[0])
					{
# line 118 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
						testFail("x[0]=%c!=%c=x[%d]", seqg_var->x[0], seqg_var->x[i], i);
						break;
					}
				}
			}
		}
		return;
	case 1:
		{
# line 126 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			testFail("x[0]=%c!=%c=x[1]", seqg_var->x[0], seqg_var->x[1]);
		}
		return;
	}
}

/****** Code for state "count" in state set "stop" ******/

/* Event function for state "count" in state set "stop" */
static seqBool seqg_event_stop_3_count(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 134 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seqg_var->seqg_vars_stop.seconds == 0)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 136 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	if (seq_delay(seqg_env, 1.0))
	{
		*seqg_pnst = 0;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "count" in state set "stop" */
static void seqg_action_stop_3_count(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 137 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			seqg_var->seqg_vars_stop.seconds -= 1;
# line 138 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
			testPass("%d seconds left", seqg_var->seqg_vars_stop.seconds);
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 144 "e:\\epics_for_win\\extensions\\src\\seq\\seq-2.2.5\\test\\validate\\raceCommon.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"x", offsetof(struct seqg_vars, x), "x", P_STRING, 1, 1, 0, 1, 0, 0},
	{"", offsetof(struct seqg_vars, y), "y", P_STRING, 1, 2, 0, 0, 0, 0},
	{"", offsetof(struct seqg_vars, seqg_vars_race1.z), "z", P_STRING, 1, 3, 0, 0, 0, 0},
	{"", offsetof(struct seqg_vars, seqg_vars_race3.z), "z", P_STRING, 1, 4, 0, 0, 0, 0},
};

/* Event masks for state set "race1" */
static const seqMask seqg_mask_race1_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_race1_0_wait[] = {
	0x0000000e,
};

/* State table for state set "race1" */
static seqState seqg_states_race1[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_race1_0_init,
	/* event function */    seqg_event_race1_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_race1_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   seqg_action_race1_0_wait,
	/* event function */    seqg_event_race1_0_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_race1_0_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "race2" */
static const seqMask seqg_mask_race2_1_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_race2_1_wait[] = {
	0x00000002,
};

/* State table for state set "race2" */
static seqState seqg_states_race2[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_race2_1_init,
	/* event function */    seqg_event_race2_1_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_race2_1_init,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   seqg_action_race2_1_wait,
	/* event function */    seqg_event_race2_1_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_race2_1_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "race3" */
static const seqMask seqg_mask_race3_2_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_race3_2_wait[] = {
	0x00000002,
};

/* State table for state set "race3" */
static seqState seqg_states_race3[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_race3_2_init,
	/* event function */    seqg_event_race3_2_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_race3_2_init,
	/* state options */     (0)
	},
	{
	/* state name */        "wait",
	/* action function */   seqg_action_race3_2_wait,
	/* event function */    seqg_event_race3_2_wait,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_race3_2_wait,
	/* state options */     (0)
	},
};

/* Event masks for state set "stop" */
static const seqMask seqg_mask_stop_3_count[] = {
	0x00000000,
};

/* State table for state set "stop" */
static seqState seqg_states_stop[] = {
	{
	/* state name */        "count",
	/* action function */   seqg_action_stop_3_count,
	/* event function */    seqg_event_stop_3_count,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_stop_3_count,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "race1",
	/* states */            seqg_states_race1,
	/* number of states */  2
	},

	{
	/* state set name */    "race2",
	/* states */            seqg_states_race2,
	/* number of states */  2
	},

	{
	/* state set name */    "race3",
	/* states */            seqg_states_race3,
	/* number of states */  2
	},

	{
	/* state set name */    "stop",
	/* states */            seqg_states_stop,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram noraceTest = {
	/* magic number */      2002005,
	/* program name */      "noraceTest",
	/* channels */          seqg_chans,
	/* num. channels */     4,
	/* state sets */        seqg_statesets,
	/* num. state sets */   4,
	/* user var size */     sizeof(struct seqg_vars),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT | OPT_SAFE),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME noraceTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void noraceTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&noraceTest);
}
epicsExportRegistrar(noraceTestRegistrar);
