# CMakeList.txt: проект CMake для ufo_torrent; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.

find_package(Curses REQUIRED)
include_directories(${CURSES_INDLUDE_DIRS})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS}) 


add_library(Testing ../includes/ufo_torrent.h ufo_torrent.cpp)

add_executable(main main.cpp)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 



target_link_libraries(main PRIVATE Testing 
  ${CURSES_LIBRARIES}
  ${Boost_LIBRARIES}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.


