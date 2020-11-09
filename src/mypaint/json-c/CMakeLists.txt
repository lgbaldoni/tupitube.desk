set(JSON_C_HEADERS
     arraylist.h
     bits.h
     debug.h
     json.h
     json_c_version.h
     json_inttypes.h
     json_object.h
     json_object_iterator.h
     json_object_private.h
     json_tokener.h
     json_util.h
     linkhash.h
     math_compat.h
     printbuf.h
     random_seed.h
     config.h
     json_config.h)

set(JSON_C_SOURCES
    arraylist.c
    debug.c
    json_c_version.c
    json_object.c
    json_object_iterator.c
    json_tokener.c
    json_util.c
    libjson.c
    linkhash.c
    printbuf.c
    random_seed.c)

add_library(json-c SHARED ${JSON_C_SOURCES})
set_target_properties(json-c PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

# unsure if these are actually necessary
set_property(TARGET json-c PROPERTY C_STANDARD 99)
target_compile_definitions(json-c PUBLIC -D_XOPEN_SOURCE=600)

# unix only path? recheck
install(TARGETS json-c LIBRARY DESTINATION ${TUPITUBE_RASTER})

if(ADD_HEADERS)
# not present in the original, so I'm disabling it
#  install(FILES ${JSON_C_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/json-c)
endif()
