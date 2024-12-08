#pragma once
#include "RingBuffer.h"

/// <summary>
/// Структура очереди на основе кольцевого буфера.
/// </summary>
struct QueueRingBuffer
{
private:
    /// <summary>
    /// Кольцевой буфер для очереди.
    /// </summary>
    RingBuffer _ringBuffer;

public:
    /// <summary>
    /// Конструктор.
    /// </summary>
    /// <param name="size"></param>
    QueueRingBuffer(int size);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~QueueRingBuffer();

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