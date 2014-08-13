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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/812168374/Frame.o \
	${OBJECTDIR}/_ext/812168374/Sprite.o \
	${OBJECTDIR}/_ext/812168374/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto ${OBJECTFILES} ${LDLIBSOPTIONS} -lSDL

${OBJECTDIR}/_ext/812168374/Frame.o: ../source/Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/812168374
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/812168374/Frame.o ../source/Frame.cpp

${OBJECTDIR}/_ext/812168374/Sprite.o: ../source/Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/812168374
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/812168374/Sprite.o ../source/Sprite.cpp

${OBJECTDIR}/_ext/812168374/main.o: ../source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/812168374
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/SDL/ -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/812168374/main.o ../source/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/proyecto

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
