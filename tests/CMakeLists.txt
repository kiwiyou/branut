include_directories(${CMAKE_SOURCE_DIR}/src)

list(APPEND branut_TESTS
    basic_variable)

FOREACH(TARGET_NAME IN ITEMS ${branut_TESTS})
    add_executable(test_${TARGET_NAME} test_${TARGET_NAME}.cpp)
    add_test(${TARGET_NAME} test_${TARGET_NAME})
    target_link_libraries(test_${TARGET_NAME} branut)
ENDFOREACH()