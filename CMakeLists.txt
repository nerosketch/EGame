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

set(EGAME_DEFINITIONS	
	-DDBG=1)

set(SRC
	src/AddPlayerScene.cpp
	src/Dialog.cpp
	src/Game.cpp
	src/MainScene.cpp
	src/Player.cpp
	src/SceneTasks.cpp
	src/SoundManager.cpp
	src/Task.cpp
	src/TextButton.cpp
	src/TextInput.cpp
	src/TextPanel.cpp
	src/main.cpp
	src/resources.cpp)

set(LIBS
	${CMAKE_CURRENT_SOURCE_DIR}/build/oxygine-framework/liboxygine-framework.a
	${CMAKE_CURRENT_SOURCE_DIR}/build/oxygine-freetype/liboxygine-freetype.a
	${CMAKE_CURRENT_SOURCE_DIR}/build/oxygine-sound/liboxygine-sound.a
	${CMAKE_CURRENT_SOURCE_DIR}/build/oxygine-sound/tremor/libtremor.a
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


# EGame dirs
include_directories(${EGAME_INCLUDE_DIRS})
link_directories(${EGAME_INCLUDE_DIRS})

# Add SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Target oxygine-framework
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-framework build/oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})
#target_include_directories(${APP_NAME} SYSTEM PUBLIC ${SDL2_INCLUDE_DIRS} )

# Target oxygine-sound
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-sound build/oxygine-sound)
include_directories(${OXYGINESOUND_INCLUDE_DIRS})


# Target oxygine-freetype
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/oxygine-freetype build/oxygine-freetype)
include_directories(${OXYGINE_FREETYPE_INCLUDE_DIRS})
link_directories(${OXYGINE_FREETYPE_LIBRARY_DIRS})


add_executable(${APP_NAME} ${SRC})

target_link_libraries(${APP_NAME}
	${LIBS}
	${SDL2_LIBRARIES}
	${OXYGINESOUND_LIBS}
	${OXYGINE_CORE_LIBS}
	oxygine-freetype
	${OXYGINE_FREETYPE_LIBS})

if (WIN32) #disable console mode for VC++
	set_target_properties(${APP_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

if (EMSCRIPTEN)
	SET(CMAKE_EXECUTABLE_SUFFIX ".html")	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s NO_EXIT_RUNTIME=1 -s WASM=0 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648 -s FORCE_FILESYSTEM=1")
	em_link_pre_js(${APP_NAME}  ${OXYGINE_JS_LIBRARIES}  ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
endif(EMSCRIPTEN)
