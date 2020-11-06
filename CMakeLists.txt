cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(tupitube.desk)
#set(VERSION_MAJOR 0)
#set(VERSION_MINOR 0)
#set(VERSION_PATCH 1)

# I couldn't find this declared anywhere, but that's how it's built with qmake
set(LIB_VERSION_MAJOR 1)
set(LIB_VERSION_MINOR 0)
set(LIB_VERSION_PATCH 0)
set(LIB_VERSION_STRING ${LIB_VERSION_MAJOR}.${LIB_VERSION_MINOR}.${LIB_VERSION_PATCH})

set(CMAKE_AUTOMOC ON)

# Helpers
#macro (create_test target)
#  add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
#endmacro (create_test)

# Define folders
#set(EXT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext)
#set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
#set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
#set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
#set(BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/bin)
#set(LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib)

# Compiler settings
#set(CMAKE_CXX_STANDARD 11)
#set(warnings "-Wall -Wextra -Werror")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")

# Output
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_DIR})
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})
#set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# https://github.com/snikulov/cmake-modules/blob/master/FindFFmpeg.cmake
# https://github.com/Eyescale/CMake/blob/master/FindFFMPEG.cmake
# https://github.com/Kitware/VTK/blob/master/CMake/FindFFMPEG.cmake
# https://sources.debian.org/src/acoustid-fingerprinter/0.6-6/cmake/modules/FindFFmpeg.cmake/
# try to find out if it's already included somewhere or if there's a newer version around

# https://github.com/Kitware/VTK/blob/master/CMake/FindTHEORA.cmake

# see about adding copyright notices to the modules we add
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/)

# apparently this stuff is supposed to be global
# TUP_DEBUG TUPITUBE_VERSION=\\\"0.2\\\" CODE_NAME=\\\"Gambá\\\" REVISION=\\\"16\\\" CONFIG_VERSION=\\\"3\\\"
# HAVE_ZLIB HAVE_MULTIMEDIA HAVE_QUAZIP HAVE_FFMPEG

# Debug is on by default
if(NOT ${DISABLE_DEBUG})
add_definitions(-DTUP_DEBUG)
endif()

add_definitions(-DTUPITUBE_VERSION="0.2" -DCODE_NAME="Gambá" -DREVISION="16" -DCONFIG_VERSION="3")

### search for libs here; also see if it's proper to link to Qt::Module instead of Qt5::Module
# I would also add zlib, quazip and ffmpeg
# Qt
find_package(Qt5 COMPONENTS Core Gui Multimedia MultimediaWidgets Network
  OpenGL PrintSupport Svg Widgets Xml REQUIRED)

# QuaZip: will have to find a wya to search for this under multipla names (quazip5, quazip)
# and possibly with a pkgconfig fallback and yet something else for Windows or OSX.
# Also see find_library()
find_package(QUAZIP NAMES QuaZip-Qt5 REQUIRED)
# maybe set HAVE_QUAZIP here? Although nothing appears to be using it

# json-c might have to be added optionally

# FFmpeg stuff
find_package(FFmpeg COMPONENTS AVCODEC AVFORMAT AVUTIL)

# Theora and ogg
find_package(THEORA)
# this defines THEORA_FOUND, see about HAVE_THEORA

add_subdirectory(src)
