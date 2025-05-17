#include <iostream>
#include <stdexcept>
// #include <cassert>
#include <string>


#define N_Max 1000

class BigInt 
{
    char m_value[N_Max];
    short m_size = 0;

    public:
        BigInt() = default;
        
        BigInt(const std::string& value) 
        {
            size_t len = value.length();
            for(int i=0;i<len;i++)
                m_value[i] = value[len-i-1] - '0';
            for(int i=len;i<N_Max;i++)
            {
                m_value[i] = 0;
            }
            m_size = len;
        }

        BigInt(const BigInt& other) 
        {
            for(int i = 0; i < N_Max; i++)
            {
                m_value[i] = other.m_value[i];
            }
            m_size = other.m_size;
        }

        BigInt& operator=(const BigInt& other) 
        {
            if (this != &other)
            {
                for(int i = 0; i < N_Max; i++)
                {
                    m_value[i] = other.m_value[i];
                }
                m_size = other.m_size;
            }
        return *this;
        }

        ~BigInt() = default;

        BigInt& operator+=(const BigInt& other)
        {
            int carry = 0;
            int max_size = (m_size > other.m_size) ? m_size : other.m_size;

            for (int i = 0; i < max_size || carry; i++)
            {
                if (i < m_size)
                {
                    carry += m_value[i];
                }
                if (i < other.m_size)
                {
                    carry += other.m_value[i];
                }

                m_value[i] = carry % 10;
                carry = carry / 10;

                if (i >= m_size)
                {
                    m_size++;
                }
            }

            return *this;
        }

        BigInt& operator+=(int other)
        {
            *this += BigInt(std::to_string(other));
            return *this;
        }

        BigInt operator+(const BigInt& other)
        {
            BigInt result(*this);
            result += other;
            return result;
        }

        BigInt& operator*=(const BigInt& other)
        {
            BigInt result("0");

            for (int i = 0; i < other.m_size; i++) 
            {
                BigInt temp("0");
                int carry = 0;
                for (int j = 0; j < m_size || carry; j++) 
                {
                    int product = carry;
                    if (j < m_size)
                    {
                        product += m_value[j] * other.m_value[i];
                    }
                    temp.m_value[j] = product % 10;
                    carry = product / 10;
        
                    if (j >= temp.m_size) 
                    {
                        temp.m_size++;
                    }
                }
        
                for (int j = temp.m_size - 1; j >= 0; j--)
                {
                    temp.m_value[j + i] = temp.m_value[j];
                }
                for (int j = 0; j < i; j++)
                {
                    temp.m_value[j] = 0;
                }
                temp.m_size += i;
        
                result += temp;
            }
        
            *this = result;
            return *this;
        }

        BigInt operator*(const BigInt& other)
        {
            BigInt result(*this);
            result *= other;
            return result;
        }

        bool operator<(const BigInt& other)
        {
            if(m_size < other.m_size)
                return true;
            else if(m_size > other.m_size)
                return false;
            else
            {
                for(int i=m_size-1;i>=0;i--)
                {
                    if(m_value[i] < other.m_value[i])
                        return true;
                    else if(m_value[i] > other.m_value[i])
                        return false;
                }
                return false;
            }
        }

        bool operator>=(const BigInt& other)
        {
            return !(*this < other);
        }

        bool operator==(const BigInt& other)
        {
            if(m_size != other.m_size)
                return false;
            for(int i = 0; i < m_size; i++) {
                if(m_value[i] != other.m_value[i])
                    return false;
            }
            return true;
        }

        bool operator!=(const BigInt& other)
        {
            return !(*this == other);
        }

        bool operator>(const BigInt& other)
        {
            return !(*this < other) && (*this != other);
        }

        bool operator<=(const BigInt& other)
        {
            return !(*this > other);
        }

        BigInt operator++(int)
        {
            BigInt result(*this);
            *this += BigInt("1");
            return result;
        }

        BigInt& operator++()
        {
            *this += BigInt("1");
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
};

std::istream& operator>>(std::istream& in, BigInt& other)
{
    std::string s;
    in >> s;
    other = BigInt(s);
    return in;
}

std::ostream& operator<<(std::ostream& out, const BigInt& other)
{
    for(int i=0;i<other.m_size;i++)
    {
        out << static_cast<short>(other.m_value[other.m_size - i - 1]);
    }
    return out;
}


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

