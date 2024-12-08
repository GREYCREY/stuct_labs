#include <iostream>
#include "List.h" 

using namespace std;

// Конструктор по умолчанию для двусвязного списка
DoublyLinkedList::DoublyLinkedList() : _head(nullptr), _tail(nullptr) {}

// Деструктор для освобождения памяти
DoublyLinkedList::~DoublyLinkedList()
{
    // Удаляем все элементы списка
    while (_head) {
        Remove(_head->Data);
    }
}

// Метод для удаления элемента из списка по значению
void DoublyLinkedList::Remove(int value)
{
    // Начинаем с головы списка
    Node* current = _head;

    while (current)
    {
        // Если нашли элемент с заданным значением
        if (current->Data == value)
        {
            // Перепривязываем указатели соседних элементов
            if (current->Prev)
            {
                current->Prev->Next = current->Next;
            }
            else
            {
                // Удаляемый элемент был головой
                _head = current->Next;
            }

            if (current->Next)
            {
                current->Next->Prev = current->Prev;
            }
            else
            {
                // Удаляемый элемент был хвостом
                _tail = current->Prev;
            }

            // Освобождаем память
            delete current;
            return;
        }
        // Переходим к следующему элементу
        current = current->Next;
    }

    // Если элемент не найден, выбрасываем исключение
    throw "Элемент не найден";
}

// Метод для вставки элемента в начало списка
void DoublyLinkedList::InsertAtBeginning(int value)
{
    // Создаем новый узел
    Node* newNode = new Node(value);

    if (!_head)
    {
        // Если список пуст, новый элемент становится головой и хвостом
        _head = _tail = newNode;
    }
    else
    {
        newNode->Next = _head;
        _head->Prev = newNode;
        _head = newNode; // Новый узел становится головой
    }
}

// Метод для вставки элемента в конец списка
void DoublyLinkedList::InsertAtEnd(int value)
{
    // Создаем новый узел
    Node* newNode = new Node(value);

    if (!_head)
    {
        // Если список пуст, новый элемент становится головой и хвостом
        _head = _tail = newNode;
    }
    else
    {
        _tail->Next = newNode;
        newNode->Prev = _tail;
        _tail = newNode; // Новый узел становится хвостом
    }
}

// Метод для вставки элемента после заданного значения
void DoublyLinkedList::InsertAfter(int target, int value)
{
    // Начинаем с головы списка
    Node* current = _head;

    while (current)
    {
        // Если нашли целевой элемент
        if (current->Data == target)
        {
            // Создаем новый узел
            Node* newNode = new Node(value);

            newNode->Next = current->Next;
            newNode->Prev = current;

            if (current->Next)
            {
                current->Next->Prev = newNode;
            }
            else
            {
                // Если вставляем в конец
                _tail = newNode;
            }

            current->Next = newNode;
            return;
        }
        // Переходим к следующему элементу
        current = current->Next;
    }

    // Если целевой элемент не найден, выбрасываем исключение
    throw "Элемент не найден";
}

// Метод для вставки элемента перед заданным значением
void DoublyLinkedList::InsertBefore(int target, int value)
{
    // Начинаем с головы списка
    Node* current = _head;

    while (current)
    {
        // Если нашли целевой элемент
        if (current->Data == target)
        {
            // Создаем новый узел
            Node* newNode = new Node(value);

            newNode->Prev = current->Prev;
            newNode->Next = current;

            if (current->Prev)
            {
                current->Prev->Next = newNode;
            }
            else
            {
                // Если вставляем в начало
                _head = newNode;
            }

            current->Prev = newNode;
            return;
        }
        // Переходим к следующему элементу
        current = current->Next;
    }

    // Если целевой элемент не найден, выбрасываем исключение
    throw "Элемент не найден";
}

// Метод для сортировки списка методом пузырька
void DoublyLinkedList::BubbleSort()
{
    // Если список пуст, ничего не делаем
    if (!_head) return;

    bool swapped;

    do
    {
        swapped = false;
        Node* current = _head;

        while (current->Next)
        {
            // Если элементы стоят не по порядку
            if (current->Data > current->Next->Data)
            {
                // Меняем местами значения
                std::swap(current->Data, current->Next->Data);
                swapped = true;
            }
            // Переходим к следующему элементу
            current = current->Next;
        }
    } while (swapped); // Повторяем, пока были перестановки
}

// Метод для линейного поиска элемента в списке
bool DoublyLinkedList::LinearSearch(int value)
{
    // Начинаем с головы списка
    Node* current = _head;

    while (current)
    {
        // Если нашли искомый элемент
        if (current->Data == value)
        {
            return true; // Элемент найден
        }
        // Переходим к следующему элементу
        current = current->Next;
    }

    // Элемент не найден
    return false;
}

// Метод для вывода всех элементов списка
void DoublyLinkedList::PrintList()
{
    // Начинаем с головы списка
    Node* current = _head;

    while (current)
    {
        // Печатаем значение текущего элемента
        cout << current->Data << " ";
        // Переходим к следующему элементу
        current = current->Next;
    }

    // Завершаем строку
    cout << endl;
}
