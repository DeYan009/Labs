#include <iostream>
#include <math.h>


class RectangularParallelepiped
{
    private:
        int m_length;
        int m_width;
        int m_height;
    public:
        RectangularParallelepiped(const int length, int width, int height):
                m_length(length), m_width(width), m_height(height) 
        {
            std::cout << "ctor RP" << std::endl;
        }
        ~RectangularParallelepiped()
        {
            std::cout << "dtor RP" << std::endl;
        }

        void S()
        {
            std::cout << 2 * (m_length * m_width + m_width * m_height + m_length * m_height) << std::endl;
        }

        void V()
        {
            std::cout << m_length * m_width * m_height << std::endl;
        }

        void D()
        {
            std::cout << sqrt(m_length * m_length + m_width * m_width + m_height * m_height) << std::endl;
        }

};

int main() 
{
    RectangularParallelepiped RP1(5, 7, 11);
    RP1.S();
    RP1.V();
    RP1.D();
	return 0;
}