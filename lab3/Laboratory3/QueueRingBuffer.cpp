#include "QueueRingBuffer.h"

/// <summary>
/// �����������.
/// </summary>
/// <param name="size"></param>
QueueRingBuffer::QueueRingBuffer(int size) : _ringBuffer(size) {}

/// <summary>
/// ����������.
/// </summary>
QueueRingBuffer::~QueueRingBuffer()
{
    Delete(); // ������������ ������
}

/// <summary>
/// ���������� �������� � �������.
/// </summary>
/// <param name="data"></param>
void QueueRingBuffer::Enqueue(int data)
{
    _ringBuffer.Add(data);
}

/// <summary>
/// ���������� �������� �� �������.
/// </summary>
/// <returns></returns>
int QueueRingBuffer::Dequeue()
{
    return _ringBuffer.Remove();
}

/// <summary>
/// ��������, ����� �� �������.
/// </summary>
/// <returns></returns>
bool QueueRingBuffer::IsEmpty()
{
    return _ringBuffer.IsEmpty();
}

/// <summary>
/// ����� ��� ������ ���� ��������� �������.
/// </summary>
void QueueRingBuffer::Print() {
    cout << "����� �������: ";
    _ringBuffer.Print();
}

/// <summary>
/// ������������ ������ ��� �������
/// </summary>
void QueueRingBuffer::Delete()
{
    _ringBuffer.Delete();
}