#include <iostream>
#include "Stack.h"
#include "QueueStack.h"
#include "QueueRingBuffer.h"
#include "RingBuffer.h"

using namespace std;

void DisplayStackMenu(Stack& stack)
{
    while (true)
    {
        cout << endl << "------------------------------------" << endl;
        cout << "Лабораторная работа #2 - стек" << endl;
        cout << endl << "Текущий стек: ";
        stack.Print();
        cout << endl;
        cout << "Выберите команду:" << endl;
        cout << "1. Добавить (Push) элемент в стек" << endl;
        cout << "2. Достать (Pop) элемент из стека" << endl;
        cout << "0. Выйти в меню" << endl;
        cout << endl << "Ваш ввод: ";

        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            int value;
            cout << "Введите значение для элемента: ";
            cin >> value;
            try
            {
                stack.Push(value);
                cout << "Введенное значение: " << value << endl;
            }
            catch (const overflow_error& e)
            {
                cout << e.what() << endl; // Обработаем ошибку переполнения
            }
            break;
        }
        case 2:
        {
            try
            {
                cout << "Взятый элемент: " << stack.Pop() << endl;
            }
            catch (const underflow_error& e)
            {
                cout << e.what() << endl; // Обрабатываем ошибку пустого стека
            }
            break;
        }
        case 0:
            return;
        default:
            cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
        }
    }
}

void DisplayRingBufferMenu(RingBuffer& ringBuffer)
{
    while (true)
    {
        cout << endl << "------------------------------------" << endl;
        cout << "Лабораторная работа #2 - кольцевой буфер" << endl;
        cout << endl << "Текущий кольцевой буфер: ";
        ringBuffer.Print();
        cout << "Выберите команду:" << endl;
        cout << "1. Добавить элемент в кольцевой буфер" << endl;
        cout << "2. Удалить элемент из кольцевого буфера" << endl;
        cout << "0. Выйти в меню" << endl;
        cout << endl << "Ваш ввод: ";

        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            int value;
            cout << "Введите значение для элемента: ";
            cin >> value;
            try
            {
                ringBuffer.Add(value);
                cout << "Введенное значение: " << value << endl;
            }
            catch (const overflow_error& e)
            {
                cout << e.what() << endl; // Обрабатываем ошибку переполнения
            }
            break;
        }
        case 2:
        {
            try
            {
                cout << "Удаленный элемент " << ringBuffer.Remove() << endl;
            }
            catch (const underflow_error& e)
            {
                cout << e.what() << endl; // Обрабатываем ошибку пустого буфера
            }
            break;
        }
        case 0:
            return; // Возвращаемся в главное меню
        default:
            cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
            return;
        }
    }
}

void DisplayQueueStackMenu(QueueStack& queueStack)
{
    while (true)
    {
        cout << endl << "------------------------------------" << endl;
        cout << "Лабораторная работа #2 - очередь на основе стеков" << endl;
        cout << endl << "Current queueStack: ";
        queueStack.Print();
        cout << "Выберите команду:" << endl;
        cout << "1. Добавить (Enqueue) элемент" << endl;
        cout << "2. Удалить (Dequeue) элемент" << endl;
        cout << "0. Выйти в меню" << endl;
        cout << endl << "Ваш ввод: ";

        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            int value;
            cout << "Введите значение для добавления: ";
            cin >> value;
            queueStack.Enqueue(value);
            cout << "Введенное значение: " << value << endl;
            break;
        }
        case 2:
        {
            try
            {
                cout << "Удаленный элемент: " << queueStack.Dequeue() << endl;
            }
            catch (const underflow_error& e)
            {
                cout << e.what() << endl; // Обрабатываем ошибку пустой очереди
            }
            break;
        }
        case 0:
            return; // Возвращаемся в главное меню
        default:
            cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
        }
    }
}

void DisplayQueueRingBufferMenu(QueueRingBuffer& queueRingBuffer)
{
    while (true)
    {
        cout << endl << "------------------------------------" << endl;
        cout << "Лабораторная работа #2 - очередь на основе кольцевого буфера" << endl;
        cout << endl << "Текущий кольцевой буфер: ";
        queueRingBuffer.Print();
        cout << "Выберите команду:" << endl;
        cout << "1. Добавить (Enqueue) элемент" << endl;
        cout << "2. Удалить (Dequeue) элемент" << endl;
        cout << "0. Выйти в меню" << endl;
        cout << endl << "Ваш ввод: ";

        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
        {
            int value;
            cout << "Введите значение для добавления: ";
            cin >> value;
            queueRingBuffer.Enqueue(value);
            cout << "Введенное значение: " << value << endl;
            break;
        }
        case 2:
        {
            try
            {
                cout << "Удаленный элемент: " << queueRingBuffer.Dequeue() << endl;
            }
            catch (const underflow_error& e)
            {
                cout << e.what() << endl; // Обрабатываем ошибку пустой очереди
            }
            break;
        }
        case 0:
            return; // Возвращаемся в главное меню
        default:
            cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");

    Stack myStack(5);
    RingBuffer myRingBuffer(5);
    QueueStack myQueueStack(5);
    QueueRingBuffer myQueueRingBuffer(5);

    while (true)
    {
        cout << endl << "------------------------------------" << endl;
        cout << "Меню" << endl;
        cout << "1. Стек" << endl;
        cout << "2. Кольцевой буфер" << endl;
        cout << "3. Очередь на основе стеков" << endl;
        cout << "4. Очередь на основе кольцевого буфера" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш ввод: ";

        int menuChoice;
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            DisplayStackMenu(myStack);
            break;
        case 2:
            DisplayRingBufferMenu(myRingBuffer);
            break;
        case 3:
            DisplayQueueStackMenu(myQueueStack);
            break;
        case 4:
            DisplayQueueRingBufferMenu(myQueueRingBuffer);
            break;
        case 0:
            return 0;
        default:
            cout << "Неизвестная комманда. Попробуйте еще раз." << endl;
        }
    }
    return 0;
}