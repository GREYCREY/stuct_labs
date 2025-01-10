#include <iostream>
#include <tuple>
#include <string>
#include <iomanip>
#include <vector>
#include <memory>
#include "BinaryTree.h"
#include <sstream>
#include "Treap.h"
using namespace std;





/// <summary>
/// Валидация ввода числа.
/// </summary>
/// <returns>Число, введённое пользователем.</returns>
static int CinInt()
{
    string input;
    int number;

    while (true)
    {
        cin >> input;

        stringstream ss(input);
        if (ss >> number && ss.eof())
        {
            break;
        }

        cout << "Error!" << endl;
    }
    return number;
}

/// <summary>
/// Выбрать обработчик конкретной структуры данных.
/// </summary>
/// <param name="action">Номер действия.</param>
/// <param name="flag">Флаг.</param>
void SelectDSHandler(int& action, bool& flag)
{
    int newAction = CinInt();
    system("cls");
    if (newAction == 0)
    {
        flag = false;
    }
    else if (newAction > 0 && newAction < 3)
    {
        action = newAction;
    }
    else
    {
        cout << "Invalid command!" << endl;
    }
}



/// <summary>
/// Меню для работы с бинарным деревом поиска.
/// </summary>
void BSTreeActionsHandler(BinaryTree* bsTree, int& action)
{
    int cmd = CinInt();
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        cout << "[1] Enter the value to insert: ";
        int value = CinInt();
        Insert(bsTree->Root, value);
        break;
    }
    case 2:
    {
        cout << "[2] Enter the value to remove: ";
        int value = CinInt();
        Remove(bsTree->Root, value);
        break;
    }
    case 3:
    {
        cout << "[3] Enter the value to find: ";
        int valueToFind = CinInt();
        try
        {
            BinaryTreeNode* node = Find(bsTree->Root, valueToFind);
            if (node != nullptr)
                cout << "Found value: " << node->Data << endl;
            else
                cout << "Value not found." << endl;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
        break;

    }
    case 4:
    {
        try
        {
            BinaryTreeNode* minNode = FindMinimal(bsTree->Root);
            if (minNode != nullptr)
                cout << "Minimum value: " << minNode->Data << endl;
            else
                cout << "Tree is empty." << endl;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
        break;
    }
    case 5:
    {
        try
        {
            BinaryTreeNode* maxNode = FindMaximal(bsTree->Root);
            if (maxNode != nullptr)
                cout << "Maximum value: " << maxNode->Data << endl;
            else
                cout << "Tree is empty." << endl;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }
        break;
    }
    case 0:
    {
        action = 0;
        break;
    }
    default:
    {
        cout << "Invalid command!" << endl;
    }
    }
}

/// <summary>
/// Меню для работы со СД Декартово дерево.
/// </summary>
/// <param name="bsTree">Экземпляр СД.</param>
/// <param name="action">Номер действия.</param>
void TreapActionsHandler(Treap* treap, int& action)
{
    int cmd = CinInt();
    system("cls");
    switch (cmd)
    {
    case 1:
    {

        cout << "[1] Enter the value: ";
        int value = CinInt();
        AddNotOptimized(treap->Root, value);
        break;
    }
    case 2:
    {
        cout << "[2] Enter the key: ";
        int key = CinInt();
        bool success = true;
        try
        {
            RemoveNotOptimized(treap->Root, key, success);
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
        break;
    }
    case 3:
    {
        cout << "[3] Enter the value: ";
        int value = CinInt();
        AddOptimized(treap->Root, value);
        break;
    }
    case 4:
    {
        cout << "[4] Enter the key: ";
        int key = CinInt();
        bool success = true;
        try
        {
            RemoveOptimized(treap->Root, key, success);
        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
        break;
    }
    case 5:
    {
        cout << "[5] Enter the key: ";
        int key = CinInt();
        try
        {
            cout << "Found value: " << GetValue(treap->Root, key) << endl;

        }
        catch (exception& e)
        {
            cout << e.what() << '\n';
        }
        break;
    }
    case 0:
    {
        action = 0;
        break;
    }
    default:
    {
        cout << "Invalid command!" << endl;
    }
    }
}



/// <summary>
/// Печать бинарного дерева.
/// </summary>
void ShowBinaryTree(BinaryTreeNode const* node, bool high, vector<string> const& lpref, vector<string> const& cpref, vector<string> const& rpref, bool root, bool left, shared_ptr<vector<vector<string>>> lines)
{
    if (!node) return;
    typedef vector<string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = make_shared<vector<VS>>();
    if (node->Left)
        ShowBinaryTree(node->Left, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ "/", "|" }) : VS({ "/" })), VSCat(lpref, high ? VS({ "-", " " }) : VS({ "-" })), false, true, lines);

    auto sval = "[" + to_string(node->Data) + "]";
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i) {
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { string(1, sval[i]) }));
    }
    if (node->Right)
        ShowBinaryTree(node->Right, high, VSCat(rpref, high ? VS({ "-", " " }) : VS({ "-" })), VSCat(rpref, high ? VS({ "\\", "|" }) : VS({ "\\" })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);
    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                }
                else
                    line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            cout << out[i] << endl;
    }
}

