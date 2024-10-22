project(editor)

set(HEADERS
  ./include/editor/logger.hpp
)

set(SOURCES
  ./src/main.cpp
)

add_executable( ${PROJECT_NAME}
                ${HEADERS}
                ${SOURCES}
                ./include/bindings/imgui_impl_sdl2.cpp
                ./include/bindings/imgui_impl_sdl2.h
                ./include/bindings/imgui_impl_opengl3.cpp
                ./include/bindings/imgui_impl_opengl3.h
                ./include/bindings/imgui_impl_opengl3_loader.h
                )

find_package(imgui REQUIRED)
find_package(sdl2 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC imgui::imgui SDL2::SDL2 OpenGL::GL)
target_link_libraries(${PROJECT_NAME} PUBLIC wind-utils)

target_include_directories(${PROJECT_NAME} PUBLIC ./include/)
