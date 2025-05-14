#include <iostream>

template <typename T, size_t N, size_t M>
class Matrix
{
private:
    T m_matrix[N][M];

public:
    Matrix()
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                m_matrix[i][j] = T();
            }
        }
    }

    Matrix(const Matrix& other)
    {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j)
            {
                m_matrix[i][j] = other.m_matrix[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other)
    {
        if (this != &other)
        {
            for (size_t i = 0; i < N; ++i)
            {
                for (size_t j = 0; j < M; ++j)
                {
                    m_matrix[i][j] = other.m_matrix[i][j];
                }
            }
        }
        return *this;
    }

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                os << matrix.data[i][j] << ' ';
            }
            if (i != N - 1) os << '\n';
        }
        return os;
    }

    Matrix operator+(const Matrix& other) const
    {
        Matrix res;
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                res.m_matrix[i][j] = m_matrix[i][j] + other.m_matrix[i][j];
            }
        }
        return res;
    }

    Matrix& operator+=(const Matrix& other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                m_matrix[i][j] += other.m_matrix[i][j];
            }
        }
        return *this;
    }


    template <size_t K>
    Matrix<T, N, K> operator*(const Matrix<T, M, K>& other) const
    {
        Matrix<T, N, K> res;
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < K; ++j)
            {
                res(i, j) = T();
                for (size_t k = 0; k < M; ++k)
                {
                    res(i, j) += m_matrix[i][k] * other.m_matrix[k][j];
                }
            }
        }
        return res;
    }

    Matrix& operator*=(const T& scalar)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                data[i][j] *= scalar;
            }
        }
        return *this;
    }

    Matrix& operator++()
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                ++m_matrix[i][j];
            }
        }
        return *this;
    }

    Matrix operator++(int)
    {
        Matrix temp(*this);
        ++(*this);
        return temp;
    }

    // Метод вычисления определителя (только для квадратных матриц)
    T determinant() const {
        static_assert(N == M, "Determinant is only defined for square matrices");
        
        if constexpr (N == 1) {
            return data[0][0];
        } else if constexpr (N == 2) {
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        } else if constexpr (N == 3) {
            return data[0][0] * data[1][1] * data[2][2] +
                   data[0][1] * data[1][2] * data[2][0] +
                   data[0][2] * data[1][0] * data[2][1] -
                   data[0][2] * data[1][1] * data[2][0] -
                   data[0][0] * data[1][2] * data[2][1] -
                   data[0][1] * data[1][0] * data[2][2];
        }
    }

    T& operator()(size_t i, size_t j)
    {
        return data[i][j];
    }
};

int main() {
    // Демонстрация работы с классом
    
    // Создание и ввод матрицы 2x2
    Matrix<int, 2, 2> mat1;
    std::cout << "Enter 4 elements for 2x2 matrix:\n";
    std::cin >> mat1;
    std::cout << "Matrix 1:\n" << mat1 << "\n\n";

    // Создание и ввод второй матрицы 2x2
    Matrix<int, 2, 2> mat2;
    std::cout << "Enter 4 elements for second 2x2 matrix:\n";
    std::cin >> mat2;
    std::cout << "Matrix 2:\n" << mat2 << "\n\n";

    // Сложение матриц
    auto sum = mat1 + mat2;
    std::cout << "Sum of matrices:\n" << sum << "\n\n";

    // Умножение матриц
    auto product = mat1 * mat2;
    std::cout << "Product of matrices:\n" << product << "\n\n";

    // Вычисление определителя
    std::cout << "Determinant of matrix 1: " << mat1.determinant() << "\n\n";

    // Инкремент матрицы
    std::cout << "Matrix 1 after increment:\n" << ++mat1 << "\n\n";

    // Работа с вектором (матрица 3x1)
    Matrix<double, 3, 1> vec;
    vec(0, 0) = 1.5;
    vec(1, 0) = 2.5;
    vec(2, 0) = 3.5;
    std::cout << "Vector:\n" << vec << "\n\n";

    // Умножение матрицы на скаляр
    mat1 *= 2;
    std::cout << "Matrix 1 multiplied by 2:\n" << mat1 << "\n\n";

    // Доступ к элементам по индексу
    std::cout << "Element (1,1) of matrix 1: " << mat1(1, 1) << "\n\n";

    return 0;
}