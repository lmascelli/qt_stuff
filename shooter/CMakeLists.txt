cmake_minimum_required(VERSION 3.10)
project(shooter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(QT_COMPONENTS
  Widgets)

list(APPEND CMAKE_PREFIX_PATH ${Qt6_DIR})
find_package(Qt6 COMPONENTS ${QT_COMPONENTS} REQUIRED)

add_executable(shooter
  src/main.cpp
  src/player.cpp
  src/player.h
  src/bullet.cpp
  src/bullet.h
  src/game.cpp
  src/game.h
  )
target_include_directories(shooter PRIVATE ${Qt6_INCLUDE_DIRS})

set(COMPONENT_LIBRARIES ${QT_COMPONENTS})
list(TRANSFORM COMPONENT_LIBRARIES PREPEND "Qt6::")
target_link_libraries(shooter PRIVATE ${COMPONENT_LIBRARIES})
