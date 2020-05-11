cmake_minimum_required(VERSION 3.5)

project(symple_meta_001 ${PROJECT_NAME} LANGUAGES CXX)

set(SOURCES
    main.cpp
    simpl_meta.cpp)
set(HEADERS
    simpl_meta.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-depth=2800")

find_package(Boost ${BOOST_MIN_VERSION} COMPONENTS context system regex)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})
