cmake_minimum_required(VERSION 3.10)

project(TestApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(INFO "System processor: ${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install/${CMAKE_SYSTEM_PROCESSOR})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Add the executable
add_subdirectory(00_Dump)
add_subdirectory(01_PolicyBasedClassDesign)
add_subdirectory(02_PartialTemplateSpecialization)