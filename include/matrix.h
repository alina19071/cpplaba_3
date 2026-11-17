/**
 * @file matrix.h
 * @brief Библиотека для работы с матрицами.
 * @author Alina
 * @version 0.1
 */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cmath>

/**
 * @brief Структура матрицы.
 * @warning Память освобождается через free_matrix().
 */
struct Matrix {
    double** data; ///< Указатель на двумерный массив.
    int rows;      ///< Количество строк.
    int cols;      ///< Количество столбцов.
};

Matrix create_matrix(int rows, int cols);
void free_matrix(Matrix& m);
Matrix matrix_add(const Matrix& a, const Matrix& b);
Matrix matrix_multiply(const Matrix& a, const Matrix& b);
void print_matrix(const Matrix& m);
Matrix matrix_from_array(const double* data, int rows, int cols);

/**
 * @brief Сравнивает две матрицы и выводит отличающиеся элементы (Задание 27).
 * @param a Первая матрица.
 * @param b Вторая матрица.
 */
void matrix_compare(const Matrix& a, const Matrix& b);

#endif // MATRIX_H
