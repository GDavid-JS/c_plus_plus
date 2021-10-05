#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

ifstream inf("matrix.txt");
ofstream outf("matrix.txt", ios::app);

// Проверяем на наличие ошибок
void checkFileError()
{
    if (!inf || !outf)
    {
        cerr << "Error" << endl;
        exit(1);
    }
}

// Выводим массив
void outArr(int** arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}

// Заполняем массив
void fillArr(int** arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            inf >> arr[i][j];
        }
    }
}

// Первая задача
void firstTask(int** arr, int N)
{
    int* Arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        Arr[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if (arr[i][k] < 0)
            {
                Arr[i] = i;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int z = 1;
        if (Arr[i] == -1)
        {
            for (int k = 0; k < N; k++)
            {
                z *= arr[i][k];
            }
        }

        if (Arr[i] != -1)
        {
            //cout << "\nВ строке (" << i << ") содержится отрицательный элемент!";
            outf << "\nВ строке (" << i << ") содержится отрицательный элемент!";
        }
        else {
            //cout << "\nПроизведение элементов (" << i << ") строки: " << z;
            outf << "\nПроизведение элементов (" << i << ") строки: " << z;
        }
    }

    delete[] Arr;
}

// Вторая задача
void secondTask(int** arr, int N)
{
    int T = 2 * N;
    int* Arr1 = new int[T];
    for (int i = 0; i < N; i++)
    {
        int u = 0;
        for (int k = 0; k < N; k++)
        {
            int z = i + k;
            if (z < N)
            {
                u += arr[k][z];
            }
        }
        Arr1[i] = u;
    }

    for (int i = 0; i < N; i++)
    {
        int u = 0;

        for (int k = 0; k < N; k++)
        {
            int z = k - i;
            if (z >= 0)
            {
                u += arr[k][z];
            }
        }
        Arr1[N + i] = u;

    }


    // Находим максимум среди массмва Arr1
    int max = Arr1[0];
    for (int i = 0; i < 2 * N; i++) {
        if (Arr1[i] > max) {
            max = Arr1[i];
        }
    }

    outf << "\nМаксимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы: " << max;
    //cout << "\nМаксимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы: " << max;
    delete[] Arr1;
}

// Удаляем массив
void deleteArr(int** arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}


int main()
{
    setlocale(LC_ALL, "rus");

    // Проверяем на наличие ошибок
    checkFileError();

    int N;
    inf >> N;
    // Инициализируем массив
    int** Array = new int* [N];
    for (int i = 0; i < N; i++)
    {
        Array[i] = new int[N];
    }


    // Заполнение массива
    fillArr(Array, N);
    // Вывод массива
    outArr(Array, N);
    // Первая задача
    firstTask(Array, N);
    // Вторая задача
    secondTask(Array, N);
    // Удаляем массив
    deleteArr(Array, N);

    cout << endl;
    return 0;
}