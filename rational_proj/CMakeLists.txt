#add_executable(test_doctest test_doctest.cpp)

add_subdirectory(rational)
add_executable(main rational_test.cpp)
#add_executable(test_doctest rational_test.cpp)
target_link_libraries(main rational)
