cmake_minimum_required(VERSION 3.27)
project(koci)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(source
        firstWindow/mainWindow/mainwindow.cpp
        firstWindow/appearance.cpp
        firstWindow/firstwindow.cpp
        firstWindow/mainWindow/object.cpp
)
set(header
        firstWindow/mainWindow/mainwindow.h
        firstWindow/firstwindow.h
        firstWindow/mainWindow/object.h
)
set(other
        main.cpp
)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(${PROJECT_NAME} ${source} ${header} ${other})
target_link_libraries(koci
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

