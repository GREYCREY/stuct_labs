#pragma once
#pragma once
#include <random>

// TODO: Полетела кодировка (посмотреть везде)
/// <summary>
/// ���� ����������� ������.
/// </summary>
struct TreapNode
{

	/// <summary>
	/// �������� ����.
	/// </summary>
	int Key;

	/// <summary>
	/// ��������� ����.
	/// </summary>
	int Priority;

	/// <summary>
	/// ��������� �� ����� ����
	/// </summary>
	TreapNode* LeftNode = nullptr;

	/// <summary>
	/// ��������� �� ������ ����
	/// </summary>
	TreapNode* RightNode = nullptr;


	/// <summary>
   /// ����������� ���� � �������������� Key � ��������� �����������.
   /// </summary>
   /// <param name="key">���� ����</param>
	TreapNode(int key)
	{
		Key = key;
		static std::mt19937 rng(std::random_device{}());
		Priority = std::uniform_int_distribution<int>(1, 1000000)(rng);
		LeftNode = nullptr;
		RightNode = nullptr;
	}
};