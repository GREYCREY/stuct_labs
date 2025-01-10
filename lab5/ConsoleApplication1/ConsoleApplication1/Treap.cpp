#include "Treap.h"


void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key < key)
	{
		Split(node->RightNode, key, node->RightNode, right);
		left = node;
	}
	else
	{
		Split(node->LeftNode, key, left, node->LeftNode);
		right = node;
	}
}


TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (!left || !right)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->RightNode = Merge(left->RightNode, right);
		return left;
	}

	right->LeftNode = Merge(left, right->LeftNode);
	return right;
}


void AddNotOptimized(TreapNode*& node, int key)
{
	TreapNode* newNode = new TreapNode(key);
	TreapNode* less = nullptr;
	TreapNode* bigger = nullptr;
	Split(node, key, less, bigger);
	node = Merge(Merge(less, newNode), bigger);
}


void AddOptimized(TreapNode*& node, int key)
{
	if (!node)
	{
		node = new TreapNode(key);
		node->Key = key;
		return;
	}

	TreapNode* newNode = new TreapNode(key);

	if (node->Priority > newNode->Priority)
	{
		if (key < node->Key)
		{
			AddOptimized(node->LeftNode, key);
		}
		else
		{
			AddOptimized(node->RightNode, key);
		}
		return;
	}

	newNode->Key = key;
	Split(node, key, newNode->LeftNode, newNode->RightNode);
	node = newNode;
}


void RemoveOptimized(TreapNode*& node, int key, bool& success)
{
	if (!node)
	{
		success = false;
		return;
	}

	if (key > node->Key)
	{
		RemoveOptimized(node->RightNode, key, success);
	}
	else if (key < node->Key)
	{
		RemoveOptimized(node->LeftNode, key, success);
	}
	else
	{
		TreapNode* temp = node;
		node = Merge(node->LeftNode, node->RightNode);
		delete temp;
	}
}


void RemoveNotOptimized(TreapNode*& node, int key, bool& success)
{
	TreapNode* less = nullptr;
	TreapNode* equal = nullptr;
	TreapNode* bigger = nullptr;

	Split(node, key, less, bigger);
	Split(bigger, key + 1, equal, bigger);
	if (!equal)
	{
		success = false;
	}

	node = Merge(less, bigger);
	delete equal;
}

TreapNode* FindElement(TreapNode* node, int key)
{
	if (!node)
	{
		return nullptr;
	}

	if (node->Key == key)
	{
		return node;
	}

	if (key > node->Key)
	{
		return FindElement(node->RightNode, key);
	}

	return FindElement(node->LeftNode, key);
}


int GetValue(TreapNode* node, int key)
{
	TreapNode* findValue = FindElement(node, key);
	if (findValue != nullptr)
	{
		return findValue->Key;
	}
	else
	{
		return 0;
	}
}
