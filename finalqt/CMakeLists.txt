cmake_minimum_required(VERSION 3.5)
project(kindergarten)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_executable(app src/device.cpp src/book.cpp src/child.cpp src/kindergarten.cpp src/person.cpp src/teacher.cpp src/buy.cpp
    src/gui.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    src/mainwindow.ui
    )

project(kindergarten LANGUAGES CXX)


find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(app PRIVATE Qt5::Widgets)