    // // Конструктор для инициализации списком
    // Matrix(std::initializer_list<std::initializer_list<T>> init)
    // {
    //     size_t i = 0;
    //     for (const auto& row : init)
    //     {
    //         size_t j = 0;
    //         for (const auto& val : row)
    //         {
    //             if (i < N && j < M)
    //             {
    //                 m_matrix[i][j] = val;
    //             }
    //             j++;
    //         }
    //         i++;
    //     }
    // }

    // Matrix(const Matrix& other)
    // {
    //     for (size_t i = 0; i < N; ++i)
    //     {
    //         for (size_t j = 0; j < M; ++j)
    //         {
    //             m_matrix[i][j] = other.m_matrix[i][j];
    //         }
    //     }
    // }

    // Matrix& operator=(const Matrix& other)
    // {
    //     if (this != &other)
    //     {
    //         for (size_t i = 0; i < N; ++i)
    //         {
    //             for (size_t j = 0; j < M; ++j)
    //             {
    //                 m_matrix[i][j] = other.m_matrix[i][j];
    //             }
    //         }
    //     }
    //     return *this;
    // }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                is >> matrix.m_matrix[i][j];
            }
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                os << matrix.m_matrix[i][j] << ' ';
            }
            if (i != N - 1) os << '\n';
        }
        return os;
    }
    template <typename U, size_t N2, size_t M2>
    Matrix<T, N, M> operator+(const Matrix<U, N2, M2>& other) const
    {
        static_assert(N == N2 && M == M2, "Matrix dimensions must match for addition");
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

    template <size_t N2, size_t M2>
    Matrix<T, N, M2> operator*(const Matrix<T, N2, M2>& other) const
    {
        static_assert(M == N2, 
            "Number of columns in the first matrix must match rows in the second");

        Matrix<T, N, M2> res;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M2; ++j) {
                res(i, j) = T();
                for (size_t k = 0; k < M; ++k) {
                    res(i, j) += (*this)(i, k) * other(k, j);
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
                m_matrix[i][j] *= scalar;
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

    T determinant() const
    {
        static_assert(N == M, "Determinant is only defined for square matrices");
        
        if constexpr (N == 1)
        {
            return m_matrix[0][0];
        }
        else if constexpr (N == 2)
        {
            return m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];
        }
        else
        {
            T det = 0;
            for (size_t col = 0; col < N; ++col)
            {
                // Минор
                Matrix<T, N-1, N-1> minor;
                for (size_t i = 1; i < N; ++i)
                {
                    size_t minor_col = 0;
                    for (size_t j = 0; j < N; ++j)
                    {
                        if (j == col) continue;
                        minor(i-1, minor_col++) = m_matrix[i][j];
                    }
                }
                
                // Рекурсия
                T sign = (col % 2 == 0) ? 1 : -1;
                det += sign * m_matrix[0][col] * minor.determinant();
            }
            return det;
        }
    }

    T& operator()(size_t i, size_t j)
    {
        return m_matrix[i][j];
    }
    const T& operator()(size_t i, size_t j) const
    {
        return m_matrix[i][j];
    }

    // constexpr size_t Rows() const noexcept { return N; }
    // constexpr size_t Cols() const noexcept { return M; }
};


// void test_determinant() {
//     // Тест 1: Матрица 1x1
//     {
//         Matrix<int, 1, 1> mat = {{5}};
//         std::cout << "1x1 matrix det: " << mat.determinant();
//         assert(mat.determinant() == 5);
//         std::cout << "OK\n";
//     }

//     // Тест 2: Матрица 2x2
//     {
//         Matrix<int, 2, 2> mat = {{1, 2}, 
//                                 {3, 4}};
//         std::cout << "2x2 matrix det: " << mat.determinant();
//         assert(mat.determinant() == -2);
//         std::cout << "OK\n";
//     }

//     // Тест 3: Матрица 3x3 (нулевой определитель)
//     {
//         Matrix<int, 3, 3> mat = {{1, 2, 3},
//                                 {4, 5, 6},
//                                 {7, 8, 9}};
//         std::cout << "3x3 matrix det: " << mat.determinant();
//         assert(mat.determinant() == 0);
//         std::cout << " OK\n";
//     }

//     // Тест 4: Матрица 3x3 (ненулевой определитель)
//     {
//         Matrix<int, 3, 3> mat = {{1, 0, 2},
//                                 {0, 3, 0},
//                                 {4, 0, 5}};
//         std::cout << "3x3 matrix det: " << mat.determinant();
//         assert(mat.determinant() == -9);
//         std::cout << "OK\n";
//     }

//     std::cout << "All simple tests passed!\n";
// }

int main() {
    
    // Создание и ввод матрицы 2x2
    Matrix<BigInt, 2, 2> mat1;
    std::cout << "Enter 4 elements for 2x2 matrix:\n";
    std::cout << "Matrix 1:\n" << mat1 << "\n\n";
    std::cin >> mat1;
    std::cout << "Matrix 1:\n" << mat1 << "\n\n";

    // Создание и ввод второй матрицы 2x2
    Matrix<BigInt, 2, 2> mat2;
    std::cout << "Enter 4 elements for second 2x2 matrix:\n";
    std::cin >> mat2;
    std::cout << "Matrix 2:\n" << mat2 << "\n\n";
    Matrix<BigInt, 2, 2> mat3;
    mat3 = mat2;
    std::cout << "Matrix 3:\n" << mat3 << "\n\n";

    // // Сложение матриц
    // auto sum = mat1 + mat2;
    // std::cout << "Sum of matrices:\n" << sum << "\n\n";

    // // Умножение матриц
    // auto product = mat1 * mat2;
    // std::cout << "Product of matrices:\n" << product << "\n\n";

    // // Вычисление определителя
    // std::cout << "Determinant of matrix 1: " << mat1.determinant() << "\n\n";

    // Инкремент матрицы
    std::cout << "Matrix 1 after increment:\n" << ++mat1 << "\n\n";

    // // Работа с вектором (матрица 3x1)
    // Matrix<double, 3, 1> vec;
    // vec(0, 0) = 1.5;
    // vec(1, 0) = 2.5;
    // vec(2, 0) = 3.5;
    // std::cout << "Vector:\n" << vec << "\n\n";

    // // Умножение матрицы на скаляр
    // mat1 *= 2;
    // std::cout << "Matrix 1 multiplied by 2:\n" << mat1 << "\n\n";

    // // Доступ к элементам по индексу
    // std::cout << "Element (1,1) of matrix 1: " << mat1(1, 1) << "\n\n";






    // Matrix<int, 2, 3> matA;
    // Matrix<int, 2, 3> matB;
    // Matrix<int, 3, 4> matC;

    // // === Тест 1: Сложение матриц одинакового размера (должно работать) ===
    // std::cout << "Test 1: Correct addition\n";
    // auto matSum = matA + matB;  // OK: 2x3 + 2x3

    // // === Тест 2: Сложение матриц разного размера (должно НЕ компилироваться) ===
    // std::cout << "Test 2: Invalid addition (uncomment to see error)\n";
    // // auto matSumError = matA + matC;  // Ошибка: 2x3 + 3x4

    // // === Тест 3: += с матрицей неверного размера ===
    // std::cout << "Test 3: Invalid += (uncomment to see error)\n";
    // matA += matB;  // Ошибка: 2x3 += 3x4

    // // === Тест 4: Умножение совместимых матриц (должно работать) ===
    // std::cout << "Test 4: Correct multiplication\n";
    // // auto matMul = matA * matC;  // OK: 2x3 * 3x4 = 2x4
    // // std::cout << "Matrix 1:\n" << matMul << "\n\n";

    // // === Тест 5: Умножение несовместимых матриц (должно НЕ компилироваться) ===
    // std::cout << "Test 5: Invalid multiplication (uncomment to see error)\n";
    // auto matMulError = matA * matB;  // Ошибка: 2x3 * 2x3 (3 != 2)

    // // === Тест 6: *= с несовместимой матрицей ===
    // Matrix<int, 2, 2> matD;
    // std::cout << "Test 6: Invalid *= (uncomment to see error)\n";
    // // matA *= matD;  // Ошибка: 2x3 *= 2x2

    // std::cout << "All tests passed (or failed correctly)!\n";
    // test_determinant();

    return 0;
}