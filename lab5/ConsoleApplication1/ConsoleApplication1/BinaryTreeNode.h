#pragma once

/// <summary>
/// Узел бинарного дерева.
/// </summary>
struct BinaryTreeNode
{
    /// <summary>
    /// Указатель на левый дочерний узел.
    /// </summary>
    BinaryTreeNode* Left = nullptr;

    /// <summary>
    /// Указатель на правый дочерний узел.
    /// </summary>
    BinaryTreeNode* Right = nullptr;

    /// <summary>
    /// Значение, хранящееся в узле.
    /// </summary>
    int Data;

    /// <summary>
    /// Конструктор для инициализации узла.
    /// </summary>
    /// <param name="value">Значение, которое будет храниться в узле.</param>
    BinaryTreeNode(int value) : Left(nullptr), Right(nullptr), Data(value) {}
};
