#include "ListItem.h" 

// ����������� ������ Node
// �������������� ���� ������ � �������� ��������� � ������������� ��������� Prev � Next � nullptr
Node::Node(int value)
    : Data(value), Prev(nullptr), Next(nullptr) {}
