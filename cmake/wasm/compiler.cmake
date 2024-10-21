set(CMAKE_C_COMPILER "emcc")
set(CMAKE_CXX_COMPILER "em++")

###===================================================================================##

set_target_properties(${PROJECT_NAME} PROPERTIES
  OUTPUT_NAME "wind"
  LINK_FLAGS "-O3"
)

###===================================================================================##
