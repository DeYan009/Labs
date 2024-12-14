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
        mt::Node* current = head;
        int i = 1;
		while(current != nullptr)
        {
            std::cout << current->data << " " << i  << " " << mt::ContainsDigits246(current->data) <<std::endl;
            if(!mt::ContainsDigits246(current->data))
            {
                std::cout << "<" << current->data << ">" <<std::endl;
                mt::Remove(head, i);
                current = current->next;
                // current = head;
                // i = 1;
                // std::cout << current->data <<std::endl;

                // i++;
                // current = current->next;
            }
            else
            {
                i++;
                current = current->next;
            }
        }
    }
    else
        mt::Sort(head);
    mt::Print(head);
    mt::Clear(head);
	return 0;
}