cmake_minimum_required(VERSION 3.19)
project(To_Do_List LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

file(GLOB_RECURSE BACKEND_SRC
    "${CMAKE_SOURCE_DIR}/backend/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/backend/include/*.h"
    "${CMAKE_SOURCE_DIR}/backend/include/*.hpp"
)

qt_add_executable(To_Do_List
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    taskitem.h taskitem.cpp taskitem.ui
    inputdialog.h inputdialog.cpp inputdialog.ui
    recordshower.h recordshower.cpp recordshower.ui

    ${BACKEND_SRC}
)

target_link_libraries(To_Do_List
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS To_Do_List
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET To_Do_List
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
