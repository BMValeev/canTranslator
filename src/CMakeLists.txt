project(canLibrary)
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)


list(APPEND LIBRARY_CAN

        )

list(APPEND DIRECTORIES_CAN

        )

set(SOURCE_FILES_CAN
        canString.cpp
        processController.cpp
        udpSender.cpp
        dataLoader.cpp
        argParser.cpp
        )

add_library(${PROJECT_NAME}        ${SOURCE_FILES_CAN}   )


include_directories(${DIRECTORIES_CAN})
link_directories(${DIRECTORIES_CAN})
target_link_libraries (${PROJECT_NAME}   ${LIBRARY_CAN}  )

