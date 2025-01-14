#pragma once

/// <summary>
/// Структура, представляющая узел в хеш-таблице.
/// </summary>
struct Node
{
    /// <summary>
    /// Ключ.
    /// </summary>
    std::string key;

    /// <summary>
    /// Значение.
    /// </summary>
    std::string value;

    /// <summary>
    /// Указатель на следующий узел.
    /// </summary>
    Node* next;

    /// <summary>
    /// Конструктор узла.
    /// </summary>
    /// <param name="k">Ключ.</param>
    /// <param name="v">Значение.</param>
    Node(const std::string& k, const std::string& v) : key(k), value(v), next(nullptr) {}
};