/// <summary>
/// Передаем параметры - в функцию для отображений бинарного деерва.
/// </summary>
void PrintTree(BinaryTreeNode* root)
{
    ShowBinaryTree(root, true, {}, {}, {}, true, false, nullptr);
}

/// <summary>
/// Печать декартова дерева с учетом приоритета.
/// </summary>
void ShowCartesianTreeWithPriority(TreapNode const* node, bool high, vector<string> const& lpref, vector<string> const& cpref, vector<string> const& rpref, bool root, bool left, shared_ptr<vector<vector<string>>> lines)
{
    if (!node) return;
    typedef vector<string> VS;
    auto VSCat = [](VS const& a, VS const& b) { auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = make_shared<vector<VS>>();

    
    if (node->LeftNode)
        ShowCartesianTreeWithPriority(node->LeftNode, high, VSCat(lpref, high ? VS({ " ", " " }) : VS({ " " })), VSCat(lpref, high ? VS({ "/", "|" }) : VS({ "/" })), VSCat(lpref, high ? VS({ "-", " " }) : VS({ "-" })), false, true, lines);

    
    auto sval = "[" + to_string(node->Key) + "] (Priority: " + to_string(node->Priority) + ")";
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i) {
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, { string(1, sval[i]) }));
    }

    
    if (node->RightNode)
        ShowCartesianTreeWithPriority(node->RightNode, high, VSCat(rpref, high ? VS({ "-", " " }) : VS({ "-" })), VSCat(rpref, high ? VS({ "\\", "|" }) : VS({ "\\" })), VSCat(rpref, high ? VS({ " ", " " }) : VS({ " " })), false, false, lines);

    
    if (root) {
        VS out;
        for (size_t l = 0;; ++l) {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                }
                else
                    line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            cout << out[i] << endl;
    }
}

/// <summary>
/// Передаем параметры - в функцию для отображения декартова дерева с приоритетами.
/// </summary>
void ShowTreap(TreapNode* root)
{
    ShowCartesianTreeWithPriority(root, true, {}, {}, {}, true, false, nullptr);
}



int main()
{
    BinaryTree* bsTree = new BinaryTree();
    Treap* treap = new Treap();
    int action = 0;
    bool flag = true;

    while (flag)
    {

        switch (action)
        {
        case 1:
        {
            cout << "Current Binary Search Tree: " << endl;
            PrintTree(bsTree->Root);
            cout << "\nTree actions:" << endl;
            cout << "[1] Add item" << endl;
            cout << "[2] Remove item" << endl;
            cout << "[3] Find an item" << endl;
            cout << "[4] Get the minimum value" << endl;
            cout << "[5] Get the maximum value" << endl;
            cout << "[0] Back to the main menu" << endl;
            cout << "\nSelect an action: ";
            BSTreeActionsHandler(bsTree, action);
            break;
        }
        case 2:
        {
            cout << "Current Treap: " << endl;
            ShowTreap(treap->Root);
            cout << "Stack actions:" << endl;
            cout << "[1] Add item" << endl;
            cout << "[2] Remove item" << endl;
            cout << "[3] Add optimized item" << endl;
            cout << "[4] Remove optimized item" << endl;
            cout << "[5] Find an item" << endl;
            cout << "[0] Back" << endl << endl;
            TreapActionsHandler(treap, action);
            break;
        }
        default:
        {
            cout << "Select the data structure:" << endl;
            cout << "[1] Binary Search Tree" << endl;
            cout << "[2] Treap" << endl;
            cout << "[0] Exit the program" << endl << endl;
            SelectDSHandler(action, flag);
            break;
        }
        }
    }

    delete bsTree;
    return 0;
}
