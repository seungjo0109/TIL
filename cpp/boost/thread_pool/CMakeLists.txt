cmake_minimum_required(VERSION 2.8.3)
project(boost_thread_pool)

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)

find_package(Boost COMPONENTS
    thread REQUIRED
)

include_directories(
    ${Boost_INCLUDE_DIRS}

    ${PROJECT_INCLUDE_DIR}/
    ${PROJECT_INCLUDE_DIR}/task/
    #TODO
    #${PROJECT_INCLUDE_DIR}/thread_pool/
)

add_executable(${PROJECT_NAME}

    ${PROJECT_SOURCE_DIR}/main.cpp

    ${PROJECT_SOURCE_DIR}/task/task_base.cpp
    ${PROJECT_SOURCE_DIR}/task/task_module.cpp

    # TODO
    #${PROJECT_SOURCE_DIR}/thread_pool/thread_pool_manager.cpp
)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})