project(game)

set(HEADERS
  ./include/game/logger.hpp
)

set(SOURCES
  ./src/main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ./include/)