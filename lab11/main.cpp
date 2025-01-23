#include <iostream>

// #pragma pack
struct Node
{
    int data;
    Node* pref;
    Node* next;
};

void AddBack(Node* sent, int data)
{
    Node* p = new Node;
    p->data = data;
    p->pref = sent->pref;
    p->next = sent;
    sent->pref->next = p;
    sent->pref = p;
}

void Print(Node* sent)
{
    Node* p = sent->next;
    while(p != sent) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

void Clear(Node* sent)
{
    Node* p = sent->next;
    while(p != sent) {
        Node* tmp = p;
        p = p->next;
        delete tmp;
    }
    sent->pref = sent;
    sent->next = sent;
}

bool isPrime(int x)
{
	if(x < 2)
		return false;
	for(int d = 2; d <= sqrt(x); d++)
		if(x % d == 0)
			return false;
	return true;
}

void DeletePrime(Node* sent) {
    Node* p = sent->next;
    while(p != sent)
    {
        if(isPrime(p->data))
        {
            Node* tmp = p;
            p->next->pref = p->pref;
            p->pref->next = p->next;
            p = p->next;
            delete tmp;
        }
        else
            p = p->next;
    }
}

void Doubl10(Node* sent) // ne rabotaet
{
    Node* p = sent->next;
    while(p != sent)
    {
        if(p->data % 10 == 0)
        {
            Node* q = new Node;
            q->data = p->data;
            q->pref = p;
            q->next = p->next;
            p->next->pref = q;
            p->next = q;
            p = p->next;
        }
        p = p->next;
    }
}

void In(Node* sent)
{
    int n;
    int a;
    std::cin >> n;
    for(int i=0;i<n;i++)
    {
        std::cin >> a;
        AddBack(sent, a);
    }

}

bool End24(Node* sent) // ne rabotaet
{
    Node* p = sent->next;
    int count = 0;
    while(p != sent)
    {
        if(p->data % 10 == 2 || p->data % 10 == 4)
        {
            count++;
        }
        if(count == 3)
            return true;
        p = p->next;
    }
    return false;
}

void Sort(Node* sent) // ne rabotaet
{
   std::cout << "error sort"; 
}

int main()
{
    Node* sent = new Node;
    sent->pref = sent;
    sent->next = sent;
    In(sent);
    if(End24(sent))
    {
        Sort(sent);
    }
    else
    {
        Print(sent);
        std::cout << "-----" << std::endl;
        DeletePrime(sent);
        std::cout << "-----" << std::endl;
        Doubl10(sent);
    }

    Print(sent);
    Clear(sent);
    delete sent;

	return 0;
}