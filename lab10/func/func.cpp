#include <func.hpp>
#include <iostream>
#include <fstream>

namespace mt
{
    void Make(Node*& head)
    {
        head = new Node {0, nullptr};
    }

    void PushBack(Node* head, int value)
    {
        Node* p = head; // head-> == (*head).
        while(p->next != nullptr)
            p = p->next;
        
        Node* q = new Node;
        q->data = value;
        q->next = nullptr;
        p->next = q;
    }

	bool Read(Node* head)
	{
		std::ifstream in("input.txt");
    	if(!in.is_open())
    	{
        	std::cout << "File not opened" << std::endl;
        	return false;
    	}

    int value;
    while (in >> value)
		PushBack(head, value);

    	return true;
	}

	bool isSorted(Node* head)
	{
		Node* current = head->next;
        bool isSortedFD = true;
		bool isSortedLD = true;
        int lastFirstDigit = INT32_MIN;
        int lastLastDigit = INT32_MIN;

        while (current != nullptr)
		{
            int firstDigit = current->data;
            while (firstDigit >= 10) firstDigit /= 10;
            int lastDigit = current->data % 10;
			// std::cout << "fd" << firstDigit << "ld" << lastDigit << std::endl;

            if (firstDigit < lastFirstDigit)
			{
                isSortedFD = false;
            }

			if (lastDigit < lastLastDigit)
			{
                isSortedLD = false;
            }

            lastFirstDigit = firstDigit;
            lastLastDigit = lastDigit;
            current = current->next;
        }
		return isSortedFD || isSortedLD;
		// return lastLastDigit;

	}

	bool ContainsDigits246(int number)
	{
    while (number > 0)
	{
        int digit = number % 10;
        if (digit == 2 || digit == 4 || digit == 6)
		{
            return true;
        }
        number /= 10;
    }
    return false;
    }

    bool ContainsDigits69(int number)
	{
    while (number > 0)
	{
        int digit = number % 10;
        if (digit == 9 || digit == 6)
		{
            return true;
        }
        number /= 10;
    }
    return false;
    }

	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	void Sort(Node* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
        	return;
    	}

		bool flagSort = true;
		while(flagSort)
		{
			flagSort = false;
			Node* current = head->next;
			while(current != nullptr && current->next != nullptr)
			{
            	if (current->data > current->next->data)
				{
                	swap(current->data, current->next->data);
					flagSort = true;
            	}
            	current = current->next;
        	}
		}
	}

    void Print(Node* head)
    {
        Node* p = head->next;
        while(p != nullptr)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
    }

    void Remove(Node* head, int index)
    {
        Node* p = head;
        int i = 0;
        while(p->next != nullptr && i != index)
        {
            i++;
            p = p->next;
        }

        if(p->next == nullptr)
            return;

        Node* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }

    void Clear(Node* head)
    {
        Node* p = head;
        while(p->next != nullptr)
        {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
    }
}