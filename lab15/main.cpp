#include <iostream>
#include <vector>
#include <algorithm>

class MyVector
{
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    MyVector()
    {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }
    MyVector(size_t size, int value)
    {
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
        for(int i=0;i<m_size;i++)
            m_arr[i] = value;

    }

    MyVector(const MyVector& other) : m_size(other.m_size), m_cap(other.m_cap)
    {
        m_arr = new int[m_cap];
        std::copy(other.m_arr, other.m_arr + m_size, m_arr);
    }

    MyVector& operator=(const MyVector& other)
    {
        if (this != &other)
        {
            delete[] m_arr;
            m_size = other.m_size;
            m_cap = other.m_cap;
            m_arr = new int[m_cap];
            std::copy(other.m_arr, other.m_arr + m_size, m_arr);
        }
        return *this;
    }

    ~MyVector()
    {
        if(m_arr != nullptr)
            delete[] m_arr;
    }

    void push_back(int value)
    {
        if(m_size + 1 <= m_cap)
        {
            m_arr[m_size] = value;
            m_size++;
            return;
        }
        m_cap = m_cap * 2 + 1;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        tmp[m_size] = value;
        delete[] m_arr;
        m_arr = tmp;
        m_size++;
    }

    void resize(size_t new_size, int value = 0)
    {
        if (new_size > m_cap)
            reserve(new_size);
        for (size_t i=m_size;i<new_size;i++)
            m_arr[i] = value;
        m_size = new_size;
    }

    void reserve(size_t cap)
    {
        if(m_size >= cap)
            return;
        m_cap = cap;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    } 

    void shrink_to_fit()
    {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    }

    void insert(size_t pos, int value)
    {
        if (pos > m_size) return;
        if (m_size >= m_cap)
            reserve(m_cap == 0 ? 1 : m_cap * 2);
        for (size_t i=m_size;i>pos;i--)
            m_arr[i] = m_arr[i - 1];
        m_arr[pos] = value;
        m_size++;
    }

    void erase(size_t pos)
    {
        if (pos >= m_size) return;
        for (size_t i=pos;i<m_size-1;i++)
            m_arr[i] = m_arr[i + 1];
        m_size--;
    }

    size_t size()
    {
        return m_size;
    }

    bool empty() const
    {
        return m_size == 0;
    }

    size_t capacity()
    {
        return m_cap;
    }

    int& operator[](size_t index)
    {
        return m_arr[index];
    }

    int& front()
    {
        return m_arr[0];
    }

    int& back()
    {
        return m_arr[m_size - 1];
    }

    // int& at(size_t index)
    // {
    //     // Проверка
    //     return m_arr[index];
    // }

    // MyVector(const MyVector&) = delete;
    // MyVector& operator=(const MyVector&) = delete;
};

#include <iostream>

int main() {
    bool all_ok = true;
    
    // 1. Проверка конструктора по умолчанию
    MyVector v1;
    bool test1 = (v1.size() == 0) && (v1.capacity() == 0);
    std::cout << "Test 1 - Default constructor: " << (test1 ? "OK" : "FAIL") << "\n";
    all_ok &= test1;

    // 2. Проверка push_back и operator[]
    v1.push_back(10);
    v1.push_back(20);
    bool test2 = (v1.size() == 2) && (v1[0] == 10) && (v1[1] == 20);
    std::cout << "Test 2 - push_back: " << (test2 ? "OK" : "FAIL") << "\n";
    all_ok &= test2;

    // 3. Проверка reserve
    v1.reserve(10);
    bool test3 = (v1.capacity() == 10) && (v1.size() == 2);
    std::cout << "Test 3 - reserve: " << (test3 ? "OK" : "FAIL") << "\n";
    all_ok &= test3;

    // 4. Проверка resize
    v1.resize(4, 30);
    bool test4 = (v1.size() == 4) && (v1[2] == 30) && (v1[3] == 30);
    std::cout << "Test 4 - resize (enlarge): " << (test4 ? "OK" : "FAIL") << "\n";
    all_ok &= test4;

    v1.resize(2);
    bool test5 = (v1.size() == 2) && (v1[0] == 10);
    std::cout << "Test 5 - resize (shrink): " << (test5 ? "OK" : "FAIL") << "\n";
    all_ok &= test5;

    // 5. Проверка shrink_to_fit
    v1.shrink_to_fit();
    bool test6 = (v1.capacity() == 2);
    std::cout << "Test 6 - shrink_to_fit: " << (test6 ? "OK" : "FAIL") << "\n";
    all_ok &= test6;

    // 6. Проверка front/back
    bool test7 = (v1.front() == 10) && (v1.back() == 20);
    std::cout << "Test 7 - front/back: " << (test7 ? "OK" : "FAIL") << "\n";
    all_ok &= test7;

    // 7. Проверка empty
    MyVector v2;
    bool test8 = (!v1.empty()) && (v2.empty());
    std::cout << "Test 8 - empty: " << (test8 ? "OK" : "FAIL") << "\n";
    all_ok &= test8;

    // 8. Проверка insert
    v1.insert(1, 15);
    bool test9 = (v1.size() == 3) && (v1[1] == 15);
    std::cout << "Test 9 - insert: " << (test9 ? "OK" : "FAIL") << "\n";
    all_ok &= test9;

    // 9. Проверка erase
    v1.erase(0);
    bool test10 = (v1.size() == 2) && (v1[0] == 15);
    std::cout << "Test 10 - erase: " << (test10 ? "OK" : "FAIL") << "\n";
    all_ok &= test10;

    // 10. Проверка конструктора копирования
    MyVector v3(v1);
    bool test11 = (v3.size() == 2) && (v3[0] == 15);
    std::cout << "Test 11 - copy constructor: " << (test11 ? "OK" : "FAIL") << "\n";
    all_ok &= test11;

    // 11. Проверка оператора присваивания
    MyVector v4;
    v4 = v1;
    bool test12 = (v4.size() == 2) && (v4[1] == 20);
    std::cout << "Test 12 - assignment: " << (test12 ? "OK" : "FAIL") << "\n";
    all_ok &= test12;

    // 12. Проверка инициализирующего конструктора
    MyVector v5(3, 100);
    bool test13 = (v5.size() == 3) && (v5[0] == 100);
    std::cout << "Test 13 - init constructor: " << (test13 ? "OK" : "FAIL") << "\n";
    all_ok &= test13;

    // Итоговый результат
    std::cout << "\nAll tests " << (all_ok ? "PASSED" : "FAILED") << "\n";
    
    return 0;
}
