TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# xxxRecord.h will be created from xxxRecord.dbd
DBDINC += xxxRecord

# Install xxxSupport.dbd into <top>/dbd
DBD += xxxSupport.dbd

# Build an IOC support library
LIBRARY_IOC += smmsIocSupport

# Compile and add the code to the support library
smmsIocSupport_SRCS += xxxRecord.c
smmsIocSupport_SRCS += devXxxSoft.c

# Link locally-provided code into the support library,
# rather than directly into the IOC application.
# This is required for Windows DLL builds.
smmsIocSupport_SRCS += dbSubExample.c
smmsIocSupport_SRCS += smmsIocHello.c
smmsIocSupport_SRCS += initTrace.c

smmsIocSupport_LIBS += $(EPICS_BASE_IOC_LIBS)


# Build the IOC application
PROD_IOC = smmsIoc

# smmsIoc.dbd will be created and installed
DBD += smmsIoc.dbd

# smmsIoc.dbd will include these files:
smmsIoc_DBD += base.dbd
smmsIoc_DBD += xxxSupport.dbd
smmsIoc_DBD += dbSubExample.dbd
smmsIoc_DBD += smmsIocHello.dbd
smmsIoc_DBD += initTrace.dbd
smmsIoc_DBD += asyn.dbd
smmsIoc_DBD += stream.dbd
smmsIoc_DBD += include.dbd



# smmsIoc_registerRecordDeviceDriver.cpp derives from smmsIoc.dbd
smmsIoc_SRCS += smmsIoc_registerRecordDeviceDriver.cpp



# Build the main IOC entry point where needed
smmsIoc_SRCS_DEFAULT += smmsIocMain.cpp
smmsIoc_SRCS_vxWorks += -nil-

# Link in the code from our support library
smmsIoc_LIBS += smmsIocSupport
smmsIoc_LIBS += asyn
smmsIoc_LIBS += stream

# To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # Build sncExample into smmsIocSupport
    sncExample_SNCFLAGS += +r
    smmsIoc_DBD += sncExample.dbd

	gauge_SNCFLAGS += +r
	smmsIoc_DBD += gauge.dbd

	chamber_SNCFLAGS += +r
	smmsIoc_DBD += chamber.dbd

    voltage_SNCFLAGS += +r
	smmsIoc_DBD += voltage.dbd

	motor_SNCFLAGS += +r
	smmsIoc_DBD += motor.dbd

    # A .stt sequence program is *not* pre-processed:
    smmsIocSupport_SRCS += sncExample.stt
	smmsIocSupport_SRCS += gauge.stt
	smmsIocSupport_SRCS += chamber.stt
	smmsIocSupport_SRCS += voltage.stt
	smmsIocSupport_SRCS += motor.stt

    smmsIocSupport_LIBS += seq pv


    # Build sncProgram as a standalone program
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    # A .st sequence program *is* pre-processed:
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

# Finally link IOC to the EPICS Base libraries
smmsIoc_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

