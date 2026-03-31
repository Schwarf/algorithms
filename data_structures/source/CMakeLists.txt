# Specify project
project(data_structures)

# Include required directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Gather all source files in subdirectories
file(GLOB_RECURSE H_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# Create a library for each subdirectory
file(GLOB SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach (SUBDIR ${SUBDIRS})
    if (IS_DIRECTORY ${SUBDIR} AND NOT SUBDIR STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}/test")
        file(GLOB LIB_SOURCES "${SUBDIR}/*.cpp" "${SUBDIR}/*.h")
        if (LIB_SOURCES)
            get_filename_component(SUBDIR_NAME ${SUBDIR} NAME)
            add_library(${SUBDIR_NAME}_lib INTERFACE ${LIB_SOURCES})
            target_include_directories(${SUBDIR_NAME}_lib INTERFACE ${SUBDIR})
        endif ()
    endif ()
endforeach ()

# Add test subdirectory
add_subdirectory(test)
