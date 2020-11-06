#unix {
#INCLUDEPATH += $$FRAMEWORK_DIR $$FRAMEWORK_DIR/core $$FRAMEWORK_DIR/gui
#LIBS += -L$$FRAMEWORK_DIR/core -L$$FRAMEWORK_DIR/gui -ltupifwcore -ltupifwgui
#}
#
#win32 {
#INCLUDEPATH += $$FRAMEWORK_DIR $$FRAMEWORK_DIR/core $$FRAMEWORK_DIR/gui
#LIBS += -L$$FRAMEWORK_DIR/core/release/ -L$$FRAMEWORK_DIR/gui/release/ -ltupifwcore -ltupifwgui
#}

## SUBDIRS += core gui sound plugins
#SUBDIRS += core gui
#CONFIG += ordered warn_on
#TEMPLATE = subdirs

add_subdirectory(core)
add_subdirectory(gui)
#add_subdirectory(sound)
#add_subdirectory(plugins)
