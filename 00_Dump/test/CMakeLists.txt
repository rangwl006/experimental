#add_executable(ExeUniquePtr ExeUniquePtr.cpp)
#install(TARGETS ExeUniquePtr)
#
#add_executable(ConstantExpression ConstexprConst.cpp)
#install(TARGETS ConstantExpression)
#
#add_executable(ConcurrencyTest ConcurrencyTest.cpp)
#target_link_libraries(ConcurrencyTest curl)
#install(TARGETS ConcurrencyTest)
#
#add_executable(SmartPointers SmartPointers.cpp)
#install(TARGETS SmartPointers)
#
#add_executable(BreadthFirstSearch BreadthFirstSearch.cpp)
#install(TARGETS BreadthFirstSearch)
#
#add_executable(FuturePromise FuturePromise.cpp)
#target_link_libraries(FuturePromise PUBLIC asio)
#install(TARGETS FuturePromise)

#add_executable(ScopedThread ScopedThread.cpp)
#install(TARGETS ScopedThread)

add_executable(UniquePointers UniquePointers.cpp)
install(TARGETS UniquePointers)