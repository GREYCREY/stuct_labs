#include "Stack.h"

/// <summary>
/// Конструктор по умолчанию.
/// </summary>
Stack::Stack() : _buffer(nullptr), _bufferSize(0), _top(-1) {}

/// <summary>
/// Конструктор с заданным размером.
/// </summary>
/// <param name="size"></param>
Stack::Stack(int size) : _bufferSize(size), _top(-1)
{
    _buffer = new int[size];
}

/// <summary>
/// Деструктор.
/// </summary>
Stack::~Stack()
{
    Delete();
}

/// <summary>
/// Добавление элемента в стек/
/// </summary>
/// <param name="data"></param>
void Stack::Push(int data)
{
    if (_top >= _bufferSize - 1)
    {
        throw overflow_error("Стек переполнен, невозможно добавить элемент.");
    }
    _buffer[++_top] = data;
}

/// <summary>
/// Извлечение элемента из стека.
/// </summary>
/// <returns></returns>
int Stack::Pop()
{
    if (IsEmpty())
    {
        throw underflow_error("Стек пуст, невозможно извлечь элемент.");
    }
    return _buffer[_top--];
}

/// <summary>
/// Проверка, пуст ли стек.
/// </summary>
/// <returns></returns>
bool Stack::IsEmpty()
{
    return _top == -1;
}

/// <summary>
/// Получение размера стека.
/// </summary>
/// <returns></returns>
int Stack::GetSize()
{
    return _top + 1;
}

/// <summary>
/// Получение вместимости стека.
/// </summary>
/// <returns></returns>
int Stack::GetCapacity()
{
    return _bufferSize;
}

/// <summary>
/// Вывод всех элементов очереди.
/// </summary>
void Stack::Print()
{
    if (IsEmpty())
    {
        cout << "Стек пуст." << std::endl;
        return;
    }

    cout << "Вывод стека: ";
    for (int i = _top; i >= 0; --i)
    {
        cout << _buffer[i] << " ";
    }
    cout << endl;
}

/// <summary>
/// Освобождение памяти стека.
/// </summary>
void Stack::Delete()
{
    delete[] _buffer;
    _buffer = nullptr;
    _bufferSize = 0;
    _top = -1;
}
