add_executable(PartialTemplateSpecializationTest main.cpp)
target_link_libraries(PartialTemplateSpecializationTest PUBLIC PartialTemplateSpecialization)
target_include_directories(PartialTemplateSpecializationTest PUBLIC ${CMAKE_SOURCE_DIR}/02_PartialTemplateSpecialization/inc)
install(TARGETS PartialTemplateSpecializationTest)