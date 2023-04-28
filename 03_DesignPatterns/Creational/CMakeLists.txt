add_library(SimpleBuilder SimpleBuilder.h SimpleBuilder.cpp)
add_library(FactoryMethod FactoryMethod.h FactoryMethod.cpp)

# add executable to test library
add_executable(RunSimpleBuilder RunSimpleBuilder.cpp)
target_link_libraries(RunSimpleBuilder PUBLIC SimpleBuilder)
install(TARGETS RunSimpleBuilder)

add_executable(RunFactoryMethod RunFactoryMethod.cpp)
target_link_libraries(RunFactoryMethod PUBLIC FactoryMethod)
install(TARGETS RunFactoryMethod)
