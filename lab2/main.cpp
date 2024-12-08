#include <iostream>
#include "List.h"

using namespace std;

void DisplayMenu()
{
    cout << "Меню: " << endl;
    cout << "1. Добавить элемент " << endl;
    cout << "2. Удалить элемент " << endl;
    cout << "3. Вставить элемент в начало " << endl;
    cout << "4. Вставить элемент в конец " << endl;
    cout << "5. Вставить элемент после " << endl;
    cout << "6. Вставить элемент перед " << endl;
    cout << "7. Отсортировать список " << endl;
    cout << "8. Поиск элемента " << endl;
    cout << "9. Время выполнения" << endl;
    cout << "0. Выход " << endl;
}

int GetValidatedInput()
{
    int value;
    while (true)
    {
        cin >> value;
        if (cin.fail())
        {
            // Сбрасываем состояние потока
            cin.clear(); 
            // Очищаем буфер
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Ошибка ввода! Пожалуйста, введите целое число: ";
        }
        else
        {
            // Очищаем буфер от лишних символов
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            return value;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    DoublyLinkedList list;
    int choice, value, target;

    do
    {
        cout << "Текущий список: ";
        list.PrintList();
        DisplayMenu();
        cout << "Выберите действие: ";
        choice = GetValidatedInput();

        switch (choice)
        {
        case 1:
            cout << "Введите значение для добавления: ";
            value = GetValidatedInput();
            list.InsertAtEnd(value);
            break;
        case 2:
            cout << "Введите значение для удаления: ";
            value = GetValidatedInput();
            list.Remove(value);
            break;
        case 3:
            cout << "Введите значение для вставки в начало: ";
            value = GetValidatedInput();
            list.InsertAtBeginning(value);
            break;
        case 4:
            cout << "Введите значение для вставки в конец: ";
            value = GetValidatedInput();
            list.InsertAtEnd(value);
            break;
        case 5:
            cout << "Введите значение после которого вставить: ";
            target = GetValidatedInput();
            cout << "Введите значение для вставки: ";
            value = GetValidatedInput();
            list.InsertAfter(target, value);
            break;
        case 6:
            cout << "Введите значение перед которым вставить: ";
            target = GetValidatedInput();
            cout << "Введите значение для вставки: ";
            value = GetValidatedInput();
            list.InsertBefore(target, value);
            break;
        case 7:
            list.BubbleSort();
            cout << "Список отсортирован.";
            break;
        case 8:
            cout << "Введите значение для поиска: ";
            value = GetValidatedInput();
            if (list.LinearSearch(value)) {
                cout << "Элемент найден: " << value;
            }
            else {
                cout << "Элемент не найден: " << value;
            }
            break;
        case 9:
            cout << "Эта функция пока не реализована.";
            break;
        case 0:
            cout << "Выход из программы.";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.";
            break;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}
