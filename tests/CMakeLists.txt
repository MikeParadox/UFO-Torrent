find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(ufo_tests test.cpp)
target_link_libraries(ufo_tests Testing GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(ufo_tests)
add_test(NAME ufo_tests_lib COMMAND tests)