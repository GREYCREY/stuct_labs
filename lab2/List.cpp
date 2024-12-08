#include <iostream>
#include "List.h" 

using namespace std;

// ����������� �� ��������� ��� ����������� ������
DoublyLinkedList::DoublyLinkedList() : _head(nullptr), _tail(nullptr) {}

// ���������� ��� ������������ ������
DoublyLinkedList::~DoublyLinkedList()
{
    // ������� ��� �������� ������
    while (_head) {
        Remove(_head->Data);
    }
}

// ����� ��� �������� �������� �� ������ �� ��������
void DoublyLinkedList::Remove(int value)
{
    // �������� � ������ ������
    Node* current = _head;

    while (current)
    {
        // ���� ����� ������� � �������� ���������
        if (current->Data == value)
        {
            // ��������������� ��������� �������� ���������
            if (current->Prev)
            {
                current->Prev->Next = current->Next;
            }
            else
            {
                // ��������� ������� ��� �������
                _head = current->Next;
            }

            if (current->Next)
            {
                current->Next->Prev = current->Prev;
            }
            else
            {
                // ��������� ������� ��� �������
                _tail = current->Prev;
            }

            // ����������� ������
            delete current;
            return;
        }
        // ��������� � ���������� ��������
        current = current->Next;
    }

    // ���� ������� �� ������, ����������� ����������
    throw "������� �� ������";
}

// ����� ��� ������� �������� � ������ ������
void DoublyLinkedList::InsertAtBeginning(int value)
{
    // ������� ����� ����
    Node* newNode = new Node(value);

    if (!_head)
    {
        // ���� ������ ����, ����� ������� ���������� ������� � �������
        _head = _tail = newNode;
    }
    else
    {
        newNode->Next = _head;
        _head->Prev = newNode;
        _head = newNode; // ����� ���� ���������� �������
    }
}

// ����� ��� ������� �������� � ����� ������
void DoublyLinkedList::InsertAtEnd(int value)
{
    // ������� ����� ����
    Node* newNode = new Node(value);

    if (!_head)
    {
        // ���� ������ ����, ����� ������� ���������� ������� � �������
        _head = _tail = newNode;
    }
    else
    {
        _tail->Next = newNode;
        newNode->Prev = _tail;
        _tail = newNode; // ����� ���� ���������� �������
    }
}

// ����� ��� ������� �������� ����� ��������� ��������
void DoublyLinkedList::InsertAfter(int target, int value)
{
    // �������� � ������ ������
    Node* current = _head;

    while (current)
    {
        // ���� ����� ������� �������
        if (current->Data == target)
        {
            // ������� ����� ����
            Node* newNode = new Node(value);

            newNode->Next = current->Next;
            newNode->Prev = current;

            if (current->Next)
            {
                current->Next->Prev = newNode;
            }
            else
            {
                // ���� ��������� � �����
                _tail = newNode;
            }

            current->Next = newNode;
            return;
        }
        // ��������� � ���������� ��������
        current = current->Next;
    }

    // ���� ������� ������� �� ������, ����������� ����������
    throw "������� �� ������";
}

// ����� ��� ������� �������� ����� �������� ���������
void DoublyLinkedList::InsertBefore(int target, int value)
{
    // �������� � ������ ������
    Node* current = _head;

    while (current)
    {
        // ���� ����� ������� �������
        if (current->Data == target)
        {
            // ������� ����� ����
            Node* newNode = new Node(value);

            newNode->Prev = current->Prev;
            newNode->Next = current;

            if (current->Prev)
            {
                current->Prev->Next = newNode;
            }
            else
            {
                // ���� ��������� � ������
                _head = newNode;
            }

            current->Prev = newNode;
            return;
        }
        // ��������� � ���������� ��������
        current = current->Next;
    }

    // ���� ������� ������� �� ������, ����������� ����������
    throw "������� �� ������";
}

// ����� ��� ���������� ������ ������� ��������
void DoublyLinkedList::BubbleSort()
{
    // ���� ������ ����, ������ �� ������
    if (!_head) return;

    bool swapped;

    do
    {
        swapped = false;
        Node* current = _head;

        while (current->Next)
        {
            // ���� �������� ����� �� �� �������
            if (current->Data > current->Next->Data)
            {
                // ������ ������� ��������
                std::swap(current->Data, current->Next->Data);
                swapped = true;
            }
            // ��������� � ���������� ��������
            current = current->Next;
        }
    } while (swapped); // ���������, ���� ���� ������������
}

// ����� ��� ��������� ������ �������� � ������
bool DoublyLinkedList::LinearSearch(int value)
{
    // �������� � ������ ������
    Node* current = _head;

    while (current)
    {
        // ���� ����� ������� �������
        if (current->Data == value)
        {
            return true; // ������� ������
        }
        // ��������� � ���������� ��������
        current = current->Next;
    }

    // ������� �� ������
    return false;
}

// ����� ��� ������ ���� ��������� ������
void DoublyLinkedList::PrintList()
{
    // �������� � ������ ������
    Node* current = _head;

    while (current)
    {
        // �������� �������� �������� ��������
        cout << current->Data << " ";
        // ��������� � ���������� ��������
        current = current->Next;
    }

    // ��������� ������
    cout << endl;
}
