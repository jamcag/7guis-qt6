cmake_minimum_required(VERSION 3.24)
project(7guis_qt)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_executable(7guis_qt main.cpp)
target_link_libraries(7guis_qt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

