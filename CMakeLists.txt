cmake_minimum_required(VERSION 3.10)

project(TestApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(INFO "System processor: ${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/${CMAKE_SYSTEM_PROCESSOR})

# Add the executable
add_executable(testProject main.cpp)
install(TARGETS testProject)

add_subdirectory(test)