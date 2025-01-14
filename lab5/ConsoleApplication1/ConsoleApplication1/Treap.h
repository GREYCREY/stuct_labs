#pragma once
#include "TreapNode.h"
/// <summary>
/// ��������� ������.
/// </summary>
struct Treap
{
	/// <summary>
	/// ��������� �� �������� ���� ������.
	/// </summary>
	TreapNode* Root;
	Treap() : Root(nullptr) {}
};

/// <summary>
/// ����� �������� � ���������� ������.
/// </summary>
/// <param name="node">���� ������</param>
/// <param name="key">������� ��������.</param>
/// <returns></returns>
TreapNode* FindElement(TreapNode* node, int key);

/// <summary>
/// ���������� ������ �� ��� ������ �� ��������
/// </summary>
/// <param name="node">���� ������.</param>
/// <param name="key">�������� ��� ����������.</param>
/// <param name="left">����� ������</param>
/// <param name="right">������ ������.</param>
void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

/// <summary>
/// ������� ���� �������� � ����
/// </summary>
/// <param name="left">����� ������</param>
/// <param name="right">������ ������</param>
/// <returns></returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

/// <summary>
/// ������� ���������� ���� � ������ ������������ ������������������ ��������
/// </summary>
/// <param name="node">���� ������</param>
/// <param name="key">��������</param>
void AddNotOptimized(TreapNode*& node, int key);

/// <summary>
///  ������� ���������� ���� � ������ ������������ ���������������� ��������
/// </summary>
/// <param name="node">���� ������</param>
/// <param name="key">��������</param>
void AddOptimized(TreapNode*& node, int key);


/// <summary>
/// ������� �������� ����� �� ������ c ������ ������, ���������� ������������������ ��������
/// </summary>
/// <param name="node">���� ������</param>
/// <param name="key">��������</param>
/// <param name="success">������ ��������</param>
void RemoveNotOptimized(TreapNode*& node, int key, bool& success);


/// <summary>
/// ������� �������� ����� �� ������ c ������ ������, ���������� ��������������� ��������
/// </summary>
/// <param name="node">���� ������</param>
/// <param name="key">��������</param>
/// <param name="success">������ ��������</param>
void RemoveOptimized(TreapNode*& node, int key, bool& success);


/// <summary>
/// �������� ��������.
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
int GetValue(TreapNode* node, int key);
