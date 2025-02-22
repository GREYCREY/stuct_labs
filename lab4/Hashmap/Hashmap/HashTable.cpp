#include "HashTable.h"
#include <cstring>

HashTable::HashTable(size_t initialSize, double loadFactor)
    : _size(initialSize), _maxLoadFactor(loadFactor), _count(0)
{
    _table = new Node * [_size];
    memset(_table, 0, _size * sizeof(Node*));
}

HashTable::~HashTable()
{
    for (size_t i = 0; i < _size; ++i)
    {
        Node* current = _table[i];
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    delete[] _table;
}

size_t HashTable::GetHash(const std::string& key)
{
    // Константы для хеширования
    constexpr size_t MULTIPLIER = 1664525;
    constexpr size_t OFFSET = 1013904223;

    size_t hashValue = 0;
    for (char c : key)
    {
        hashValue = (hashValue * MULTIPLIER) + static_cast<unsigned char>(c) + OFFSET;
    }

    return hashValue;
}


size_t HashTable::GetIndex(const std::string& key) const
{
    return GetHash(key) % _size;
}

void HashTable::Rehash()
{
    size_t oldSize = _size;
    _size *= 2;
    Node** newTable = new Node * [_size];
    memset(newTable, 0, _size * sizeof(Node*));

    for (size_t i = 0; i < oldSize; ++i)
    {
        Node* current = _table[i];
        while (current)
        {
            size_t newIndex = GetIndex(current->key);
            Node* next = current->next;

            current->next = newTable[newIndex];
            newTable[newIndex] = current;

            current = next;
        }
    }

    delete[] _table;
    _table = newTable;
}

void HashTable::Insert(const std::string& key, const std::string& value)
{
    size_t index = GetIndex(key);

    // Ищем существующий ключ в списке
    for (Node* current = _table[index]; current != nullptr; current = current->next)
    {
        if (current->key == key)
        {
            // Если ключ найден, обновляем значение
            current->value = value;
            return;
        }
    }

    // Если ключ не найден, создаём новый узел
    Node* newNode = new Node{ key, value };
    newNode->next = _table[index];
    _table[index] = newNode;
    _count++;
    if (static_cast<double>(_count) / _size >= _maxLoadFactor) {
        Rehash();
    }
}

void HashTable::Remove(const std::string& key)
{
    size_t index = GetIndex(key);
    Node* current = _table[index];
    Node* prev = nullptr;

    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
            }
            else
            {
                _table[index] = current->next;
            }

            delete current;
            _count--;
            return;
        }

        prev = current;
        current = current->next;
    }
}

std::string HashTable::Find(const std::string& key) const
{
    size_t index = GetIndex(key);

    for (Node* current = _table[index]; current != nullptr; current = current->next)
    {
        if (current->key == key)
        {
            return current->value;
        }
    }

    return "";
}

size_t HashTable::GetSize() const
{
    return _size;
}

size_t HashTable::GetCount() const
{
    return _count;
}

Node* HashTable::GetBucket(size_t index) const
{
    return _table[index];
}
