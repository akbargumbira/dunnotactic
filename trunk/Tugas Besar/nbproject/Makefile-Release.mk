#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Job/Assassin.o \
	${OBJECTDIR}/Job/Mage.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/DunnoTactic.o \
	${OBJECTDIR}/Job/Sage.o \
	${OBJECTDIR}/Job/Archer.o \
	${OBJECTDIR}/Job/Warrior.o \
	${OBJECTDIR}/Job/Knight.o \
	${OBJECTDIR}/Job/Job.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/tugas_besar

dist/Release/GNU-Linux-x86/tugas_besar: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tugas_besar ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Job/Assassin.o: nbproject/Makefile-${CND_CONF}.mk Job/Assassin.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Assassin.o Job/Assassin.cpp

${OBJECTDIR}/Job/Mage.o: nbproject/Makefile-${CND_CONF}.mk Job/Mage.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Mage.o Job/Mage.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/DunnoTactic.o: nbproject/Makefile-${CND_CONF}.mk DunnoTactic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/DunnoTactic.o DunnoTactic.cpp

${OBJECTDIR}/Job/Sage.o: nbproject/Makefile-${CND_CONF}.mk Job/Sage.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Sage.o Job/Sage.cpp

${OBJECTDIR}/Job/Archer.o: nbproject/Makefile-${CND_CONF}.mk Job/Archer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Archer.o Job/Archer.cpp

${OBJECTDIR}/Job/Warrior.o: nbproject/Makefile-${CND_CONF}.mk Job/Warrior.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Warrior.o Job/Warrior.cpp

${OBJECTDIR}/Job/Knight.o: nbproject/Makefile-${CND_CONF}.mk Job/Knight.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Knight.o Job/Knight.cpp

${OBJECTDIR}/Job/Job.o: nbproject/Makefile-${CND_CONF}.mk Job/Job.cpp 
	${MKDIR} -p ${OBJECTDIR}/Job
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Job/Job.o Job/Job.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/tugas_besar

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
