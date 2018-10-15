/* THIS IS A GENERATED FILE. DO NOT EDIT! */
/* Generated from ../O.Common/cmdButtons.dbd */

#include <string.h>

#include "compilerDependencies.h"
#include "epicsStdlib.h"
#include "iocsh.h"
#include "iocshRegisterCommon.h"
#include "registryCommon.h"

extern "C" {

epicsShareExtern rset *pvar_rset_boRSET, *pvar_rset_stringoutRSET;

typedef int (*rso_func)(dbRecordType *pdbRecordType);
epicsShareExtern rso_func pvar_func_boRecordSizeOffset,
    pvar_func_stringoutRecordSizeOffset;

static const char * const recordTypeNames[] = {
    "bo", "stringout"
};

static const recordTypeLocation rtl[] = {
    {pvar_rset_boRSET, pvar_func_boRecordSizeOffset},
    {pvar_rset_stringoutRSET, pvar_func_stringoutRecordSizeOffset}
};

epicsShareExtern dset *pvar_dset_devBoSoft, *pvar_dset_devSoSoft;

static const char * const deviceSupportNames[] = {
    "devBoSoft", "devSoSoft"
};

static const dset * const devsl[] = {
    pvar_dset_devBoSoft, pvar_dset_devSoSoft
};

typedef void (*reg_func)(void);
epicsShareExtern reg_func pvar_func_seqCmdBtnsRegistrar;

epicsShareExtern double * const pvar_double_boHIGHlimit;
epicsShareExtern int * const pvar_int_boHIGHprecision;

static struct iocshVarDef vardefs[] = {
    {"boHIGHlimit", iocshArgDouble, pvar_double_boHIGHlimit},
    {"boHIGHprecision", iocshArgInt, pvar_int_boHIGHprecision},
    {NULL, iocshArgInt, NULL}
};

int cmdButtons_registerRecordDeviceDriver(DBBASE *pbase)
{
    static int executed = 0;
    const char *bldTop = "E:/epics_for_win/extensions/src/seq/seq-2.2.5";
    const char *envTop = getenv("TOP");

    if (envTop && strcmp(envTop, bldTop)) {
        printf("Warning: IOC is booting with TOP = \"%s\"\n"
               "          but was built with TOP = \"%s\"\n",
               envTop, bldTop);
    }

    if (!pbase) {
        printf("pdbbase is NULL; you must load a DBD file first.\n");
        return -1;
    }

    if (executed) {
        printf("Warning: Registration already done.\n");
    }
    executed = 1;

    registerRecordTypes(pbase, NELEMENTS(rtl), recordTypeNames, rtl);
    registerDevices(pbase, NELEMENTS(devsl), deviceSupportNames, devsl);
    pvar_func_seqCmdBtnsRegistrar();
    iocshRegisterVariable(vardefs);
    return 0;
}

/* cmdButtons_registerRecordDeviceDriver */
static const iocshArg rrddArg0 = {"pdbbase", iocshArgPdbbase};
static const iocshArg *rrddArgs[] = {&rrddArg0};
static const iocshFuncDef rrddFuncDef =
    {"cmdButtons_registerRecordDeviceDriver", 1, rrddArgs};
static void rrddCallFunc(const iocshArgBuf *)
{
    cmdButtons_registerRecordDeviceDriver(*iocshPpdbbase);
}

} // extern "C"

/*
 * Register commands on application startup
 */
static int Registration() {
    iocshRegisterCommon();
    iocshRegister(&rrddFuncDef, rrddCallFunc);
    return 0;
}

static int done EPICS_UNUSED = Registration();
