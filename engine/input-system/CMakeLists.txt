project(wind-input-system)

set(HEADERS
    ./include/input-system/input-system.h
    ./include/input-system/mouse-context.h
    ./include/input-system/keyboard-context.h
    ./include/input-system/context.h
    ./include/input-system/keys.h
    ./include/input-system/trigger.h
    ./include/input-system/error.h

)

set(SOURCES
    ./src/input-system.cpp
    ./src/triggers/keycode-triggers.cpp
    ./src/triggers/grouped-triggers.cpp
    ./src/context/mouse-context.cpp
    ./src/context/keyboard-context.cpp
    ./src/context/context.cpp
    ./src/context/keys.cpp
    ./src/triggers/trigger.cpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ./include/)

# internal depencencies

target_link_libraries(${PROJECT_NAME} PUBLIC wind-utils)
target_link_libraries(${PROJECT_NAME} PRIVATE wind-asset-manager)

# extrenal depencencies

find_package(yaml-cpp REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp::yaml-cpp)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2)