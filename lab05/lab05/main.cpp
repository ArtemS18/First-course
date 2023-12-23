#include "func.h"
using namespace std;

int main()
{
    system("chcp 1251 > nul");
    srand(time(0));
    
    int n = 0, per = 0;
    int lenArr0 = 5,lenArr1 = 10, lenArr2 = 100, lenArr3 = 1000;

    int arr0[5] = { 7, 4, 8, 5, 8 };int copyArr0[5] = { 7, 4, 8, 5, 8 };
    int arr1[10] = { 5, 4, 3, 2, 1, 9, 0, 10, 11, 0 }; int copyArr1[10] = { 5, 4, 3, 2, 1, 9, 0, 10, 11, 0 };

    Arry Arr2 { new int[lenArr2] , new int[lenArr2]};
    Arry Arr3 { new int[lenArr3], new int[lenArr3]};

    random_val(Arr2, 0, 200, lenArr2);
    random_val(Arr3, 0, 200, lenArr3);

    cout << "Исходный массив: ";
    printArr(arr0, lenArr0);
    cout << "\n";

    bouble(arr0, lenArr0, n, per);
    cout << "Сортировка пузырьком по возраст. для массива длиной: " << lenArr0 << endl << "Кол-во сравнений: " << n << " Кол-во перестановок:" << per << "\n\n";
    selection(copyArr0, lenArr0, n, per);
    cout << "Выборная сортировка по возраст. для массива длиной: " << lenArr0 << endl << "Кол-во сравнений: " << n << " Кол-во перестановок:" << per << "\n\n";
    cout << "Исходный массив: ";
    printArr(arr0, lenArr0);
    cout << "\n";

    bouble(arr0, lenArr0, n, per);
    cout << "Сортировка пузырьком по возраст. для массива длиной: " << lenArr0 << endl << "Кол-во сравнений: " << n << " Кол-во перестановок:" << per << "\n\n";
    selection(copyArr0, lenArr0, n, per);
    cout << "Выборная сортировка по возраст. для массива длиной: " << lenArr0 << endl << "Кол-во сравнений: " << n << " Кол-во перестановок:" << per << "\n\n";

    cout << "Исходный массив: ";
    printArr(arr0, lenArr0);
    cout << "\n";
    rev_bouble(arr0, lenArr0, n, per);
    cout << "Сортировка пузырьком по убыв. для массива длиной: " << lenArr0 << endl << "Кол-во сравнений: " << n << " Кол-во перестановок:" << per << "\n\n";
    rev_selection(copyArr0, lenArr0, n, per);
    cout << "Выборная сортировка по убыв. для массива длиной: " << lenArr0 << endl << "Кол-во сравнений: " << n << " Кол-во перестановок:" << per << "\n\n";

    cout << "Arr1: ";
    printArr(arr1, lenArr1);
    cout << "\n";

    cout << "Arr2: ";
    printArr(Arr2.copy1, lenArr2);
    cout << "\n";

    cout << "Arr3: ";
    printArr(Arr3.copy1, lenArr3);
    cout << "\n";


     cout << setw(20) << "Имя массива" << setw(20) << "Тип сортировки" << setw(20) << "Длина массива" << setw(20) << "Кол-во сравнений" << setw(20) << "Кол-во перестановок" << endl;

     char tapeSelect[] = "Select"; char tapeBouble[] = "Bouble";
     char nameArr1[] = "Arr1"; char nameArr2[] = "Arr2"; char nameArr3[] = "Arr3";

     selection(arr1, lenArr1, n, per);
     printRow(nameArr1, tapeSelect, lenArr1, n, per);
     bouble(copyArr1, lenArr1, n, per);
     printRow(nameArr1, tapeBouble, lenArr1, n, per);

     selection(Arr2.copy1, lenArr2, n, per);
     printRow(nameArr2, tapeSelect, lenArr2, n, per);
     bouble(Arr2.copy2, lenArr2, n, per);
     printRow(nameArr2, tapeBouble, lenArr2, n, per);

     delete[] Arr2.copy1;
     delete[] Arr2.copy2;

     selection(Arr3.copy1, lenArr3, n, per);
     printRow(nameArr3, tapeSelect, lenArr3, n, per);
     bouble(Arr3.copy2, lenArr3, n, per);
     printRow(nameArr3, tapeBouble, lenArr3, n, per);

     delete[] Arr3.copy1;
     delete[] Arr3.copy2;
}

