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
        stringReader.cpp
        udpSender.cpp

        dataLoader.cpp dataLoader.h argParser.cpp argParser.h)

add_library(${PROJECT_NAME}        ${SOURCE_FILES_CAN}   )

#add_subdirectory(videofiles)
#add_subdirectory(comcpp)

include_directories(${DIRECTORIES_CAN})
link_directories(${DIRECTORIES_CAN})
target_link_libraries (${PROJECT_NAME}   ${LIBRARY_CAN}  )

