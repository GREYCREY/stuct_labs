#include "QueueCircularBuffer.h"

/// <summary>
/// Конструктор.
/// </summary>
/// <param name="size"></param>
QueueCircularBuffer::QueueCircularBuffer(int size) : _circularBuffer(size) {}

/// <summary>
/// Деструктор.
/// </summary>
QueueCircularBuffer::~QueueCircularBuffer()
{
    Delete(); // Освобождение памяти
}

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
/// <param name="data"></param>
void QueueCircularBuffer::Enqueue(int data)
{
    if (!_circularBuffer.IsFull()) { // Проверяем, не переполнена ли очередь
        _circularBuffer.Add(data);
    }
    else {
        cout << "Очередь переполнена. Элемент не добавлен: " << data << endl;
    }
}

/// <summary>
/// Извлечение элемента из очереди.
/// </summary>
/// <returns></returns>
int QueueCircularBuffer::Dequeue()
{
    return _circularBuffer.Remove();
}

/// <summary>
/// Проверка, пуста ли очередь.
/// </summary>
/// <returns></returns>
bool QueueCircularBuffer::IsEmpty()
{
    return _circularBuffer.IsEmpty();
}

/// <summary>
/// Метод для вывода всех элементов очереди.
/// </summary>
void QueueCircularBuffer::Print() {
    cout << "Вывод очереди: ";
    _circularBuffer.Print();
}

/// <summary>
/// Освобождение памяти для очереди
/// </summary>
void QueueCircularBuffer::Delete()
{
    _circularBuffer.Delete();
}