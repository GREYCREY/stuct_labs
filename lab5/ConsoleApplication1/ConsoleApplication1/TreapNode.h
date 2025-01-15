#pragma once
#pragma once
#include <random>

// TODO: РџРѕР»РµС‚РµР»Р° РєРѕРґРёСЂРѕРІРєР° (РїРѕСЃРјРѕС‚СЂРµС‚СЊ РІРµР·РґРµ)
/// <summary>
/// пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ.
/// </summary>
struct TreapNode
{

	/// <summary>
	/// пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ.
	/// </summary>
	int Key;

	/// <summary>
	/// пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ.
	/// </summary>
	int Priority;

	/// <summary>
	/// пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	/// </summary>
	TreapNode* LeftNode = nullptr;

	/// <summary>
	/// пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ
	/// </summary>
	TreapNode* RightNode = nullptr;


	/// <summary>
   /// пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ Key пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ.
   /// </summary>
   /// <param name="key">пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ</param>
	TreapNode(int key)
	{
		Key = key;
		static std::mt19937 rng(std::random_device{}());
		Priority = std::uniform_int_distribution<int>(1, 1000000)(rng);
		LeftNode = nullptr;
		RightNode = nullptr;
	}
};