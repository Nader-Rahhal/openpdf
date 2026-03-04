cmake_minimum_required(VERSION 3.15...4.1)
project(OpenPDF VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FLTK REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(POPPLER REQUIRED IMPORTED_TARGET poppler-cpp)

add_executable(main src/Main.cpp)
target_include_directories(main PUBLIC include /opt/homebrew/include)
target_link_libraries(main PRIVATE ${FLTK_LIBRARIES} PkgConfig::POPPLER)


