#include "HashTable.h"
#include "Dictionary.h"
#include <iostream>
#include <string>

using namespace std;

// TODO: Полетела кодировка (см. все файлы)
// TODO: Добавить файл .gitignore и убрать лишние файлы из версионного контроля git

/// <summary>
/// ������� ��� �������� ����� ������ ����� �������������.
/// ������� ����������� � ������������ ���� ������ ����� � ���������� ������ �� ��� ���,
/// ���� �� ����� ������� ���������� ��������.
/// </summary>
/// <returns>��������� ������������� ����� �����.</returns>
int CheckValue()
{
    cout << "��� ����: ";

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
                    cout << "������� �������� �������� (���������� �������). ��������� ����: ";
                }
            }
            catch (const invalid_argument& e)
            {
                cout << "������� �������� �������� (�� �����). ��������� ����: ";
            }
            catch (const out_of_range& e)
            {
                cout << "������� ������� ������� ��������. ��������� ����: ";
            }
        }
        else
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "������ �����. ��������� ����: ";
        }
    }
}

void DictionaryWrapper::PrintState() const
{
    cout << "������� ��������� ���-�������:" << endl;
    for (size_t i = 0; i < _dictionary.GetSize(); ++i)
    {
        cout << i << ": ";
        Node* current = _dictionary.GetBucket(i);
        if (current == nullptr)
        {
            cout << "�����";
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

    cout << "������� (����� � ��������):" << endl;
    for (size_t i = 0; i < _dictionary.GetSize(); ++i)
    {
        Node* current = _dictionary.GetBucket(i);
        while (current)
        {
            cout << current->key << ": " << current->value << endl;
            current = current->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    DictionaryWrapper* dict = new DictionaryWrapper();

    int choice;
    string key, value;

    do
    {
        cout << endl << "����" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. ������� �������" << endl;
        cout << "3. ����� �������" << endl;
        cout << "4. �������� ������������� ����" << endl;
        cout << "5. ��������� �� ���������������" << endl;
        cout << "0. �����" << endl;
        dict->PrintState();

        cout << "�������� ��������: ";

        choice = CheckValue();
        switch (choice)
        {
        case 1:
            cout << "������� ����: ";
            cin >> key;
            cout << "������� ��������: ";
            cin >> value;
            dict->Add(key, value);
            break;

        case 2:
            cout << "������� ���� ��� ��������: ";
            cin >> key;
            dict->Remove(key);
            break;

        case 3:
            cout << "������� ���� ��� ������: ";
            cin >> key;
            value = dict->Find(key);
            if (!value.empty())
                cout << "������� ��������: " << value << endl;
            else
                cout << "������� �� ������." << endl;
            break;

        case 4:
            cout << "������� ������������� ����: ";
            cin >> key;
            cout << "������� ��������: ";
            cin >> value;
            dict->Add(key, value);
            break;

        case 5:
            cout << "���������� �� ������ ���������������..." << endl;
            for (int i = 0; i < 20; ++i)
            {
                dict->Add("Key" + to_string(i), "Value" + to_string(i));
            }
            break;

        case 0:
            cout << "�����..." << endl;
            break;

        default:
            cout << "�������� �����." << endl;
        }
    } while (choice != 0);

    delete dict;
    return 0;
}
