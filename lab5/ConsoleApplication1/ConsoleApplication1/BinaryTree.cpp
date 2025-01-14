#include "BinaryTree.h"
#include "BinaryTree.h"
#include <iostream>
#include <exception>
using namespace std;

void Insert(BinaryTreeNode*& node, int value)
{
	if (node == nullptr)
	{
		node = new BinaryTreeNode(value);

	}

	else if (value < node->Data)
	{
		Insert(node->Left, value);
	}
	else
	{
		Insert(node->Right, value);
	}
}

BinaryTreeNode* Find(BinaryTreeNode* node, const int value)
{
	while (node != nullptr)
	{
		if (node->Data == value)
		{
			return node;
		}
		else if (value < node->Data)
		{
			node = node->Left;
		}
		else
		{
			node = node->Right;
		}
	}
	return nullptr;
}

BinaryTreeNode* FindMinimal(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}


BinaryTreeNode* FindMaximal(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}

void Remove(BinaryTreeNode*& node, const int value)
{
	if (node == nullptr)
	{
		return;
	}

	if (value < node->Data)
	{
		Remove(node->Left, value);
	}
	else if (value > node->Data)
	{
		Remove(node->Right, value);
	}
	else if (node->Left != nullptr && node->Right != nullptr)
	{
		node->Data = FindMinimal(node->Right)->Data;
		Remove(node->Right, node->Data);
	}
	else
	{
		BinaryTreeNode* current = nullptr;
		if (node->Left != nullptr)
		{
			current = node;
			node = current->Left;
			delete current;
		}
		else if (node->Right != nullptr)
		{
			current = node;
			node = current->Right;
			delete current;
		}
		else
		{
			delete node;
			node = nullptr;
		}
	}

	return;
}









