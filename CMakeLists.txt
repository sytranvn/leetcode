cmake_minimum_required(VERSION 3.10)
project(leetcode)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

set(CMAKE_C_COMPILER gcc)


file( GLOB CPP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp )
foreach( sourcefile ${CPP_SOURCES} )
  # I used a simple string replace, to cut off .cpp.
  get_filename_component(sourcename ${sourcefile} NAME_WE)

  add_library(${sourcename})

  target_sources(${sourcename}
      PRIVATE
        ${sourcefile}
      )
  target_link_libraries(${sourcename} ${sourcefile})
endforeach( sourcefile ${CPP_SOURCES} )

file( GLOB C_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/c/*.c )
foreach( sourcefile ${C_SOURCES} )
  # I used a simple string replace, to cut off .c.
  get_filename_component(sourcename ${sourcefile} NAME_WE)

  add_library(${sourcename})

  target_sources(${sourcename}
      PRIVATE
        ${sourcefile}
      )
  target_link_libraries(${sourcename} ${sourcefile})
endforeach( sourcefile ${C_SOURCES} )

