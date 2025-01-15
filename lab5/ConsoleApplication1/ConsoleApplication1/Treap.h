#pragma once
#include "BinaryTreeNode.h"

/// <summary>
/// Структура, представляющая бинарное дерево.
/// </summary>
struct BinaryTree
{
    /// <summary>
    /// Указатель на корень дерева.
    /// </summary>
    BinaryTreeNode* Root;

    /// <summary>
    /// Конструктор инициализирует дерево пустым.
    /// </summary>
    BinaryTree() : Root(nullptr) {}
};

/// <summary>
/// Находит узел с заданным значением в бинарном дереве.
/// </summary>
/// <param name="node">Указатель на текущий узел, в котором производится поиск.</param>
/// <param name="value">Значение для поиска.</param>
/// <returns>Указатель на найденный узел или nullptr, если узел не найден.</returns>
BinaryTreeNode* Find(BinaryTreeNode* node, const int value);

/// <summary>
/// Находит узел с минимальным значением в дереве.
/// </summary>
/// <param name="node">Указатель на текущий узел, начиная с которого производится поиск.</param>
/// <returns>Указатель на узел с минимальным значением или nullptr, если дерево пусто.</returns>
BinaryTreeNode* FindMinimal(BinaryTreeNode* node);

/// <summary>
/// Находит узел с максимальным значением в дереве.
/// </summary>
/// <param name="node">Указатель на текущий узел, начиная с которого производится поиск.</param>
/// <returns>Указатель на узел с максимальным значением или nullptr, если дерево пусто.</returns>
BinaryTreeNode* FindMaximal(BinaryTreeNode* node);

/// <summary>
/// Вставляет узел с заданным значением в бинарное дерево.
/// </summary>
/// <param name="node">Указатель на текущий узел, к которому добавляется новый элемент.</param>
/// <param name="value">Значение для добавления.</param>
void Insert(BinaryTreeNode*& node, int value);

/// <summary>
/// Удаляет узел с заданным значением из дерева.
/// </summary>
/// <param name="node">Указатель на текущий узел, из которого удаляется значение.</param>
/// <param name="value">Значение для удаления.</param>
void Remove(BinaryTreeNode*& node, const int value);

// Код для структуры Treap
#pragma once
#include "TreapNode.h"

/// <summary>
/// Структура, представляющая декартово дерево (Treap).
/// </summary>
struct Treap
{
    /// <summary>
    /// Указатель на корень Treap.
    /// </summary>
    TreapNode* Root;
    Treap() : Root(nullptr) {}
};

/// <summary>
/// Находит элемент с заданным ключом в Treap.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ для поиска.</param>
/// <returns>Указатель на найденный узел или nullptr, если ключ не найден.</returns>
TreapNode* FindElement(TreapNode* node, int key);

/// <summary>
/// Разделяет дерево Treap на два поддерева по заданному ключу.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ, по которому производится разделение.</param>
/// <param name="left">Указатель на левое поддерево.</param>
/// <param name="right">Указатель на правое поддерево.</param>
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// Объединяет два поддерева в одно дерево Treap.
/// </summary>
/// <param name="left">Указатель на левое поддерево.</param>
/// <param name="right">Указатель на правое поддерево.</param>
/// <returns>Указатель на корень объединенного дерева.</returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// Добавляет элемент в Treap без оптимизации.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ для добавления.</param>
void AddNotOptimized(TreapNode*& node, int key);

/// <summary>
/// Добавляет элемент в Treap с оптимизацией.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ для добавления.</param>
void AddOptimized(TreapNode*& node, int key);

/// <summary>
/// Удаляет элемент из Treap без оптимизации.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ для удаления.</param>
/// <param name="success">Флаг успеха удаления.</param>
void RemoveNotOptimized(TreapNode*& node, int key, bool& success);

/// <summary>
/// Удаляет элемент из Treap с оптимизацией.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ для удаления.</param>
/// <param name="success">Флаг успеха удаления.</param>
void RemoveOptimized(TreapNode*& node, int key, bool& success);

/// <summary>
/// Возвращает значение элемента по заданному ключу в Treap.
/// </summary>
/// <param name="node">Указатель на текущий узел.</param>
/// <param name="key">Ключ для поиска значения.</param>
/// <returns>Значение элемента.</returns>
int GetValue(TreapNode* node, int key);
