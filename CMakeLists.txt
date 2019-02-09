cmake_minimum_required(VERSION 3.0.0)
project(branut VERSION 0.1.0)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_subdirectory(include)
add_subdirectory(src)

include(CTest)
enable_testing()
add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)