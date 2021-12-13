cmake_minimum_required(VERSION 3.17)
project(C--Project-HaGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(.)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.2.1\\mingw81_64\\lib\\cmake")

find_package(Qt5Widgets REQUIRED)

add_executable(C--Project-HaGame
        main.cpp
        include/hagame.h
	include/menu.h
	include/object.h
	include/score.h
	include/questionlist.h
        src/hagame.cpp
        src/menu.cpp
        src/object.cpp
        src/questionlist.cpp
        src/score.cpp
        resource/source.qrc)

target_link_libraries(C--Project-HaGame Qt5::Widgets)
