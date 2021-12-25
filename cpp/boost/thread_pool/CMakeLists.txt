cmake_minimum_required(VERSION 2.8.3)
project(boost_thread_pool)

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/)
set(PROJECT_INCLUD_DIR ${CMAKE_SOURCE_DIR}/include/)

find_package(Boost COMPONENTS
    thread REQUIRED
)

include_directories(
    ${Boost_INCLUDE_DIRS}

    ${PROJECT_INCLUDE_DIR}/
)

add_executable(${PROJECT_NAME}

    ${PROJECT_SOURCE_DIR}/main.cpp

)