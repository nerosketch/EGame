cmake_minimum_required (VERSION 2.6)
project (EGAME)

set(APP_NAME Egame)

set( CMAKE_BUILD_TYPE RELEASE )

set(EGAME_INCLUDE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound/dependencies/tremor/Tremor
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound/dependencies/libogg/include
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound/tremor
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-framework/oxygine/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-freetype/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound/src
	)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

message(status ${EGAME_INCLUDE_DIRS})

set(EGAME_DEFINITIONS	
	-DDBG=1)

set(SRC
	AddPlayerScene.cpp
	Dialog.cpp
	Game.cpp
	MainScene.cpp
	Player.cpp
	SceneTasks.cpp
	SoundManager.cpp
	Task.cpp
	TextButton.cpp
	TextInput.cpp
	TextPanel.cpp
	main.cpp
	resources.cpp)

set(LIBS
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-framework/liboxygine-framework.a
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-freetype/liboxygine-freetype.a
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound/liboxygine-sound.a
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound/dependencies/tremor/libtremor.a
	${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-framework/libs/SDL2main.lib
	pthread
	GL
	GLU
	glut
	png
	z
	SDL2
	jpeg
	openal
	freetype
	ogg)


find_package(PkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

add_executable(${APP_NAME} ${SRC})

include_directories(${EGAME_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} ${LIBS})
target_include_directories(${APP_NAME} SYSTEM PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} ${SDL2_LIBRARIES})
link_directories(${EGAME_INCLUDE_DIRS})
