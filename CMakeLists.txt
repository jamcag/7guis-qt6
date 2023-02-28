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

add_executable(counter counter.cpp)
target_link_libraries(counter
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

add_executable(tempconv tempconv.cpp)
target_link_libraries(tempconv
        Qt::Core
        Qt::Gui
        Qt::Widgets)