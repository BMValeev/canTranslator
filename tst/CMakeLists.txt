find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set (TESTS_SOURCES
        testUdpSender.cpp
        testCanString.cpp
        testMain.cpp
        )

include_directories(
        ../src
        ..
        PRIVATE ${Boost_INCLUDE_DIRS}
)
set (TEST test_${PROJECT_NAME})
add_executable (${TEST} ${TESTS_SOURCES} )
target_link_libraries (
        ${TEST}
#        ${PROJECT_NAME}
        canLibrary
        ${Boost_LIBRARIES}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing ()
add_test (${TEST} ${TEST})
