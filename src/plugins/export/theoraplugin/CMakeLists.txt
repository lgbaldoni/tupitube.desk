#CONFIG += plugin warn_on
#TEMPLATE = lib
#TARGET = tupitheoraplugin
#
#INSTALLS += target
#target.path = /plugins/
#
#HEADERS += theoramoviegenerator.h \
#           theoraplugin.h
#

set(TUPITHEORAPLUGIN_SOURCES
    theoramoviegenerator.cpp)
###    theoraplugin.cpp)

add_library(tupitheoraplugin MODULE ${TUPITHEORAPLUGIN_SOURCES})
target_link_libraries(tupitheoraplugin tupifwcore tupibase)

# for some reason I don't have to explicitly link to libtheora/ogg or 
# add to the include path. Look better at those cmake modules

#LIBS += -ltheora -ltheoraenc -ltheoradec -logg
#
#INCLUDEPATH += ../../../libbase
#INCLUDEPATH += ../../../store
#INCLUDEPATH += ../../../libtupi
#
#LIBS += -L../../../libbase -ltupibase
#LIBS += -L../../../store -ltupistore 
#LIBS += -L../../../libtupi -ltupi
#
#FRAMEWORK_DIR = "../../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#unix {
#    !include(../../../../tupiglobal.pri) {
#        error("Please run configure first")
#    }
#}
#
#win32 {
#    include(../../../../win.pri)
#}
