#include "HashTable.h"
#include "Dictionary.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Функция нужна для проверки введенного значения пользователем
/// </summary>
/// <returns>Введеное значение пользователем.</returns>
int CheckValue()
{
    cout << "Enter a number: ";

    string input;
    while (true)
    {
        if (cin >> input)
        {
            try
            {
                size_t pos;
                int value = stoi(input, &pos);
                if (pos == input.length())
                {
                    return value;
                }
                else
                {
                    cout << "Invalid input (non-integer characters found). Try again: ";
                }
            }
            catch (const invalid_argument& e)
            {
                cout << "Invalid input (not a number). Try again: ";
            }
            catch (const out_of_range& e)
            {
                cout << "Input out of range. Try again: ";
            }
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Input error. Try again: ";
        }
    }
}

void DictionaryWrapper::PrintState() const
{
    cout << "Buckets and key-value pairs:" << endl;
    for (size_t i = 0; i < _dictionary->GetSize(); ++i)
    {
        cout << i << ": ";
        Node* current = _dictionary->GetBucket(i);
        if (current == nullptr)
        {
            cout << "Empty";
        }
        else
        {
            while (current)
            {
                cout << "[" << current->key << ": " << current->value << "]";
                if (current->next)
                    cout << " -> ";
                current = current->next;
            }
        }
        cout << endl;
    }

    cout << "Key-value pairs (flat list):" << endl;
    for (size_t i = 0; i < _dictionary->GetSize(); ++i)
    {
        Node* current = _dictionary->GetBucket(i);
        while (current)
        {
            cout << current->key << ": " << current->value << endl;
            current = current->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "English");
    DictionaryWrapper* dict = new DictionaryWrapper();

    int choice;
    string key, value;

    do
    {
        cout << endl << "Menu" << endl;
        cout << "1. Add key-value pair" << endl;
        cout << "2. Remove key-value pair" << endl;
        cout << "3. Find a value by key" << endl;
        cout << "4. Add key-value pair (force rehash)" << endl;
        cout << "5. Auto-populate dictionary" << endl;
        cout << "0. Exit" << endl;
        dict->PrintState();

        cout << "Choose an option: ";

        choice = CheckValue();
        switch (choice)
        {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            dict->Add(key, value);
            break;

        case 2:
            cout << "Enter the key to remove: ";
            cin >> key;
            dict->Remove(key);
            break;

        case 3:
            cout << "Enter the key to find: ";
            cin >> key;
            value = dict->Find(key);
            if (!value.empty())
                cout << "Value found: " << value << endl;
            else
                cout << "Value not found." << endl;
            break;

        case 4:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            dict->Add(key, value);
            break;

        case 5:
            cout << "Populating the dictionary with test data..." << endl;
            for (int i = 0; i < 20; ++i)
            {
                dict->Add("Key" + to_string(i), "Value" + to_string(i));
            }
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    delete dict;
    return 0;
}
