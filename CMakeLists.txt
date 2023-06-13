cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )
foreach( sourcefile ${APP_SOURCES} )
    # I used a simple string replace, to cut off .cpp.
    get_filename_component(exename ${sourcefile} NAME_WE)
    add_executable( ${exename} ${sourcefile} )
endforeach( sourcefile ${APP_SOURCES} )
