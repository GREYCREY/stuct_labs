#include "DynamicArray.h"
#include <iostream>
#include <limits>

// ������� ��� ����������� ����� ����� �����
int GetValidatedInput() {
    int value;
    while (true) 
    {
        std::cin >> value;
        if (std::cin.fail()) 
        {
            // ����� ��������� ������
            std::cin.clear(); 
            // ������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "������ �����! ����������, ������� ����� �����: ";
        }
        else 
        {
            // �������� ������ ��������
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
        std::cout << "\n--- ���� ---\n";
        std::cout << "1. �������� �������\n";
        std::cout << "2. ������� ������� �� �������\n";
        std::cout << "3. ������� ������� �� ��������\n";
        std::cout << "4. �������� ������� � ������\n";
        std::cout << "5. �������� ������� � �����\n";
        std::cout << "6. �������� ������� ����� �������\n";
        std::cout << "7. �������� ����� ��������\n";
        std::cout << "8. �������� ����� �������� (������� ����������)\n";
        std::cout << "9. ����������� ������\n";
        std::cout << "10. ������ �������\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";
        choice = GetValidatedInput();

        switch (choice) 
        {
        case 1:
            std::cout << "������� ������� ��� ����������: ";
            value = GetValidatedInput();
            arr.AddToEnd(value);
            break;
        case 2:
            std::cout << "������� ������ ��� ��������: ";
            index = GetValidatedInput();
            arr.RemoveAtIndex(index);
            break;
        case 3:
            std::cout << "������� �������� ��� ��������: ";
            value = GetValidatedInput();
            arr.RemoveValue(value);
            break;
        case 4:
            std::cout << "������� ������� ��� ������� � ������: ";
            value = GetValidatedInput();
            arr.InsertAtStart(value);
            break;
        case 5:
            std::cout << "������� ������� ��� ������� � �����: ";
            value = GetValidatedInput();
            arr.InsertAtEnd(value);
            break;
        case 6:
            std::cout << "������� ������ ��� �������: ";
            index = GetValidatedInput();
            std::cout << "������� ������� ��� �������: ";
            value = GetValidatedInput();
            arr.InsertAfterIndex(index, value);
            break;
        case 7:
            std::cout << "������� ������� ��� ������: ";
            value = GetValidatedInput();
            index = arr.LinearSearch(value);
            if (index != -1) {
                std::cout << "������� ������ �� �������: " << index << std::endl;
            }
            else {
                std::cout << "������� �� ������\n";
            }
            break;
        case 8:
            std::cout << "������� ������� ��� ��������� ������: ";
            value = GetValidatedInput();
            index = arr.BinarySearch(value);
            if (index != -1) {
                std::cout << "������� ������ �� �������: " << index << std::endl;
            }
            else {
                std::cout << "������� �� ������\n";
            }
            break;
        case 9:
            arr.CombSort();
            std::cout << "������ ������������ (���������� ���������).\n";
            break;
        case 10:
            arr.PrintElements();
            break;
        case 0:
            std::cout << "�����...\n";
            break;
        default:
            std::cout << "�������� �����! ���������� �����.\n";
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    Menu();
    return 0;
}
