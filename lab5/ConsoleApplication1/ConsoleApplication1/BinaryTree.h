#pragma once
#include "BinaryTreeNode.h"
/// <summary>
/// Структура, представляющая бинарное дерево.
/// </summary>
struct BinaryTree
{
    /// <summary>
    /// Указатель на корневой узел дерева.
    /// </summary>
    BinaryTreeNode* Root;

    /// <summary>
    /// Конструктор Инициализирует корень как nullptr
    /// </summary>
    BinaryTree() : Root(nullptr) {}
};


/// <summary>
/// Выполняет поиск элемента в бинарном дереве.
/// </summary>
/// <param name="node">Указатель на узел дерева, с которого начинается поиск.</param>
/// <param name="value">Значение, которое требуется найти.</param>
/// <returns>Указатель на узел, содержащий искомое значение, или nullptr, если элемент не найден.</returns>
BinaryTreeNode* Find(BinaryTreeNode* node, const int value);

/// <summary>
/// Выполняет поиск минимального элемента в дереве.
/// </summary>
/// <param name="node">Указатель на узел дерева, с которого начинается поиск.</param>
/// <returns>Указатель на узел, содержащий минимальное значение, или nullptr, если дерево пусто.</returns>
BinaryTreeNode* FindMinimal(BinaryTreeNode* node);

/// <summary>
/// Выполняет поиск максимального элемента в дереве.
/// </summary>
/// <param name="node">Указатель на узел дерева, с которого начинается поиск.</param>
/// <returns>Указатель на узел, содержащий максимальное значение, или nullptr, если дерево пусто.</returns>
BinaryTreeNode* FindMaximal(BinaryTreeNode* node);

/// <summary>
/// Вставляет новое значение в бинарное дерево.
/// </summary>
/// <param name="node">Ссылка на указатель узла, куда вставляется значение.</param>
/// <param name="value">Значение, которое требуется вставить.</param>
void Insert(BinaryTreeNode*& node, int value);

/// <summary>
/// Удаляет элемент с заданным значением из бинарного дерева.
/// </summary>
/// <param name="node">Ссылка на указатель узла, из которого удаляется значение.</param>
/// <param name="value">Значение, которое требуется удалить.</param>
void Remove(BinaryTreeNode*& node, const int value);

