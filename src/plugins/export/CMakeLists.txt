#CONFIG += ordered warn_on

add_subdirectory(imageplugin)

#
## SMIL plugin will be disabled temporary 
#add_subdirectory(# smileplugin)

#
#contains(DEFINES, HAVE_FFMPEG) {
#        SUBDIRS += ffmpegplugin 
#}

# don't forget to add the checks in the top CMakeLists.txt
if(FFMPEG_FOUND)
add_subdirectory(ffmpegplugin)
endif()

#
## linux-g++ {
##    contains(DEFINES, HAVE_THEORA) {
##        SUBDIRS += theoraplugin
##    }
## }

# if linux
if(THEORA_FOUND)
add_subdirectory(theoraplugin)
endif()

#
## Experimental code
#contains(DEFINES, HAVE_APNG) {
#         SUBDIRS += apngplugin
#}
