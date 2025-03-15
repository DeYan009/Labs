#include <iostream>
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
            for(int i=len;i<N_Max;i++) {
                m_value[i] = 0;
            }
            m_size = len;
        }

        // BigInt(const int& value) 
        // {
        //     BigInt(std::to_string(value));
        // }


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

int main() {
    // BigInt x;
    // std::cin >> x;
    // BigInt y("999");
    
    // BigInt z = x + y;

    // for(BigInt i = 0; i < BigInt("1000"); i+=1)
    // {

    // }

    // if(x < y)
    // {
    //     std::cout << "LESS" << std::endl;
    // }
    
    // std::cout << z << std::endl;


    // // BigInt a;
    // BigInt b("2");
    // BigInt d; // copy
    // // BigInt c = b;
    // BigInt e;
    // std::cin >> e;
    // std::cout << "b " << b << std::endl;
    // d = b + b;
    // std::cout << "d " << d << std::endl;
    // std::cout << "e " << e << std::endl;
    // b += e;
    // std::cout << "b+=e " << b << std::endl;
    // std::cout << "e " << e << std::endl;
    // std::cout << d + b;


    // 1. Проверка базового конструктора
    BigInt a; // Базовый конструктор
    std::cout << "1. Базовый конструктор: a = " << a << std::endl;

    // 2. Проверка конструктора из строки
    BigInt b("12345");
    std::cout << "2. Конструктор из строки: b = " << b << std::endl;

    // 3. Проверка конструктора копирования
    BigInt c(b);
    std::cout << "3. Конструктор копирования: c = " << c << std::endl;

    // 4. Проверка оператора присваивания
    BigInt d;
    d = c;
    std::cout << "4. Оператор присваивания: d = " << d << std::endl;

    // 5. Проверка операторов + и +=
    BigInt e("999");
    BigInt f("1");
    e += f;
    std::cout << "5. Оператор +=: e += f = " << e << std::endl;

    BigInt g = b + c;
    std::cout << "5. Оператор +: b + c = " << g << std::endl;

    // 6. Проверка операторов * и *=
    BigInt h("12");
    BigInt i("34");
    h *= i;
    std::cout << "6. Оператор *=: h *= i = " << h << std::endl;

    BigInt j = b * c;
    std::cout << "6. Оператор *: b * c = " << j << std::endl;

    // 7. Проверка операторов сравнения
    std::cout << "7. Операторы сравнения:" << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;
    std::cout << "b >= c: " << (b >= c) << std::endl;
    std::cout << "b == c: " << (b == c) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    // 8. Проверка операторов ввода и вывода
    BigInt k;
    std::cout << "8. Введите число для k: ";
    std::cin >> k;
    std::cout << "Вы ввели: " << k << std::endl;

    return 0;
}
