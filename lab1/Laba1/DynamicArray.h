#pragma once

#include <iostream>

class DynamicArray {
private:
    int* _array;
    int _length;
    int _capacity;
    // Коэффициент роста
    const float GrowthFactor = 2.0;  

    // Функция для изменения размера массива
    void resize(int newCapacity);

public:
    // Конструктор, создающий массив с заданной начальной емкостью
    DynamicArray(int initCapacity = 4);

    // Деструктор
    ~DynamicArray();

    // Получение длины массива
    int GetLength() const;

    // Функция для добавления элемента в конец
    void AddToEnd(int value);

    // Функция для удаления элемента по индексу
    void RemoveAtIndex(int index);

    // Функция для удаления элемента по значению
    void RemoveValue(int value);

    // Вставка элемента в начало массива
    void InsertAtStart(int value);
    // Вставка элемента в конец массива 
    void InsertAtEnd(int value);

    // Вставка элемента после определенного индекса
    void InsertAfterIndex(int index, int value);

    // Линейный поиск элемента в массиве
    int LinearSearch(int value) const;

    // Бинарный поиск элемента в массиве (требует отсортированного массива)
    int BinarySearch(int value) const;

    // Сортировка расчёской (Comb Sort)
    void CombSort();

    // Вывод элементов массива
    void PrintElements() const;
};
