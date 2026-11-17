# Ищем установленный Google Test
find_package(GTest REQUIRED)

# Создаем исполняемый файл тестов
add_executable(matrix_tests test_matrix.cpp)

# Подключаем библиотеки GTest и нашу библиотеку matrix_lib
target_link_libraries(matrix_tests PRIVATE matrix_lib GTest::gtest_main)

# Регистрируем тест в CTest
add_test(NAME MatrixTests COMMAND matrix_tests)
