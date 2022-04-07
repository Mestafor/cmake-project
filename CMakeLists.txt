cmake_minimum_required (VERSION 3.16.3)

# # C++ 2017
# target_compile_features(myapp cxx_std_17)
# # C++ 2014
# target_compile_features(myapp cxx_std_14)
# # C++ 2011
# target_compile_features(myapp cxx_std_11)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin )

if (WIN32)
    set(CMAKE_GENERATOR "Ninja") # set your generator
    message("Win32 used, generator is set to ${CMAKE_GENERATOR}")
endif (WIN32)

# Download all submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodule during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        message("GIT_SUBMOD_RESULT: ${GIT_SUBMOD_RESULT} ${GIT_EXECUTABLE}")
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "`git submodule update --init --recursive` failed with ${GIT_SUBMOD_RESULT}, please check submodules")
        endif()
    endif()
endif()

# Check all the submodules
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not downloaded! GIT_SUBMODULE was turned off or failed. Please check glfw submodule.")
endif()

project(cmake_project)
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw)

# #include "GLFW/glfw3.h"
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
)

target_link_libraries(${PROJECT_NAME} glfw)

