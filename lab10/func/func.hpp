#pragma once

namespace mt
{
    #pragma pack(push, 1)
    struct Node
    {
        int data;
        Node* next;
    };
    #pragma pack(pop)

    void PushBack(Node* head, int value);
    void Print(Node* head);
    void Remove(Node* head, int index);
    void Clear(Node* head);
    void Make(Node*& head);
    bool Read(Node* head);
    bool ContainsDigits246(int number);
    bool isSorted(Node* head);
    void Sort(Node* head);
}