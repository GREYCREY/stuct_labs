#include <iostream>
using namespace std;

const int PeopleCount = 4;

struct Person {
    string firstName;
    string lastName;
    int age;
};

Person** CreatePeopleArray() {
    Person** people = new Person * [PeopleCount];

    people[0] = new Person{ "Casey", "Aguilar", 30 };
    people[1] = new Person{ "Brock", "Curtis", 19 };
    people[2] = new Person{ "Blake", "Diaz", 21 };
    people[3] = new Person{ "Cristian", "Evans", 55 };

    return people;
}

void WritePerson(Person* person) {
    cout << "First Name: " << person->firstName
        << "; Last Name: " << person->lastName
        << "; Age: " << person->age
        << endl;
}

void ClearPeople(Person** people, int count) {
    for (int i = 0; i < count; i++) {
        delete people[i];
    }
    delete[] people;
}

void Task1_FindPersonByLastName() {
    Person** people = CreatePeopleArray();

    for (int i = 0; i < PeopleCount; i++) {
        WritePerson(people[i]);
    }

    string lastName;
    cout << "Enter last name: ";
    cin >> lastName;

    int foundIndex = -1;

    for (int i = 0; i < PeopleCount; i++) {
        if (people[i]->lastName == lastName) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "Could not find a person by last name: " << lastName << endl;
    }
    else {
        cout << "A person's last name " << lastName
            << " was found. Its index in the array is "
            << foundIndex << endl;
    }

    ClearPeople(people, PeopleCount);
}

double GetPower(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); i++) {
        result *= base;
    }
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

void DemoGetPower(double base, int exponent) {
    double result = GetPower(base, exponent);
    cout << base << " ^ " << exponent << " = " << result << endl;
}

void RoundToTens(int& value) {
    int remainder = value % 10;
    if (remainder < 5) {
        value = (value / 10) * 10;
    }
    else {
        value = ((value / 10) + 1) * 10;
    }
}

void BubbleSort(double* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[12] = { 1, 20, -40, 10, 15, 9, 2, 90, -100, 7, 0, 2 };
    cout << "Source array is:" << endl;
    for (int i = 0; i < 12; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array is:" << endl;
    for (int i = 0; i < 12; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Power calculations:" << endl;
    DemoGetPower(2.0, 5);
    DemoGetPower(3.0, 4);
    DemoGetPower(-2.0, 5);
    DemoGetPower(2.0, -2);

    cout << "\nRounding to tens:" << endl;
    int a = 14;
    cout << "For " << a << " rounded value is ";
    RoundToTens(a);
    cout << a << endl;

    a = 191;
    cout << "For " << a << " rounded value is ";
    RoundToTens(a);
    cout << a << endl;

    a = 27;
    cout << "For " << a << " rounded value is ";
    RoundToTens(a);
    cout << a << endl;

    int size = 8;
    double* d_arr = new double[size];
    d_arr[0] = 1.0;
    d_arr[1] = 15.0;
    d_arr[2] = -8.2;
    d_arr[3] = -3.5;
    d_arr[4] = 12.6;
    d_arr[5] = 38.4;
    d_arr[6] = -0.5;
    d_arr[7] = 4.5;

    cout << "Array of double:" << endl;
    for (int i = 0; i < size; i++) {
        cout << d_arr[i] << " ";
    }
    cout << endl;

    delete[] d_arr;

    int sizee = 10;
    double* arr = new double[sizee];

    arr[0] = 1.0;
    arr[1] = 15.0;
    arr[2] = -8.2;
    arr[3] = -3.5;
    arr[4] = 12.6;
    arr[5] = 38.4;
    arr[6] = -0.5;
    arr[7] = 4.5;
    arr[8] = 16.7;
    arr[9] = 4.5;

    cout << "Array of double:" << endl;
    for (int i = 0; i < sizee; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(arr, sizee);

    cout << "Sorted array of double:" << endl;
    for (int i = 0; i < sizee; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    Task1_FindPersonByLastName();

    return 0;
}
