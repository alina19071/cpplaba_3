#include "matrix.h"

Matrix create_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Matrix dimensions must be positive integers");
    }
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new double*[rows];
    try {
        for (int i = 0; i < rows; ++i) {
            mat.data[i] = new double[cols](); 
        }
    } catch (...) {
        for (int i = 0; i < rows; ++i) delete[] mat.data[i];
        delete[] mat.data;
        throw; 
    }
    return mat;
}

void free_matrix(Matrix& m) {
    if (m.data == nullptr) return;
    for (int i = 0; i < m.rows; ++i) {
        delete[] m.data[i];
        m.data[i] = nullptr;
    }
    delete[] m.data;
    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;
}

Matrix matrix_add(const Matrix& a, const Matrix& b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    Matrix result = create_matrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix matrix_multiply(const Matrix& a, const Matrix& b) {
    if (a.cols != b.rows) {
        throw std::invalid_argument("Matrix dimensions are incompatible for multiplication");
    }
    Matrix result = create_matrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < b.cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < a.cols; ++k) {
                sum += a.data[i][k] * b.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

void print_matrix(const Matrix& m) {
    if (m.data == nullptr || m.rows <= 0 || m.cols <= 0) {
        std::cout << "[Empty matrix]" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < m.rows; ++i) {
        std::cout << "[";
        for (int j = 0; j < m.cols; ++j) {
            std::cout << std::setw(6) << m.data[i][j];
            if (j < m.cols - 1) std::cout << " ";
        }
        std::cout << "]" << std::endl;
    }
}

Matrix matrix_from_array(const double* data, int rows, int cols) {
    if (data == nullptr || rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Invalid data or dimensions");
    }
    Matrix m = create_matrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.data[i][j] = data[i * cols + j];
        }
    }
    return m;
}

void matrix_compare(const Matrix& a, const Matrix& b) {
    if (a.data == nullptr || b.data == nullptr || a.rows <= 0 || b.rows <= 0) {
        throw std::invalid_argument("Invalid matrices for comparison");
    }
    if (a.rows != b.rows || a.cols != b.cols) {
        std::cout << "Matrix dimensions mismatch!\n";
        return;
    }
    bool has_differences = false;
    std::cout << "Differences found:\n";
    const double EPS = 1e-9; 
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            if (std::abs(a.data[i][j] - b.data[i][j]) > EPS) {
                std::cout << "  Element [" << i << "][" << j << "]: " 
                          << a.data[i][j] << " (A) != " << b.data[i][j] << " (B)\n";
                has_differences = true;
            }
        }
    }
    if (!has_differences) {
        std::cout << "  No differences found. Matrices are equal.\n";
    }
}
