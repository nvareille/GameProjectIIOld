cmake_minimum_required (VERSION 2.6)


set(PRJ test)
set(SRC ${PRJ}.cpp ${PRJ}.hpp)
project (${PRJ})

set(EXECUTABLE_OUTPUT_PATH .)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR CMAKE_COMPILER_IS_GNUCXX)
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag(--std=c++11 SUPPORTS_STD_CXX11)
    check_cxx_compiler_flag(--std=c++0x SUPPORTS_STD_CXX01)
    if(SUPPORTS_STD_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c++11")
    elseif(SUPPORTS_STD_CXX01)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++0x")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --std=c++0x")
    else()
        message(ERROR "Compiler does not support --std=c++11 or --std=c++0x.")
    endif()
endif()

OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" ON)
SET (BUILD_SHARED_LIBS TRUE)

ADD_LIBRARY(${PRJ} SHARED ${SRC})
