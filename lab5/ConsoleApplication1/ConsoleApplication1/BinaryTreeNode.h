#pragma once
#pragma once
/// <summary>
/// Узел бинарного дерева
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// указатель на левый  дочерний узел
	/// </summary>
	BinaryTreeNode* Left = nullptr;
	/// <summary>
	/// указатель на правый  дочерний узел
	/// </summary>
	BinaryTreeNode* Right = nullptr;
	/// <summary>
	/// Данные, которые содержит узел
	/// </summary>
	int Data;
	/// <summary>
	/// Конструктор для инициализации полей
	/// </summary>
	/// <param name="value"></param>
	BinaryTreeNode(int value) : Left(nullptr), Right(nullptr), Data(value) {}

};

