#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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
    heapSort(arr, N);

    auto stop2 = chrono::high_resolution_clock::now();
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration<float>(stop1 - start1);
    auto duration2 = chrono::duration<float>(stop2 - start2);
    cout << "Tiempo de ejecucion: " << duration1.count() << " s" << endl;
    cout << "Tiempo de ordenamiento: " << duration2.count() << " s" << endl;
}