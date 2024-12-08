#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/// <summary>
/// Структура кольцевого буфера.
/// </summary>
struct RingBuffer
{
private:
    /// <summary>
    /// Указатель на буфер.
    /// </summary>
    int* _buffer;

    /// <summary>
    /// Максимальный размер буфера.
    /// </summary>
    int _bufferSize;

    /// <summary>
    /// Индекс для добавления элемента.
    /// </summary>
    int _head;

    /// <summary>
    /// Индекс для извлечения элемента.
    /// </summary>
    int _tail;

    /// <summary>
    /// Текущий размер заполненного буфера.
    /// </summary>
    int _currentSize;

public:
    /// <summary>
    /// Конструктор.
    /// </summary>
    /// <param name="size"></param>
    RingBuffer(int size);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~RingBuffer();


    /// <summary>
    /// Добавление элемента в кольцевой буфер.
    /// </summary>
    /// <param name="data"></param>
    void Add(int data);

    /// <summary>
    /// Извлечение элемента из кольцевого буфера.
    /// </summary>
    /// <returns></returns>
    int Remove();

    /// <summary>
    /// Проверка, полный ли кольцевой буфер.
    /// </summary>
    /// <returns></returns>
    bool IsFull();

    /// <summary>
    /// Проверка, пуст ли кольцевой буфер.
    /// </summary>
    /// <returns></returns>
    bool IsEmpty();

    /// <summary>
    /// Получение текущего размера буфера.
    /// </summary>
    /// <returns></returns>
    int Size();

    /// <summary>
    /// Вывод всех элементов кольцевого буфера.
    /// </summary>
    void Print();

    /// <summary>
    /// Освобождение памяти кольцевого буфера.
    /// </summary>
    void Delete();
};