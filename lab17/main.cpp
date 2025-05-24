#include <iostream>


struct BitRef
{
    char* m_value;
    size_t m_index;
    BitRef(char* value, size_t index)
    {
        m_value = value;
        m_index = index;
    }
        void operator=(bool v)
    {
        size_t num = m_index / 8; // >> 3
        size_t offset = m_index % 8;

        if(v)
            m_value[num] |= (1 << offset);
        else
            m_value[num] &= ~(1 << offset);
    }
};

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
        char* m_value;
        size_t m_size;
        size_t m_cup;
    public:
        MyVector()
        {
            m_value = new char[10];
            m_cup = 10;
            m_size = 0;
        }

        ~MyVector()
        {
            delete[] m_value;
        }

        void set(size_t index, bool value)
        {
            size_t num = index / 8; // >> 3
            size_t offset = index % 8;

            if(value)
                m_value[num] |= (1 << offset);
            else
                m_value[num] &= ~(1 << offset);
        }

        bool get(size_t index)
        {
            size_t num = index / 8; // >> 3
            size_t offset = index % 8;
            return m_value[num] & (1 << offset);
        }

        struct BitRef
        {
            char* m_value;
            size_t m_index;
            BitRef(char* value, size_t index)
            {
                m_value = value;
                m_index = index;
            }
            void operator=(bool v)
            {
                size_t num = m_index / 8; // >> 3
                size_t offset = m_index % 8;

                if(v)
                    m_value[num] |= (1 << offset);
                else
                    m_value[num] &= ~(1 << offset);
            }
        };

        BitRef operator[](size_t index)
        {
            return BitRef(m_value, index);
        }
};

std::ostream& operator<<(std::ostream& out, BitRef b)
{
    size_t num = b.m_index / 8; // >> 3
    size_t offset = b.m_index % 8;
    out << ((b.m_value[num] & (1 << offset))?1:0);
    return out;      
}




int main() 
{
    std::cout << "hello world" << std::endl;
	return 0;
}