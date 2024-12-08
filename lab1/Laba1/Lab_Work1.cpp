#include "DynamicArray.h"
#include <iostream>
#include <limits>

// Функция для безопасного ввода целых чисел
int GetValidatedInput() {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (std::cin.fail()) 
        {
            // Сброс состояния ошибки
            std::cin.clear(); 
            // Очистка буфера
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число: ";
        }
        else 
        {
            // Удаление лишних символов
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return value;
        }
    }
}

void Menu() 
{
    DynamicArray arr;
    int choice, value, index;

    do 
    {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить элемент\n";
        std::cout << "2. Удалить элемент по индексу\n";
        std::cout << "3. Удалить элемент по значению\n";
        std::cout << "4. Вставить элемент в начало\n";
        std::cout << "5. Вставить элемент в конец\n";
        std::cout << "6. Вставить элемент после индекса\n";
        std::cout << "7. Линейный поиск элемента\n";
        std::cout << "8. Бинарный поиск элемента (требует сортировки)\n";
        std::cout << "9. Сортировать массив\n";
        std::cout << "10. Печать массива\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите опцию: ";
        choice = GetValidatedInput();

        switch (choice) 
        {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            value = GetValidatedInput();
            arr.AddToEnd(value);
            break;
        case 2:
            std::cout << "Введите индекс для удаления: ";
            index = GetValidatedInput();
            arr.RemoveAtIndex(index);
            break;
        case 3:
            std::cout << "Введите значение для удаления: ";
            value = GetValidatedInput();
            arr.RemoveValue(value);
            break;
        case 4:
            std::cout << "Введите элемент для вставки в начало: ";
            value = GetValidatedInput();
            arr.InsertAtStart(value);
            break;
        case 5:
            std::cout << "Введите элемент для вставки в конец: ";
            value = GetValidatedInput();
            arr.InsertAtEnd(value);
            break;
        case 6:
            std::cout << "Введите индекс для вставки: ";
            index = GetValidatedInput();
            std::cout << "Введите элемент для вставки: ";
            value = GetValidatedInput();
            arr.InsertAfterIndex(index, value);
            break;
        case 7:
            std::cout << "Введите элемент для поиска: ";
            value = GetValidatedInput();
            index = arr.LinearSearch(value);
            if (index != -1) {
                std::cout << "Элемент найден на позиции: " << index << std::endl;
            }
            else {
                std::cout << "Элемент не найден\n";
            }
            break;
        case 8:
            std::cout << "Введите элемент для бинарного поиска: ";
            value = GetValidatedInput();
            index = arr.BinarySearch(value);
            if (index != -1) {
                std::cout << "Элемент найден на позиции: " << index << std::endl;
            }
            else {
                std::cout << "Элемент не найден\n";
            }
            break;
        case 9:
            arr.CombSort();
            std::cout << "Массив отсортирован (сортировка расчёской).\n";
            break;
        case 10:
            arr.PrintElements();
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    Menu();
    return 0;
}
