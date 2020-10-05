cmake_minimum_required(VERSION 3.17)
project(postal C)

set(CMAKE_C_STANDARD 99)
find_package(SFML 2.5.0 COMPONENTS graphics)

add_executable(
        postal
        main.c
        stb/stb_image.h
        stb/stb_image_write.h
        stb/stb_image_resize.h
)

target_link_libraries(postal csfml-graphics)
