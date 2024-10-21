
if(ENABLE_TESTS AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("Testing enabled")

  enable_testing()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage")

  find_program(GCOVR_EXECUTABLE NAMES gcovr)
  if (GCOVR_EXECUTABLE)
    add_custom_target(coverage
      COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/tests/coverage
      COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/tests/coverage
      COMMAND native-tests
      COMMAND gcovr --root ${CMAKE_SOURCE_DIR} --exclude '.*/tests/.*' --exclude '.*/CMakeFiles/.*' --exclude '.*/build/.*' --html --html-details -o ${CMAKE_SOURCE_DIR}/tests/coverage/index.html
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      COMMENT "Generating code coverage report..."
    )
  else()
    message(WARNING "gcovr not found, skipping coverage target.")
  endif()

  add_subdirectory(./tests/)
endif()
