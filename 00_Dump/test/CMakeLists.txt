add_executable(ExeUniquePtr ExeUniquePtr.cpp)
install(TARGETS ExeUniquePtr)

add_executable(ConstantExpression ConstexprConst.cpp)
install(TARGETS ConstantExpression)

add_executable(ConcurrencyTest ConcurrencyTest.cpp)
install(TARGETS ConcurrencyTest)