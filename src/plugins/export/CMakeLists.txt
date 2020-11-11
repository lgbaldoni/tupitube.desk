add_subdirectory(imageplugin)
## SMIL plugin will be disabled temporary
#add_subdirectory(# smileplugin)

# don't forget to add the checks in the top CMakeLists.txt
# should be if(HAVE_FFMPEG) to match the original
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
# should be if(HAVE_THEORA) to match the original
if(THEORA_FOUND)
###  add_subdirectory(theoraplugin)
endif()

# Experimental code
#if(HAVE_APNG)
#add_subdirectory(apngplugin)
#endif()
