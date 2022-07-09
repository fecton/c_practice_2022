project(summer_practice_2022)
set(CMAKE_PROJECT_VERSION 1.0)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	tests
	tests.cc
)
target_link_libraries(
	tests
	gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)




