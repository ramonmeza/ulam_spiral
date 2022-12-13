file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/ulam/*.hh")
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/ulam/*.cc")

add_library(ulam ${SRC_FILES} ${HEADER_LIST})

target_include_directories(ulam PUBLIC ${PROJECT_SOURCE_DIR}/include)

