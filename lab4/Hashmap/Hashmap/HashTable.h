#pragma once

#include <string>
#include <iostream>
#include "Node.h"

// TODO: Один файл - один класс/структура(исправлено)
/// <summary>
/// Класс HashTable представляет хеш-таблицу.
/// </summary>
class HashTable
{
private:
    /// <summary>
    /// Таблица с указателями на узлы.
    /// </summary>
    Node** _table;

    /// <summary>
    /// Размер хеш-таблицы.
    /// </summary>
    size_t _size;

    /// <summary>
    /// Максимальный коэффициент загрузки.
    /// </summary>
    double _maxLoadFactor;

    /// <summary>
    /// Текущая численность элементов в хеш-таблице.
    /// </summary>
    size_t _count;

    /// <summary>
    /// Вычисляет индекс в таблице на основе ключа.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Индекс в таблице.</returns>
    size_t GetIndex(const std::string& key) const;

    /// <summary>
    /// Выполняет перераспределение памяти и пересчет хеша для всех элементов.
    /// </summary>
    void Rehash();

public:
    /// <summary>
    /// Конструктор хеш-таблицы.
    /// </summary>
    /// <param name="initialSize">Начальный размер таблицы.</param>
    /// <param name="loadFactor">Максимальный коэффициент загрузки.</param>
    HashTable(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// Деструктор хеш-таблицы.
    /// </summary>
    ~HashTable();

    /// <summary>
    /// Вставляет элемент с заданными ключом и значением.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <param name="value">Значение.</param>
    void Insert(const std::string& key, const std::string& value);

    /// <summary>
    /// Удаляет элемент из таблицы по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    void Remove(const std::string& key);

    /// <summary>
    /// Находит значение по ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Значение, соответствующее ключу, или пустая строка, если ключ не найден.</returns>
    std::string Find(const std::string& key) const;

    /// <summary>
    /// Вычисляет хеш для заданного ключа.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Хеш ключа.</returns>
    size_t static GetHash(const std::string& key);

    /// <summary>
    /// Возвращает указатель на начало списка узлов по индексу.
    /// </summary>
    /// <param name="index">Индекс.</param>
    /// <returns>Указатель на узел.</returns>
    Node* GetBucket(size_t index) const;

    /// <summary>
    /// Возвращает размер хеш-таблицы.
    /// </summary>
    /// <returns>Размер таблицы.</returns>
    size_t GetSize() const;

    /// <summary>
    /// Возвращает текущее количество элементов в таблице.
    /// </summary>
    /// <returns>Количество элементов.</returns>
    size_t GetCount() const;
};
