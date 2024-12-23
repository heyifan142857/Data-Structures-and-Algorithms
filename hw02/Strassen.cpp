#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix_multiply_standard(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    size_t n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

std::vector<std::vector<int>> matrix_add(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    size_t n = A.size();
    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            ans[i][j] = A[i][j] + B[i][j];
        }
    }
    return ans;
}

std::vector<std::vector<int>> matrix_subtract(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    size_t n = A.size();
    std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            ans[i][j] = A[i][j] - B[i][j];
        }
    }
    return ans;
}

std::vector<std::vector<int>> matrix_multiply_recursive(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, int threshold) {
    size_t n = A.size();
    if (n <= threshold) {
        return matrix_multiply_standard(A, B);
    }

    size_t mid = n / 2;

    std::vector<std::vector<int>> A11(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A21(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A22(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B11(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B21(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B22(mid, std::vector<int>(mid));

    for (size_t i = 0; i < mid; ++i) {
        for (size_t j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    auto P1 = matrix_multiply_recursive(matrix_add(A11, A22), matrix_add(B11, B22), threshold);
    auto P2 = matrix_multiply_recursive(matrix_add(A21, A22), B11, threshold);
    auto P3 = matrix_multiply_recursive(A11, matrix_subtract(B12, B22), threshold);
    auto P4 = matrix_multiply_recursive(A22, matrix_subtract(B21, B11), threshold);
    auto P5 = matrix_multiply_recursive(matrix_add(A11, A12), B22, threshold);
    auto P6 = matrix_multiply_recursive(matrix_subtract(A21, A11), matrix_add(B11, B12), threshold);
    auto P7 = matrix_multiply_recursive(matrix_subtract(A12, A22), matrix_add(B21, B22), threshold);

    auto C11 = matrix_add(matrix_subtract(matrix_add(P1, P4), P5), P7);
    auto C12 = matrix_add(P3, P5);
    auto C21 = matrix_add(P2, P4);
    auto C22 = matrix_add(matrix_subtract(matrix_add(P1, P3), P2), P6);

    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < mid; ++i) {
        for (size_t j = 0; j < mid; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> A(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> B(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> B[i][j];
        }
    }

    int threshold = 64; 
    std::vector<std::vector<int>> C = matrix_multiply_recursive(A, B, threshold);

    for (const auto &row : C) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}