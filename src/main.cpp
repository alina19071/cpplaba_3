#include "matrix.h"
#include <iostream>

int main() {
    double arrA[] = {1, 2, 3, 4};
    double arrB[] = {1, 5, 3, 4};
    Matrix A = matrix_from_array(arrA, 2, 2);
    Matrix B = matrix_from_array(arrB, 2, 2);

    std::cout << "Matrix A:\n"; print_matrix(A);
    std::cout << "Matrix B:\n"; print_matrix(B);
    std::cout << "\n--- Task 27: matrix_compare ---\n";
    matrix_compare(A, B);

    free_matrix(A);
    free_matrix(B);
    return 0;
}
