#pragma once
#pragma once
#include <random>

/// <summary>
/// Узел декартового дерева.
/// </summary>
struct TreapNode
{

	/// <summary>
	/// Значение узла.
	/// </summary>
	int Key;
	/// <summary>
	/// Приоритет узла.
	/// </summary>
	int Priority;
	/// <summary>
	/// Указатель на левый узел
	/// </summary>
	TreapNode* LeftNode = nullptr;
	/// <summary>
	/// Указатель на правый узел
	/// </summary>
	TreapNode* RightNode = nullptr;


	/// <summary>
   /// Конструктор узла с инициализацией Key и случайным приоритетом.
   /// </summary>
   /// <param name="key">Ключ узла</param>
	TreapNode(int key)
	{
		Key = key;
		static std::mt19937 rng(std::random_device{}());
		Priority = std::uniform_int_distribution<int>(1, 1000000)(rng);
		LeftNode = nullptr;
		RightNode = nullptr;
	}
};