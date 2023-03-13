cmake_minimum_required(VERSION 3.8)
project(canTranslator)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

if (${ENABLE_TESTS})
    add_subdirectory(tst)
endif ()

list(APPEND LIBRARIES_TR
        canLibrary
        )

list(APPEND DIRECTORIES_TR
        src
        )

set(SOURCE_FILES_TR
        main.cpp
        )

include_directories( ${CMAKE_SOURCE_DIR}  ${DIRECTORIES_TR}     )
add_executable(${PROJECT_NAME}      ${SOURCE_FILES_TR}          )

target_link_libraries (${PROJECT_NAME} PUBLIC  ${LIBRARIES_TR}  )




