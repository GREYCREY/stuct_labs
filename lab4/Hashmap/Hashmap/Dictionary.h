#pragma once
#include "HashTable.h"
#include <string>

/// <summary>
/// Класс словаря.
/// </summary>
class DictionaryWrapper
{
private:
    // TODO: Использовать указатель(Исправлено)
    // TODO: Комментарий пишется над комментируемым кодом. (Сделано)
    /// <summary>
    /// Указатель на объект хэш-таблицы, используемый для хранения данных.
    /// </summary>
    HashTable* _dictionary;

public:
    /// <summary>
    /// Конструктор класса.
    /// </summary>
    /// <param name="initialSize">Начальный размер хэш-таблицы.</param>
    /// <param name="loadFactor">Фактор загрузки хэш-таблицы.</param>
    DictionaryWrapper(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// Добавляет новую пару ключ-значение в хэш-таблицу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <param name="value">Значение.</param>
    void Add(const std::string& key, const std::string& value);

    /// <summary>
    /// Удаляет элемент из хэш-таблицы по указанному ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    void Remove(const std::string& key);

    /// <summary>
    /// Находит значение по указанному ключу.
    /// </summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Значение, связанное с ключом, или пустая строка, если ключ отсутствует.</returns>
    std::string Find(const std::string& key);

    /// <summary>
    /// Выводит текущее состояние хэш-таблицы:
    /// 1. Содержимое каждого бакета.
    /// 2. Полный список пар ключ-значение.
    /// </summary>
    void PrintState() const;
};

