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
    /// Конструктор инициализирует пустое дерево (корень - nullptr).
    /// </summary>
    BinaryTree() : Root(nullptr) {}
};

/// <summary>
/// Находит узел с заданным значением в бинарном дереве.
/// </summary>
/// <param name="node">Указатель на корневой узел, с которого начинается поиск.</param>
/// <param name="value">Значение, которое нужно найти.</param>
/// <returns>Указатель на узел, содержащий заданное значение, или nullptr, если узел не найден.</returns>
BinaryTreeNode* Find(BinaryTreeNode* node, const int value);

/// <summary>
/// Находит узел с минимальным значением в дереве.
/// </summary>
/// <param name="node">Указатель на корневой узел, с которого начинается поиск.</param>
/// <returns>Указатель на узел с минимальным значением, или nullptr, если дерево пустое.</returns>
BinaryTreeNode* FindMinimal(BinaryTreeNode* node);

/// <summary>
/// Находит узел с максимальным значением в дереве.
/// </summary>
/// <param name="node">Указатель на корневой узел, с которого начинается поиск.</param>
/// <returns>Указатель на узел с максимальным значением, или nullptr, если дерево пустое.</returns>
BinaryTreeNode* FindMaximal(BinaryTreeNode* node);

/// <summary>
/// Вставляет новое значение в бинарное дерево.
/// </summary>
/// <param name="node">Указатель на узел, откуда начинается вставка.</param>
/// <param name="value">Значение, которое нужно вставить.</param>
void Insert(BinaryTreeNode*& node, int value);

/// <summary>
/// Удаляет узел с заданным значением из бинарного дерева.
/// </summary>
/// <param name="node">Указатель на узел, из которого начинается удаление.</param>
/// <param name="value">Значение, которое нужно удалить.</param>
void Remove(BinaryTreeNode*& node, const int value);
