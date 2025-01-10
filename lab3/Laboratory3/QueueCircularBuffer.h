#pragma once
#include "CircularBuffer.h"

/// <summary>
/// ��������� ������� �� ������ ���������� ������.
/// </summary>
struct QueueCircularBuffer
{
private:
    /// <summary>
    /// ��������� ����� ��� �������.
    /// </summary>
    CircularBuffer _circularBuffer;

public:
    /// <summary>
    /// �����������.
    /// </summary>
    /// <param name="size"></param>
    QueueCircularBuffer(int size);

    /// <summary>
    /// ����������.
    /// </summary>
    ~QueueCircularBuffer();

    /// <summary>
    /// ���������� �������� � �������.
    /// </summary>
    /// <param name="data"></param>
    void Enqueue(int data);

    /// <summary>
    /// ���������� �������� �� �������.
    /// </summary>
    /// <returns></returns>
    int Dequeue();

    /// <summary>
    /// ��������, ����� �� �������.
    /// </summary>
    /// <returns></returns>
    bool IsEmpty();

    /// <summary>
    /// ������������ ������ ��� �������.
    /// </summary>
    void Delete();

    /// <summary>
    /// ����� ���� ��������� �������.
    /// </summary>
    void Print();
};