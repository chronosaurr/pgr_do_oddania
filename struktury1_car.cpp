#include <iostream>
#include <string>
#include <limits>  // Dla std::numeric_limits

using namespace std;

// Definicja struktury Samochod
struct Samochod {
    string marka;
    string model;
    int rokProdukcji;
};

int main() {
    int n;  // Liczba samochodów
    cout << "Podaj liczbę samochodów (max 10): ";
    cin >> n;

    // Sprawdzenie, czy liczba samochodów nie przekracza 10
    if (n <= 0 || n > 10) {
        cout << "Liczba samochodów musi być w zakresie od 1 do 10!" << endl;
        return 1;  // Zakończenie programu z kodem błędu
    }

    Samochod samochody[n];

    // Wczytywanie danych o samochodach
    for (int i = 0; i < n; ++i) {
        cout << "\nSamochód " << i + 1 << ":\n";
        cout << "Podaj markę: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Czyszczenie bufora
        getline(cin, samochody[i].marka);

        cout << "Podaj model: ";
        getline(cin, samochody[i].model);

        cout << "Podaj rok produkcji: ";
        cin >> samochody[i].rokProdukcji;
    }

    // Wyświetlanie wprowadzonych samochodów
    cout << "\nWprowadzone samochody:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Marka: " << samochody[i].marka
             << ", Model: " << samochody[i].model
             << ", Rok produkcji: " << samochody[i].rokProdukcji << endl;
    }

    // Liczenie samochodów po roku 2000
    int liczbaPo2000 = 0;
    for (int i = 0; i < n; ++i) {
        if (samochody[i].rokProdukcji > 2000) {
            liczbaPo2000++;
        }
    }
    cout << "\nLiczba samochodów wyprodukowanych po roku 2000: " << liczbaPo2000 << endl;

    // Szukanie najstarszego samochodu
    int najstarszyIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (samochody[i].rokProdukcji < samochody[najstarszyIndex].rokProdukcji) {
            najstarszyIndex = i;
        }
    }
    cout << "\nNajstarszy samochód:\n";
    cout << "Marka: " << samochody[najstarszyIndex].marka
         << ", Model: " << samochody[najstarszyIndex].model
         << ", Rok produkcji: " << samochody[najstarszyIndex].rokProdukcji << endl;

    return 0;
}
