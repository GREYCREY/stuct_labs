#pragma once
#include <random>

// TODO: Полетела кодировка (посмотреть везде)(исправлено)

/// <summary>
/// Узел декартового дерева.
/// </summary>
struct TreapNode
{
    /// <summary>
    /// Ключ узла.
    /// </summary>
    int Key;

    /// <summary>
    /// Приоритет узла.
    /// </summary>
    int Priority;

    /// <summary>
    /// Ссылка на левого потомка.
    /// </summary>
    TreapNode* LeftNode = nullptr;

    /// <summary>
    /// Ссылка на правого потомка.
    /// </summary>
    TreapNode* RightNode = nullptr;

    /// <summary>
    /// Конструктор узла с инициализацией ключа и случайного приоритета.
    /// </summary>
    /// <param name="key">Ключ узла.</param>
    TreapNode(int key)
    {
        Key = key;
        static std::mt19937 rng(std::random_device{}());
        Priority = std::uniform_int_distribution<int>(1, 1000000)(rng);
        LeftNode = nullptr;
        RightNode = nullptr;
    }
};
