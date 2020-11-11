# are we sure about the name? Shouldn't it be prepended with "tupi"?
set(TGSTENGINE_HEADERS tgstengine.h)
set(TGSTENGINE_SOURCES tgstengine.cpp)

add_library(tgstengine MODULE ${TGSTENGINE_SOURCES})
#target_link_libraries(tgstengine tupifwcore tupibase)

install(TARGETS tgstengine DESTINATION ${TUPITUBE_PLUGIN})
