cmake_minimum_required (VERSION 2.8)
project (common)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/)
include_directories( ${CMAKE_BINARY_DIR}/../inc )
include_directories( ${CMAKE_BINARY_DIR}/../inc/libeventInc/ )
link_directories( ${CMAKE_BINARY_DIR}/../3rdlibs)

message(WARNING ${CMAKE_BINARY_DIR})

aux_source_directory(exe EXESOURCE)
aux_source_directory(src LIBSOURCE)
SET(HEADERS
	inc/comn.h
	inc/utils.h
)

SET(3rdLIBS
	event_extra
	event_core
	libssl
	libcrypto
)

add_library(common STATIC ${LIBSOURCE} ${HEADERS})

add_executable(test ${EXESOURCE})
target_link_libraries(test common ${3rdLIBS})

