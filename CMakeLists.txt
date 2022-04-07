cmake_minimum_required (VERSION 3.16.3)

# # C++ 2017
# target_compile_features(myapp cxx_std_17)
# # C++ 2014
# target_compile_features(myapp cxx_std_14)
# # C++ 2011
# target_compile_features(myapp cxx_std_11)

if (WIN32)
    set(CMAKE_GENERATOR "Ninja") # set your generator
    message("Win32 used, generator is set to ${CMAKE_GENERATOR}")
endif (WIN32)

project(cmake_project)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin )

add_executable(${PROJECT_NAME} main.cpp)