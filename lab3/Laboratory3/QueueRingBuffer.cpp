#include "QueueCircularBuffer.h"

/// <summary>
/// �����������.
/// </summary>
/// <param name="size"></param>
QueueCircularBuffer::QueueCircularBuffer(int size) : _circularBuffer(size) {}

/// <summary>
/// ����������.
/// </summary>
QueueCircularBuffer::~QueueCircularBuffer()
{
    Delete(); // ������������ ������
}

/// <summary>
/// ���������� �������� � �������.
/// </summary>
/// <param name="data"></param>
void QueueCircularBuffer::Enqueue(int data)
{
    if (!_circularBuffer.IsFull()) { // ���������, �� ����������� �� �������
        _circularBuffer.Add(data);
    }
    else {
        cout << "������� �����������. ������� �� ��������: " << data << endl;
    }
}

/// <summary>
/// ���������� �������� �� �������.
/// </summary>
/// <returns></returns>
int QueueCircularBuffer::Dequeue()
{
    return _circularBuffer.Remove();
}

/// <summary>
/// ��������, ����� �� �������.
/// </summary>
/// <returns></returns>
bool QueueCircularBuffer::IsEmpty()
{
    return _circularBuffer.IsEmpty();
}

/// <summary>
/// ����� ��� ������ ���� ��������� �������.
/// </summary>
void QueueCircularBuffer::Print() {
    cout << "����� �������: ";
    _circularBuffer.Print();
}

/// <summary>
/// ������������ ������ ��� �������
/// </summary>
void QueueCircularBuffer::Delete()
{
    _circularBuffer.Delete();
}