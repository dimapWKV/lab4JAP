#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

// Прототипы
void processArray(); //Первое задание
void var13(); //Второе задание

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // var13();
    processArray();
    return 0;
}


vector<int> FillArrayVector(int size){
    std::vector<int> mass = {};

    for (int i = 0; i < size; i++)
    {
        std::cout << "Введите " << i << " элемент массива: ";
        int element;
        std::cin >> element;
        mass.push_back(element);
    }

    return mass;
}

void processArray() {
    int size;

    cout <<"Введите количество элементов:  ";
    cin >> size;

    vector<int> mass = FillArrayVector(size);

    cout << "Исходный массив: ";
    for (int num : mass) {
        cout << num << " ";
    }
    cout << endl;


    //Поиск максимального и минимального элемента
    int min_val = mass[0];
    int max_val = mass[0];
    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < mass.size(); i++) {
        // Поиск минимального элемента
        if (mass[i] < min_val) {
            min_val = mass[i];
            min_index = i;
        }
        // Поиск максимального элемента
        if (mass[i] > max_val) {
            max_val = mass[i];
            max_index = i;
        }
    }

    cout << "\n1. Максимальный элемент: " << max_val
              << " (индекс " << max_index << ")" << endl;
    cout << "   Минимальный элемент: " << min_val
              << " (индекс " << min_index << ")" << endl;

    //Перестановка местами максимального и минимального элемента
    int temp = mass[min_index];
    mass[min_index] = mass[max_index];
    mass[max_index] = temp;

    cout << "\n2. Массив после перестановки: ";
    for (int num : mass) {
        cout << num << " ";
    }
    cout << endl;

    //Поиск количества различных элементов и их частоты
    cout << "\n3. Количество различных элементов и их частота:" << endl;

    int different_count = 0;

    for (int i = 0; i < mass.size(); i++) {
        bool already_counted = false;

        // Проверяем, не встречался ли этот элемент раньше
        for (int j = 0; j < i; j++) {
            if (mass[i] == mass[j]) {
                already_counted = true;
                break;
            }
        }


        if (!already_counted) {
            int count = 1;
            // Считаем сколько раз он встречается во всем массиве
            for (int k = i + 1; k < mass.size(); k++) {
                if (mass[i] == mass[k]) {
                    count++;
                }
            }
            cout << "   " << mass[i] << " - " << count << endl;
            different_count++;
        }
    }
}


//Второе задание
double *FillArray(int size)
{
    double *data = new double[size];

    double element;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите " << i << " элемент массива";
        cin >> element;

        data[i] = element;
    }

    return data;
}

int CountElementsInRange(double *data, int size)
{
    int count = 0;
    for (int i = 0; i<size; i++)
    {
        if (data[i] >= -2 && data[i] <= 2)
            count++;
    }
    return count;
}

double SumElementAfterMax(double *data, int size)
{
    double maxelement = data[0], sumelements = 0;

    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (data[i] > maxelement)
        {
            maxelement = data[i];
            index = i;
        }
    }
    for (int i = index+1; i < size; i++)
    {
        sumelements += data[i];
    }
    return sumelements;
}

void ReversArray(double *data, int size)
{
    for (int i = 0; i < size / 2; i++) {
        int tmp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = tmp;
    }

    cout << "Обратный массив: ";
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
}

void var13() {
    int numbers;

    cout << "Введите количество элементов массива: ";
    cin >> numbers;
    cout << endl;

    double *data = FillArray(numbers);

    cout << "Количество элементов массива, лежащих в диапазоне [-2, 2]: " << CountElementsInRange(data, numbers) << endl;
    cout << "Сумма элементов массива, расположенных после максимального элемента: " << SumElementAfterMax(data, numbers) << endl;
    ReversArray(data, numbers);
    cout << endl;

    delete[] data;
}

