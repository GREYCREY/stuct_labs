#pragma once
#include "CircularBuffer.h"

/// <summary>
/// Структура очереди на основе кольцевого буфера.
/// </summary>
struct QueueCircularBuffer
{
private:
    /// <summary>
    /// Кольцевой буфер для очереди.
    /// </summary>
    CircularBuffer _circularBuffer;

public:
    /// <summary>
    /// Конструктор.
    /// </summary>
    /// <param name="size"></param>
    QueueCircularBuffer(int size);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~QueueCircularBuffer();

    /// <summary>
    /// Добавление элемента в очередь.
    /// </summary>
    /// <param name="data"></param>
    void Enqueue(int data);

    /// <summary>
    /// Извлечение элемента из очереди.
    /// </summary>
    /// <returns></returns>
    int Dequeue();

    /// <summary>
    /// Проверка, пуста ли очередь.
    /// </summary>
    /// <returns></returns>
    bool IsEmpty();

    /// <summary>
    /// Освобождение памяти для очереди.
    /// </summary>
    void Delete();

    /// <summary>
    /// Вывод всех элементов очереди.
    /// </summary>
    void Print();
};