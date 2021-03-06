/* C code for program arrayTest, generated by snc from ../array.st */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 9 "../array.st"
#include "../testSupport.h"

/* Variable declarations */
struct seqg_vars_array {
# line 16 "../array.st"
	string a4a5s[4][5];
	struct {
# line 24 "../array.st"
		string (*a4ps[4])[5];
	} seqg_vars_init;
} seqg_vars_array;


/* Function declarations */

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 16 "../array.st"
	static string seqg_initvar_a4a5s[4][5] = {{"00", "01", "02", "03", "04"}, {"10", "11", "12", "13", "14"}, {"20", "21", "22", "23", "24"}, {"30", "31", "32", "33", "34"}};
	memcpy(&seqg_vars_array.a4a5s, &seqg_initvar_a4a5s, sizeof(seqg_initvar_a4a5s));
	}
	{
# line 24 "../array.st"
	static string (*seqg_initvar_a4ps[4])[5] = {&seqg_vars_array.a4a5s[0], &seqg_vars_array.a4a5s[1], &seqg_vars_array.a4a5s[2], &seqg_vars_array.a4a5s[3]};
	memcpy(&seqg_vars_array.seqg_vars_init.a4ps, &seqg_initvar_a4ps, sizeof(seqg_initvar_a4ps));
	}
}

/* Program entry func */
static void seqg_entry(SS_ID seqg_env)
{
# line 12 "../array.st"
	seq_test_init(20);
}

/****** Code for state "init" in state set "array" ******/

/* Event function for state "init" in state set "array" */
static seqBool seqg_event_array_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		seq_exit(seqg_env);
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "array" */
static void seqg_action_array_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 31 "../array.st"
			int i;
# line 31 "../array.st"
			int j;
# line 32 "../array.st"
			for (i = 0; i < 4; i++)
			{
# line 33 "../array.st"
				for (j = 0; j < 5; j++)
				{
# line 36 "../array.st"
					testOk(seqg_vars_array.a4a5s[i][j] == (*seqg_vars_array.seqg_vars_init.a4ps[i])[j], "a4a5s[%d][%d]=%s==%s=(*a4ps[%d])[%d])", i, j, seqg_vars_array.a4a5s[i][j], (*seqg_vars_array.seqg_vars_init.a4ps[i])[j], i, j);
				}
			}
# line 39 "../array.st"
			for (i = 0; i < 4; i++)
			{
# line 40 "../array.st"
				testDiag("a4ps[%d]=%p", i, seqg_vars_array.seqg_vars_init.a4ps[i]);
			}
		}
		return;
	}
}

/* Program exit func */
static void seqg_exit(SS_ID seqg_env)
{
# line 47 "../array.st"
	seq_test_done();
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"", (size_t)&seqg_vars_array.a4a5s[0], "a4a5s[0]", P_STRING, 5, 1, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[1], "a4a5s[1]", P_STRING, 5, 2, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[2], "a4a5s[2]", P_STRING, 5, 3, 0, 0, 0, 0},
	{"", (size_t)&seqg_vars_array.a4a5s[3], "a4a5s[3]", P_STRING, 5, 4, 0, 0, 0, 0},
};

/* Event masks for state set "array" */
static const seqMask seqg_mask_array_0_init[] = {
	0x00000000,
};

/* State table for state set "array" */
static seqState seqg_states_array[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_array_0_init,
	/* event function */    seqg_event_array_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_array_0_init,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "array",
	/* states */            seqg_states_array,
	/* number of states */  1
	},
};

/* Program table (global) */
seqProgram arrayTest = {
	/* magic number */      2002005,
	/* program name */      "arrayTest",
	/* channels */          seqg_chans,
	/* num. channels */     4,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        seqg_entry,
	/* exit func */         seqg_exit,
	/* num. queues */       0
};

#define PROG_NAME arrayTest
#include "seqMain.c"

/* Register sequencer commands and program */
#include "epicsExport.h"
static void arrayTestRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&arrayTest);
}
epicsExportRegistrar(arrayTestRegistrar);
