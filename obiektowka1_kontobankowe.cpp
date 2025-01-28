#include <iostream>
#include <string>

class BankAccount {
public:
    // Publiczne pola
    std::string numerKonta;
    double saldo;
    std::string wlasciciel;

    // Konstruktor klasy BankAccount
    BankAccount(std::string numerKonta, double saldo, std::string wlasciciel) {
        this->numerKonta = numerKonta;
        this->saldo = saldo;
        this->wlasciciel = wlasciciel;
    }

    // Metoda do wpłacania pieniędzy
    void wplac(double kwota) {
        if (kwota > 0) {
            saldo += kwota;
            std::cout << "Wplata " << kwota << " PLN zakonczona sukcesem.\n";
        } else {
            std::cout << "Kwota wplaty musi byc dodatnia.\n";
        }
    }

    // Metoda do wypłacania pieniędzy
    void wyplac(double kwota) {
        if (kwota > 0 && kwota <= saldo) {
            saldo -= kwota;
            std::cout << "Wypłata " << kwota << " PLN zakonczona sukcesem.\n";
        } else if (kwota > saldo) {
            std::cout << "Brak wystarczajacych srodkow na koncie.\n";
        } else {
            std::cout << "Kwota wypłaty musi byc dodatnia.\n";
        }
    }

    // Metoda do wyświetlania salda
    void wyswietlSaldo() {
        std::cout << "Stan konta: " << saldo << " PLN\n";
    }
};

int main() {
    // Tworzenie obiektu BankAccount
    BankAccount konto("123456789", 1000.0, "Jan Kowalski");

    // Wyświetlanie początkowego salda
    std::cout << "Wlasciciel: " << konto.wlasciciel << "\n";
    std::cout << "Numer konta: " << konto.numerKonta << "\n";
    konto.wyswietlSaldo();

    // Wpłata
    konto.wplac(500.0);
    konto.wyswietlSaldo();

    // Wypłata
    konto.wyplac(300.0);
    konto.wyswietlSaldo();

    // Próba wypłaty większej niż saldo
    konto.wyplac(1500.0);
    konto.wyswietlSaldo();

    return 0;
}
