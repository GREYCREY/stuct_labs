#pragma once
#include "TreapNode.h"
/// <summary>
/// Декартово дерево.
/// </summary>
struct Treap
{
	/// <summary>
	/// Указатель на корневой узел дерева.
	/// </summary>
	TreapNode* Root;
	Treap() : Root(nullptr) {}
};

/// <summary>
/// Поиск элемента в декартовом дереве.
/// </summary>
/// <param name="node">Узел дерева</param>
/// <param name="key">Искомое значение.</param>
/// <returns></returns>
TreapNode* FindElement(TreapNode* node, int key);

/// <summary>
/// Разделение дерева на два дерева по значению
/// </summary>
/// <param name="node">Узел дерева.</param>
/// <param name="key">Критерий для разделения.</param>
/// <param name="left">Левое дерево</param>
/// <param name="right">Правое дерево.</param>
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// Слияние двух деревьев в одно
/// </summary>
/// <param name="left">Левое дерево</param>
/// <param name="right">Правое дерево</param>
/// <returns></returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// Функция добавление узла в дерево использующая неоптимизированный алгоритм
/// </summary>
/// <param name="node">Узел дерева</param>
/// <param name="key">Значение</param>
void AddNotOptimized(TreapNode*& node, int key);

/// <summary>
///  Функция добавления узла в дерево использующая оптимизированный алгоритм
/// </summary>
/// <param name="node">Узел дерева</param>
/// <param name="key">Значение</param>
void AddOptimized(TreapNode*& node, int key);


/// <summary>
/// Функция удаления узлов из дерева c равным ключем, использует неоптимизированный алгоритм
/// </summary>
/// <param name="node">Узел дерева</param>
/// <param name="key">Значение</param>
/// <param name="success">Статус удаления</param>
void RemoveNotOptimized(TreapNode*& node, int key, bool& success);


/// <summary>
/// Функция удаления узлов из дерева c равным ключем, использует птимизированный алгоритм
/// </summary>
/// <param name="node">Узел дерева</param>
/// <param name="key">Значение</param>
/// <param name="success">Статус удаления</param>
void RemoveOptimized(TreapNode*& node, int key, bool& success);


/// <summary>
/// Получить значение.
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
int GetValue(TreapNode* node, int key);
