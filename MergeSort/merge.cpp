#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // arreglos temporales
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main(int argc, char *argv[])
{
    // empieza tiempo de ejecución
    auto start1 = chrono::high_resolution_clock::now();

    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " <tamaño del arreglo>" << endl;
        return 1;
    }

    // llenar arreglo de números aleatorios
    int N = atoi(argv[1]);
    srand(time(0));
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;
    }

    auto start2 = chrono::high_resolution_clock::now();
    // ordenar el arreglo
    mergeSort(arr, 0, N - 1);

    auto stop2 = chrono::high_resolution_clock::now();
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration<float>(stop1 - start1);
    auto duration2 = chrono::duration<float>(stop2 - start2);
    cout << "Tiempo de ejecucion: " << duration1.count() << " s" << endl;
    cout << "Tiempo de ordenamiento: " << duration2.count() << " s" << endl;
}