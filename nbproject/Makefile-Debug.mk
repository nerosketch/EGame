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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/AddPlayerScene.o \
	${OBJECTDIR}/Dialog.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/MainScene.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/SceneTasks.o \
	${OBJECTDIR}/SoundManager.o \
	${OBJECTDIR}/Task.o \
	${OBJECTDIR}/TextButton.o \
	${OBJECTDIR}/TextInput.o \
	${OBJECTDIR}/TextPanel.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/resources.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config --cflags sdl2` 
CXXFLAGS=`pkg-config --cflags sdl2` 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L./lib/oxygine-framework/libs ./lib/oxygine-framework/liboxygine-framework.a ./lib/oxygine-freetype/liboxygine-freetype.a ./lib/oxygine-framework/libs/SDL2main.lib -lpthread -lGL -lGLU -lglut -lpng -lz -lSDL2 -ljpeg -lopenal -lfreetype lib/oxygine-sound/liboxygine-sound.a lib/oxygine-sound/tremor/libtremor.a -logg -lopenal

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame: ./lib/oxygine-framework/liboxygine-framework.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame: ./lib/oxygine-freetype/liboxygine-freetype.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame: ./lib/oxygine-framework/libs/SDL2main.lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame: lib/oxygine-sound/liboxygine-sound.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame: lib/oxygine-sound/tremor/libtremor.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/egame ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AddPlayerScene.o: AddPlayerScene.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AddPlayerScene.o AddPlayerScene.cpp

${OBJECTDIR}/Dialog.o: Dialog.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Dialog.o Dialog.cpp

${OBJECTDIR}/Game.o: Game.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/MainScene.o: MainScene.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainScene.o MainScene.cpp

${OBJECTDIR}/Player.o: Player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/SceneTasks.o: SceneTasks.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SceneTasks.o SceneTasks.cpp

${OBJECTDIR}/SoundManager.o: SoundManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SoundManager.o SoundManager.cpp

${OBJECTDIR}/Task.o: Task.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Task.o Task.cpp

${OBJECTDIR}/TextButton.o: TextButton.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextButton.o TextButton.cpp

${OBJECTDIR}/TextInput.o: TextInput.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextInput.o TextInput.cpp

${OBJECTDIR}/TextPanel.o: TextPanel.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextPanel.o TextPanel.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/resources.o: resources.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -DDBG -I./lib/oxygine-framework/oxygine/src -I./lib/oxygine-freetype/src -I./lib/oxygine-sound/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/resources.o resources.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
