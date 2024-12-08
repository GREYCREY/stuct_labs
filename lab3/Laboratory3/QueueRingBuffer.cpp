#include "QueueRingBuffer.h"

/// <summary>
/// Конструктор.
/// </summary>
/// <param name="size"></param>
QueueRingBuffer::QueueRingBuffer(int size) : _ringBuffer(size) {}

/// <summary>
/// Деструктор.
/// </summary>
QueueRingBuffer::~QueueRingBuffer()
{
    Delete(); // Освобождение памяти
}

/// <summary>
/// Добавление элемента в очередь.
/// </summary>
/// <param name="data"></param>
void QueueRingBuffer::Enqueue(int data)
{
    _ringBuffer.Add(data);
}

/// <summary>
/// Извлечение элемента из очереди.
/// </summary>
/// <returns></returns>
int QueueRingBuffer::Dequeue()
{
    return _ringBuffer.Remove();
}

/// <summary>
/// Проверка, пуста ли очередь.
/// </summary>
/// <returns></returns>
bool QueueRingBuffer::IsEmpty()
{
    return _ringBuffer.IsEmpty();
}

/// <summary>
/// Метод для вывода всех элементов очереди.
/// </summary>
void QueueRingBuffer::Print() {
    cout << "Вывод очереди: ";
    _ringBuffer.Print();
}

/// <summary>
/// Освобождение памяти для очереди
/// </summary>
void QueueRingBuffer::Delete()
{
    _ringBuffer.Delete();
}