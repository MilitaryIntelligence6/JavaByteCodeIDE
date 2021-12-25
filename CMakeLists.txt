cmake_minimum_required(VERSION 3.5)

project(JavaByteCodeIDE LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES JavaByteCodeIDE_zh_CN.ts)

include_directories(src/main/cpp/codecomplete/controller)
include_directories(src/main/cpp/codecomplete/entity)
include_directories(src/main/cpp/codecomplete/ui)
include_directories(src/main/cpp/codecomplete/util)

include_directories(src/main/cpp/common/controller)
include_directories(src/main/cpp/common/entity)
include_directories(src/main/cpp/common/ui)
include_directories(src/main/cpp/common/util)

include_directories(src/main/cpp/console/controller)
include_directories(src/main/cpp/console/entity)
include_directories(src/main/cpp/console/ui)
include_directories(src/main/cpp/console/util)

include_directories(src/main/cpp/highlight/controller)
include_directories(src/main/cpp/highlight/entity)
include_directories(src/main/cpp/highlight/ui)
include_directories(src/main/cpp/highlight/util)

include_directories(src/main/cpp/menu/controller)
include_directories(src/main/cpp/menu/entity)
include_directories(src/main/cpp/menu/ui)
include_directories(src/main/cpp/menu/util)

include_directories(src/main/cpp/editor/controller)
include_directories(src/main/cpp/editor/entity)
include_directories(src/main/cpp/editor/ui)
include_directories(src/main/cpp/editor/util)

qt5_add_resources(IMAGE_RESOURCE
        src/main/resources/image/image.qrc)

file(GLOB SOURCE_FILES
        src/main/cpp/*/*/*.h
        src/main/cpp/*/*/*.hpp
        src/main/cpp/*/*/*.cpp
        src/main/cpp/main.cpp
        )

if (ANDROID)
  add_library(JavaByteCodeIDE SHARED
          ${SOURCE_FILES}
          ${IMAGE_RESOURCE}
          ${TS_FILES}
          )
else ()
  add_executable(JavaByteCodeIDE
          ${SOURCE_FILES}
          ${IMAGE_RESOURCE}
          ${TS_FILES}
          )
endif ()

target_link_libraries(JavaByteCodeIDE PRIVATE Qt5::Widgets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
