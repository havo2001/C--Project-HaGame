cmake_minimum_required(VERSION 3.17)
project(MyGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(.)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.1\\mingw81_64\\lib\\cmake")

find_package(Qt5Widgets REQUIRED)

add_executable(MyGame
        header/hagame.h
	header/menu.h
	header/object.h
	header/score.h
	header/questionlist.h
        source/hagame.cpp
        source/main.cpp
        source/menu.cpp
        source/object.cpp
        source/questionlist.cpp
        source/score.cpp
        resource/source.qrc)

target_link_libraries(MyGame Qt5::Widgets)

