cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(tupitube.desk)
# perhaps add program version  here?

# I couldn't find this declared anywhere, but that's how it's built with qmake
set(LIB_VERSION_MAJOR 1)
set(LIB_VERSION_MINOR 0)
set(LIB_VERSION_PATCH 0)
set(LIB_VERSION_STRING ${LIB_VERSION_MAJOR}.${LIB_VERSION_MINOR}.${LIB_VERSION_PATCH})

set(CMAKE_AUTOMOC ON)

# flags
set(CMAKE_C_FLAGS "-Wall -fdiagnostics-color=always ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -fdiagnostics-color=always ${CMAKE_CXX_FLAGS}")

# INDENT EVERY OTHER CONDITIONAL!

# see what to do about Windows and Apple, not to mention BSD
if(UNIX AND NOT APPLE)
  include(GNUInstallDirs)
endif()

# we need to review install dirs for windows and mac

if(NOT DEFINED CMAKE_INSTALL_BINDIR)
  set(CMAKE_INSTALL_BINDIR bin)
endif()

if(NOT DEFINED CMAKE_INSTALL_DATADIR)
  set(CMAKE_INSTALL_DATADIR share)
endif()

if(NOT DEFINED CMAKE_INSTALL_LIBDIR)
  set(CMAKE_INSTALL_LIBDIR lib)
endif()

if(NOT DEFINED CMAKE_INSTALL_INCLUDEDIR)
  set(CMAKE_INSTALL_INCLUDEDIR include)
endif()

set(TUPITUBE_HOME ${CMAKE_INSTALL_PREFIX})
set(TUPITUBE_SHARE ${CMAKE_INSTALL_DATADIR}/tupitube)
### perhaps this is unix-only? recheck
set(TUPITUBE_TUPILIB ${CMAKE_INSTALL_LIBDIR}/tupitube)
set(TUPITUBE_BIN ${TUPITUBE_TUPILIB}/bin)
set(TUPITUBE_PLUGIN ${TUPITUBE_TUPILIB}/plugins)
set(TUPITUBE_RASTER ${TUPITUBE_TUPILIB}/raster)
set(TUPITUBE_LIB ${TUPITUBE_TUPILIB};${TUPITUBE_RASTER})

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

# QuaZip: will have to find a wya to search for this under multiple names (quazip5, quazip)
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

### see about locales too

### FIX THEORAPLUGIN!!! ###
### finish libui

add_subdirectory(src)
