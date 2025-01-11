#pragma once
#include "HashTable.h"
#include <string>

/// <summary>
/// �����-������� ��� ������ �� ��������.
/// </summary>
class DictionaryWrapper
{
private:
    // TODO: Использовать указатель
    // TODO: Комментарий пишется над комментируемым кодом. Используйте summary
    HashTable _dictionary; // ���-������� ��� �������� ������.

public:
    /// <summary>
    /// ����������� �������.
    /// </summary>
    /// <param name="initialSize">��������� ������ ���-�������.</param>
    /// <param name="loadFactor">������������ ����������� ��������.</param>
    DictionaryWrapper(size_t initialSize = 10, double loadFactor = 0.75);

    /// <summary>
    /// ��������� ���� ����-��������.
    /// </summary>
    /// <param name="key">����.</param>
    /// <param name="value">��������.</param>
    void Add(const std::string& key, const std::string& value);

    /// <summary>
    /// ������� ������� �� �����.
    /// </summary>
    /// <param name="key">����.</param>
    void Remove(const std::string& key);

    /// <summary>
    /// ������� �������� �� �����.
    /// </summary>
    /// <param name="key">����.</param>
    /// <returns>��������, ��������� � ������, ��� ������ ������, ���� ������� �� ������.</returns>
    std::string Find(const std::string& key);

    /// <summary>
    /// ������� ������� ��������� ������� � ���-�������.
    /// </summary>
    void PrintState() const;
};
