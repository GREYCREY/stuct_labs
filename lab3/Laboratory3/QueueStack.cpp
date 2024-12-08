#include "QueueStack.h"

/// <summary>
/// Конструктор.
/// </summary>
/// <param name="size"></param>
QueueStack::QueueStack(int size) : _stack1(size), _stack2(size) {}

/// <summary>
/// Деструктор.
/// </summary>
QueueStack::~QueueStack()
{
    Delete();
}

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
/// <param name="data"></param>
void QueueStack::Enqueue(int data)
{
    _stack1.Push(data); // Добавляем элемент в первый стек
}

/// <summary>
/// Извлечение элемента из очереди.
/// </summary>
/// <returns></returns>
int QueueStack::Dequeue()
{
    if (_stack2.IsEmpty())
    {
        while (!_stack1.IsEmpty())
        {
            _stack2.Push(_stack1.Pop());
        }
    }
    if (_stack2.IsEmpty())
    {
        throw underflow_error("Очередь пуста, невозможно извлечь элемент.");
    }
    return _stack2.Pop();
}

/// <summary>
/// Проверка, пуста ли очередь.
/// </summary>
/// <returns></returns>
bool QueueStack::IsEmpty()
{
    return _stack1.IsEmpty() && _stack2.IsEmpty();
}

/// <summary>
/// Освобождение памяти для очереди.
/// </summary>
void QueueStack::Delete()
{
    _stack1.Delete();
    _stack2.Delete();
}

/// <summary>
/// Вывод всех элементов очереди.
/// </summary>
void QueueStack::Print() {
    std::cout << "Вывод очереди: ";
    // Создаем временные стеки для вывода.
    Stack tempStack1(_stack1.GetSize());
    Stack tempStack2(_stack2.GetSize());

    while (!_stack2.IsEmpty())
    {
        int value = _stack2.Pop();
        cout << value << " ";
        tempStack2.Push(value); // Сохраняем элементы обратно.
    }

    // Теперь показываем элементы из первого стека, сохраняя их в временном.
    while (!_stack1.IsEmpty())
    {
        int value = _stack1.Pop();
        cout << value << " ";
        tempStack1.Push(value);
    }

    // Возвращаем все элементы обратно.
    while (!tempStack2.IsEmpty())
    {
        _stack2.Push(tempStack2.Pop());
    }
    while (!tempStack1.IsEmpty())
    {
        _stack1.Push(tempStack1.Pop());
    }

    cout << std::endl;
}
