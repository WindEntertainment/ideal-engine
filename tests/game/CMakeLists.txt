project(native-tests)

add_executable(${PROJECT_NAME} main.cpp)

find_package(Catch2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)

target_compile_options(${PROJECT_NAME} PRIVATE --coverage)
target_link_options(${PROJECT_NAME} PRIVATE --coverage)

include(CTest)

include(Catch)
catch_discover_tests(native-tests)