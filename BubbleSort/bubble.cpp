#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int main (int argc, char* argv[]){
    // empieza tiempo de ejecución
    auto start1 = chrono::high_resolution_clock::now();

    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <tamaño del arreglo>" << endl;
        return 1;
    }

    // llenar arreglo de números aleatorios
    int N = atoi(argv[1]);
    srand(time(0));
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100;  
    }

    auto start2 = chrono::high_resolution_clock::now();
    // ordenar el arreglo
    int i, j;
    bool swapped;
    for (i = 0; i < N - 1; i++) {
        swapped = false;
        for (j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    auto stop2 = chrono::high_resolution_clock::now();

    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration<float>(stop1 - start1);
    auto duration2 = chrono::duration<float>(stop2 - start2);
    cout << "Tiempo de ejecucion: " << duration1.count() << " s" << endl;
    cout << "Tiempo de ordenamiento: " << duration2.count() << " s" << endl;
}