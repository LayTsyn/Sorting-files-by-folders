cmake_minimum_required(VERSION 3.22)

project(sf
	VERSION 1.0.0
	LANGUAGES CXX)
set(CMAKE_CXX_STANDART 17)

include_directories(include)

file(GLOB SOURCES "sources/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
