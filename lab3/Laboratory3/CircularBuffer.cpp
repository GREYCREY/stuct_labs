#include "CircularBuffer.h"

/// <summary>
/// Конструктор.
/// </summary>
/// <param name="size"></param>
CircularBuffer::CircularBuffer(int size) : _bufferSize(size), _head(0), _tail(0), _currentSize(0)
{
    _buffer = new int[size];
}

/// <summary>
/// Деструктор.
/// </summary>
CircularBuffer::~CircularBuffer()
{
    Delete();
}

/// <summary>
/// Добавление элемента в кольцевой буфер с перезаписью старых данных при переполнении.
/// </summary>
/// <param name="data"></param>
void CircularBuffer::Add(int data)
{
    if (IsFull())
    {
        // При переполнении сдвигаем хвост вперёд
        _tail = (_tail + 1) % _bufferSize;
        _currentSize--;
    }
    _buffer[_head] = data;
    _head = (_head + 1) % _bufferSize;
    _currentSize++;
}

/// <summary>
/// Извлечение элемента из кольцевого буфера.
/// </summary>
/// <returns></returns>
int CircularBuffer::Remove()
{
    if (IsEmpty())
    {
        throw underflow_error("Кольцевой буфер пуст, невозможно извлечь элемент.");
    }
    int data = _buffer[_tail];
    _tail = (_tail + 1) % _bufferSize;
    _currentSize--;
    return data;
}

/// <summary>
/// Проверка, полный ли кольцевой буфер.
/// </summary>
/// <returns></returns>
bool CircularBuffer::IsFull()
{
    return _currentSize == _bufferSize;
}

/// <summary>
/// Проверка, пуст ли кольцевой буфер.
/// </summary>
/// <returns></returns>
bool CircularBuffer::IsEmpty()
{
    return _currentSize == 0;
}

/// <summary>
/// Получение текущего размера кольцевого буфера.
/// </summary>
/// <returns></returns>
int CircularBuffer::Size()
{
    return _currentSize;
}

/// <summary>
/// Вывод всех элементов кольцевого буфера.
/// </summary>
void CircularBuffer::Print()
{
    if (IsEmpty())
    {
        cout << "Кольцевой буфер пуст." << endl;
        return;
    }

    cout << "Вывод кольцевого буфера: ";
    for (int i = 0; i < _currentSize; ++i)
    {
        cout << _buffer[(_tail + i) % _bufferSize] << " ";
    }
    cout << endl;
}

/// <summary>
/// Освобождение памяти кольцевого буфера.
/// </summary>
void CircularBuffer::Delete() {
    delete[] _buffer;
    _buffer = nullptr;
    _bufferSize = 0;
    _head = 0;
    _tail = 0;
    _currentSize = 0;
}