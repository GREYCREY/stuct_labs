#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

/// <summary>
/// Стуктура стека.
/// </summary>
struct Stack
{
private:
    /// <summary>
    /// Указатель на массив (буфер).
    /// </summary>
    int* _buffer;

    /// <summary>
    /// Размер буфера.
    /// </summary>
    int _bufferSize;

    /// <summary>
    /// Индекс вершины стека.
    /// </summary>
    int _top;

public:
    /// <summary>
    /// Конструктор по умолчанию.
    /// </summary>
    Stack();

    /// <summary>
    /// Конструктор с заданным размером.
    /// </summary>
    /// <param name="size"></param>
    Stack(int size);

    /// <summary>
    /// Деструктор.
    /// </summary>
    ~Stack();

    /// <summary>
    /// Помещение элемента в стек.
    /// </summary>
    /// <param name="data"></param>
    void Push(int data);

    /// <summary>
    /// Извлечение элемента из стека.
    /// </summary>
    /// <returns></returns>
    int Pop();

    /// <summary>
    /// Проверка на пустоту стека.
    /// </summary>
    /// <returns></returns>
    bool IsEmpty();

    /// <summary>
    /// Получение размера стека.
    /// </summary>
    /// <returns></returns>
    int GetSize();

    /// <summary>
    /// Получение вместимости стека.
    /// </summary>
    /// <returns></returns>
    int GetCapacity();

    /// <summary>
    /// Вывод всех элементов очереди.
    /// </summary>
    void Print();

    /// <summary>
    /// Освобождение памяти стека.
    /// </summary>
    void Delete();
};