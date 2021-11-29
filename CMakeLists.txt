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
        hagame.cpp
        hagame.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        menu.cpp
        menu.h
        object.cpp
        object.h
        questionlist.cpp
        questionlist.h
        score.cpp
        score.h
        source.qrc)

target_link_libraries(MyGame Qt5::Widgets)

