#include <iostream>
#include <stdexcept>

struct BitRef
{
    char* m_value;
    size_t m_index;
    
    BitRef(char* value, size_t index) : m_value(value), m_index(index) {}
    
    operator bool() const
    {
        size_t num = m_index / 8;
        size_t offset = m_index % 8;
        return m_value[num] & (1 << offset);
    }
    
    BitRef& operator=(bool v)
    {
        size_t num = m_index / 8;
        size_t offset = m_index % 8;
        
        if (v)
            m_value[num] |= (1 << offset);
        else
            m_value[num] &= ~(1 << offset);
            
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const BitRef& b)
{
    out << static_cast<bool>(b);
    return out;
}

template<typename T>
class MyVector
{
public:
    void print()
    {
        std::cout << "all types" << std::endl;
    }
};

template<>
class MyVector<bool>
{
private:
    char* m_data;
    size_t m_size;
    size_t m_cap;
    
    void resize(size_t new_cap)
    {
        size_t byte_need = (new_cap + 7) / 8;
        char* new_data = new char[byte_need]();
        
        size_t byte_copy = (m_size + 7) / 8;
        for (size_t i = 0; i < byte_copy; ++i)
        {
            new_data[i] = m_data[i];
        }
        
        delete[] m_data;
        m_data = new_data;
        m_cap = new_cap;
    }
    
public:
    MyVector() : m_data(new char[1]()), m_size(0), m_cap(8) {}
    
    ~MyVector()
    {
        delete[] m_data;
    }
    
    BitRef operator[](size_t index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return BitRef(m_data, index);
    }

    void push_back(bool value)
    {
        if (m_size >= m_cap)
        {
            resize(m_cap * 2);
        }
        BitRef(m_data, m_size) = value;
        m_size++;
    }
    
    bool operator[](size_t index) const
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        size_t num = index / 8;
        size_t offset = index % 8;
        return m_data[num] & (1 << offset);
    }
    
    size_t size() const
    {
        return m_size;
    }
    
    void insert(size_t pos, bool value)
    {
        if (pos > m_size) throw std::out_of_range("Insert position out of range");
        
        if (m_size >= m_cap)
        {
            resize(m_cap * 2);
        }
        m_size++;
        for (size_t i = m_size - 1; i > pos; i--)
        {
            BitRef(m_data, i) = BitRef(m_data, i - 1);
        }
        BitRef(m_data, pos) = value;
    }
    
    void erase(size_t pos)
    {
        if (pos >= m_size) throw std::out_of_range("Erase position out of range");
        
        for (size_t i = pos; i < m_size - 1; i++)
        {
            BitRef(m_data, i) = BitRef(m_data, i + 1);
        }
        
        m_size--;
    }
};

int main()
{
    MyVector<bool> vec;
    // Добавление элементов
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(1);
    vec.push_back(0);
    // Вывод размера и элементов
    std::cout << "Size: " << vec.size() << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    // Изменение элемента
    vec[1] = true;
    std::cout << "After modification: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    // Вставка элемента
    vec.insert(2, false);
    std::cout << "After insert: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    // Удаление элемента
    vec.erase(3);
    std::cout << "After erase: ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
