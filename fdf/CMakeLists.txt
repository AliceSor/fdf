cmake_minimum_required(VERSION 3.6)
project(fdf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

set(SOURCE_FILES main.c
        lists.c
        create.c
        put_line.c
        put_line1.c
        put_line2.c
        put_pixel.c
        foreachpoint.c
        calculate.c
        fill_down.c
        zoom.c
        print_map.c
        rotation.c
        calc.c)

add_executable(fdf ${SOURCE_FILES})
target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/libft/libft.a)