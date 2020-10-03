cmake_minimum_required(VERSION 3.17)
project(image)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(
        image
        main.cpp
        param.h
        param.c
        image.cpp
        image.h
        stb/stb_image.h
        stb/stb_image_write.h
        stb/stb_image_resize.h
)
target_link_libraries(image sfml-system sfml-window sfml-graphics)