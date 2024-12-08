#include "ListItem.h" // Подключаем заголовочный файл с описанием структуры Node

// Определение класса двусвязного списка
class DoublyLinkedList {
private:
    // Указатель на первый элемент (голову) списка
    Node* _head;

    // Указатель на последний элемент (хвост) списка
    Node* _tail;

public:
    // Конструктор по умолчанию
    DoublyLinkedList();

    // Деструктор для освобождения памяти, выделенной под элементы списка
    ~DoublyLinkedList();

    // Удаление элемента из списка по значению
    void Remove(int value);

    // Вставка элемента в начало списка
    void InsertAtBeginning(int value);

    // Вставка элемента в конец списка
    void InsertAtEnd(int value);

    // Вставка элемента после указанного значения
    void InsertAfter(int target, int value);

    // Вставка элемента перед указанным значением
    void InsertBefore(int target, int value);

    // Сортировка элементов списка методом пузырька
    void BubbleSort();

    // Линейный поиск элемента в списке
    bool LinearSearch(int value);

    // Печать всех элементов списка
    void PrintList();
};
