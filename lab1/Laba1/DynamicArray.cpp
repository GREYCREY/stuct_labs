#include "DynamicArray.h"

// ������� ��� ��������� ������� �������
void DynamicArray::resize(int newCapacity) {
    int* newArray = new int[newCapacity];
    for (int i = 0; i < _length; ++i) {
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;
    _capacity = newCapacity;
}

// �����������, ��������� ������ � �������� ��������� ��������
DynamicArray::DynamicArray(int initCapacity) : _length(0), _capacity(initCapacity) {
    _array = new int[_capacity];
}

// ����������
DynamicArray::~DynamicArray() {
    delete[] _array;
}

// ��������� ����� �������
int DynamicArray::GetLength() const {
    return _length;
}

// ������� ��� ���������� �������� � �����
void DynamicArray::AddToEnd(int value) {
    if (_length == _capacity) {
        resize(static_cast<int>(_capacity * GrowthFactor));
    }
    _array[_length++] = value;
}

// ������� ��� �������� �������� �� �������
void DynamicArray::RemoveAtIndex(int index) {
    if (index < 0 || index >= _length) {
        std::cerr << "Invalid index\n";
        return;
    }
    for (int i = index; i < _length - 1; ++i) {
        _array[i] = _array[i + 1];
    }
    --_length;
    if (_capacity > 4 && _length < _capacity / GrowthFactor) {
        resize(static_cast<int>(_capacity / GrowthFactor));
    }
}

// ������� ��� �������� �������� �� ��������
void DynamicArray::RemoveValue(int value) {
    int index = LinearSearch(value);
    if (index != -1) {
        RemoveAtIndex(index);
    }
}

// ������� �������� � ������ �������
void DynamicArray::InsertAtStart(int value) {
    if (_length == _capacity) {
        resize(static_cast<int>(_capacity * GrowthFactor));
    }
    for (int i = _length; i > 0; --i) {
        _array[i] = _array[i - 1];
    }
    _array[0] = value;
    ++_length;
}

void DynamicArray::InsertAtEnd(int value)
{
    AddToEnd(value);
}

// ������� �������� ����� ������������� �������
void DynamicArray::InsertAfterIndex(int index, int value) {
    if (index < 0 || index >= _length) {
        std::cerr << "Invalid index\n";
        return;
    }
    if (_length == _capacity) {
        resize(static_cast<int>(_capacity * GrowthFactor));
    }
    for (int i = _length; i > index + 1; --i) {
        _array[i] = _array[i - 1];
    }
    _array[index + 1] = value;
    ++_length;
}

// �������� ����� �������� � �������
int DynamicArray::LinearSearch(int value) const {
    for (int i = 0; i < _length; ++i) {
        if (_array[i] == value) {
            return i;
        }
    }
    return -1;
}

// �������� ����� �������� � ������� (������� ���������������� �������)
int DynamicArray::BinarySearch(int value) const {
    int left = 0, right = _length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (_array[mid] == value) {
            return mid;
        }
        else if (_array[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

// ���������� ��������� (Comb Sort)
void DynamicArray::CombSort() {
    int gap = _length;
    const float shrinkFactor = 1.3;
    bool sorted = false;
    while (!sorted) {
        gap = static_cast<int>(gap / shrinkFactor);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }
        for (int i = 0; i + gap < _length; ++i) {
            if (_array[i] > _array[i + gap]) {
                std::swap(_array[i], _array[i + gap]);
                sorted = false;
            }
        }
    }
}

// ����� ��������� �������
void DynamicArray::PrintElements() const {
    for (int i = 0; i < _length; ++i) {
        std::cout << _array[i] << " ";
    }
    std::cout << std::endl;
}
