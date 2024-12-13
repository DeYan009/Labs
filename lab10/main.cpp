#include <iostream>
#include <func.hpp>

int main()
{
	mt::Node* head;
	Make(head);
    mt::Read(head);
    mt::Print(head);
    std::cout << std::endl;
    // std::cout << mt::isSorted(head);
    if(mt::isSorted(head))
    {
        std::cout << "cool" << std::endl;
    }
    else
        mt::Sort(head);
    mt::Print(head);
    mt::Clear(head);
	return 0;
}