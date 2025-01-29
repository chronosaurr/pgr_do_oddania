#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
 
using namespace std;
 
void generujTablice(int* tablica, int rozmiar);
int partition(int* tablica, int low, int high);
void quicksort(int* tablica, int low, int high);
void zmierzCzas(void (*sortowanie)(int*, int, int), int* tablica, int rozmiar);
 
 
int main() {
    srand(time(NULL));
    int rozmiary[] = {100, 5000, 100000};
    for (int rozmiar : rozmiary) {
        int* tablica = new int[rozmiar];
        generujTablice(tablica, rozmiar);
        cout << "Test dla rozmiaru " << rozmiar << ":" << endl;
        zmierzCzas(quicksort, tablica, rozmiar);
        delete[] tablica;
    }
 
    return 0;
}
 
void generujTablice(int* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = rand() % 1000 + 1;
    }
}
 
int partition(int* tablica, int low, int high) {
    int pivot = tablica[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (tablica[j] <= pivot) {
            ++i;
            swap(tablica[i], tablica[j]);
        }
    }
    swap(tablica[i + 1], tablica[high]);
    return i + 1;
}
 
void quicksort(int* tablica, int low, int high) {
    if (low < high) {
        int pi = partition(tablica, low, high);
        quicksort(tablica, low, pi - 1);
        quicksort(tablica, pi + 1, high);
    }
}
 
void zmierzCzas(void (*sortowanie)(int*, int, int), int* tablica, int rozmiar) {
    DWORD start = GetTickCount();
    sortowanie(tablica, 0, rozmiar - 1);
    DWORD end = GetTickCount();
    cout << "Czas wykonania: " << end - start << " ms" << endl;
}
