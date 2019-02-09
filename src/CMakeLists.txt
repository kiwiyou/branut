set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(branut_SOURCES
    Variable.cpp
    Term.cpp)

add_library(branut ${branut_SOURCES})