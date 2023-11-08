cmake_minimum_required(VERSION 3.16)

project(QMLButton VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appQMLButton
    main.cpp
)

qt_add_qml_module(appQMLButton
    URI QMLButton
    VERSION 1.0
    QML_FILES main.qml
    QML_FILES CustomButton.qml
)

set_target_properties(appQMLButton PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQMLButton
    PRIVATE Qt6::Quick)
