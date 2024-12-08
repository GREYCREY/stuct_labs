#pragma once

#include <iostream>

class DynamicArray {
private:
    int* _array;
    int _length;
    int _capacity;
    // ����������� �����
    const float GrowthFactor = 2.0;  

    // ������� ��� ��������� ������� �������
    void resize(int newCapacity);

public:
    // �����������, ��������� ������ � �������� ��������� ��������
    DynamicArray(int initCapacity = 4);

    // ����������
    ~DynamicArray();

    // ��������� ����� �������
    int GetLength() const;

    // ������� ��� ���������� �������� � �����
    void AddToEnd(int value);

    // ������� ��� �������� �������� �� �������
    void RemoveAtIndex(int index);

    // ������� ��� �������� �������� �� ��������
    void RemoveValue(int value);

    // ������� �������� � ������ �������
    void InsertAtStart(int value);
    // ������� �������� � ����� ������� 
    void InsertAtEnd(int value);

    // ������� �������� ����� ������������� �������
    void InsertAfterIndex(int index, int value);

    // �������� ����� �������� � �������
    int LinearSearch(int value) const;

    // �������� ����� �������� � ������� (������� ���������������� �������)
    int BinarySearch(int value) const;

    // ���������� ��������� (Comb Sort)
    void CombSort();

    // ����� ��������� �������
    void PrintElements() const;
};
