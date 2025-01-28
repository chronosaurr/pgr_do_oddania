#include <iostream>
#include <string>

using namespace std;

// Definicja klasy Samochod (Car)
class Car {
private:
    string marka;
    string model;
    float pojemnoscSilnika;
    string rodzajPaliwa;
    float predkosc;  // Dodałem pole prędkości

public:
    // Konstruktor klasy Car
    Car(string marka, string model, float pojemnoscSilnika, string rodzajPaliwa)
        : marka(marka), model(model), pojemnoscSilnika(pojemnoscSilnika), rodzajPaliwa(rodzajPaliwa), predkosc(0) {}

    // Metoda do wczytywania danych samochodu
    void create() {
        cout << "Podaj marke samochodu: ";
        cin.ignore();  // Usuwanie ewentualnych danych w buforze
        getline(cin, marka);

        cout << "Podaj model samochodu: ";
        getline(cin, model);

        cout << "Podaj pojemnosc silnika (w litrach): ";
        cin >> pojemnoscSilnika;

        cout << "Podaj rodzaj paliwa (np. benzyna, diesel, elektryczny): ";
        cin.ignore();  // Usuwanie ewentualnych danych w buforze
        getline(cin, rodzajPaliwa);
    }

    // Metoda do wyświetlania danych samochodu
    void show() const {
        cout << "\nInformacje o samochodzie:\n";
        cout << "Marka: " << marka << endl;
        cout << "Model: " << model << endl;
        cout << "Pojemność silnika: " << pojemnoscSilnika << " L" << endl;
        cout << "Rodzaj paliwa: " << rodzajPaliwa << endl;
        cout << "Aktualna prędkość: " << predkosc << " km/h\n";
    }

    // Metoda do zwiększania prędkości
    void zwiekszPredkosc(float wartosc) {
        if (wartosc > 0) {
            predkosc += wartosc;
            cout << "Prędkość została zwiększona o " << wartosc << " km/h. Nowa prędkość: " << predkosc << " km/h.\n";
        } else {
            cout << "Wartość do zwiększenia prędkości musi być dodatnia.\n";
        }
    }

    // Metoda do zmniejszania prędkości
    void zmniejszPredkosc(float wartosc) {
        if (wartosc > 0 && predkosc - wartosc >= 0) {
            predkosc -= wartosc;
            cout << "Prędkość została zmniejszona o " << wartosc << " km/h. Nowa prędkość: " << predkosc << " km/h.\n";
        } else if (wartosc > predkosc) {
            cout << "Nie możesz zmniejszyć prędkości o więcej niż aktualna prędkość.\n";
        } else {
            cout << "Wartość do zmniejszenia prędkości musi być dodatnia.\n";
        }
    }
};

int main() {
    // Tworzymy dwa obiekty samochodów
    Car skoda("Skoda", "Octavia", 1.6, "Benzyna");
    Car citroen("Citroen", "C4", 1.6, "Diesel");

    // Zmienna wyboru użytkownika
    int wybor;
    float wartoscPredkosci;

    // Menu do wyboru samochodu
    cout << "Wybierz samochod (1 - Skoda, 2 - Citroen): ";
    cin >> wybor;

    Car* wybranySamochod = nullptr;

    // Wybór samochodu
    if (wybor == 1) {
        wybranySamochod = &skoda;
    } else if (wybor == 2) {
        wybranySamochod = &citroen;
    } else {
        cout << "Nieprawidłowy wybór!" << endl;
        return 1;
    }

    // Wyświetlamy dane wybranego samochodu
    wybranySamochod->show();

    // Menu do zmiany prędkości
    while (true) {
        cout << "\nWybierz akcje: \n";
        cout << "1 - Zwieksz predkosc\n";
        cout << "2 - Zmniejsz predkosc\n";
        cout << "3 - Wyswietl dane samochodu\n";
        cout << "4 - Zakoncz\n";
        cout << "Twoj wybór: ";
        int akcja;
        cin >> akcja;

        switch (akcja) {
            case 1:
                cout << "O ile chcesz zwiekszyc predkosc? ";
                cin >> wartoscPredkosci;
                wybranySamochod->zwiekszPredkosc(wartoscPredkosci);
                break;
            case 2:
                cout << "O ile chcesz zmniejszyc predkosc? ";
                cin >> wartoscPredkosci;
                wybranySamochod->zmniejszPredkosc(wartoscPredkosci);
                break;
            case 3:
                wybranySamochod->show();
                break;
            case 4:
                cout << "Zakończenie programu.\n";
                return 0;
            default:
                cout << "Nieprawidłowa akcja. Spróbuj ponownie.\n";
        }
    }

    return 0;
}
