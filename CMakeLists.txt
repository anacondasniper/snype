cmake_minimum_required(VERSION 3.13)
project(snype C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

add_executable(snype
	src/main.c
	src/input.c
)

target_include_directories(snype PRIVATE
	${SDL2_INCLUDE_DIRS}
	src/
)

target_link_libraries(snype
	SDL2
	m
)
