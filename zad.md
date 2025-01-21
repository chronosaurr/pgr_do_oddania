## Struktury
#### Zad 1
Napisz program, który będzie przechowywał informacje o ocenach studentów z jednej grupy z przedmiotu PRG. 
Każdy student ma predefiniowane imię i nazwisko oraz swój numer indeksu. 
Program powinien zapytać użytkownika po kolei o ocenę każdego studenta, 
a następnie wydrukować zestawienie wszystkich ocen w formacie nr_indeksu: ocena s14616: 2.0 s2137: 3.5 
Oraz średnią wszystkich ocen za przedmiot. Studentów jest 10;

#### Zad 2
Zdefiniuj strukturę Samochod, zawierającą pola:

marka (łańcuch znaków),
model (łańcuch znaków),
rokProdukcji (liczba całkowita). Następnie program powinien:
Wczytać liczbę samochodów n (np. do 10).
Wczytać dane o każdym samochodzie do tablicy struktur.
Wyświetlić wszystkie wprowadzone samochody.
Policzyć, ile samochodów zostało wyprodukowanych po roku 2000 i wyświetlić tę liczbę.
Znaleźć najstarszy samochód (z najmniejszym rokProdukcji) i wypisać jego markę i model.


## Obiektowosc 1
#### Zad 1
Napisz klasę samochód, która zawierać będzie pola: marka, model, pojemność silnika, rodzaj paliwa oraz metody:
create() – która zapyta użytkownika o wszystkie dane pojazdu
show() – która wyświetli wszystkie te informacje. W funkcji main powinniśmy jedynie tworzyć obiekt klasy samochód i wywoływać obie metody.

#### Zad 2
Napisz klasę rectangle, która będzie miała pola a i b oraz metody pozwalające na obliczanie pola i przekątnej tego prostokąta. 
W funkcji main stwórz nowy obiekt, poproś użytkownika o podanie a i b, a następnie wywołaj obie metody i wynik obliczeń wydrukuj na terminalu.

#### Zad 3
Konto Bankowe: Zdefiniuj klasę BankAccount reprezentującą konto bankowe. Dodaj publiczne pola dla numeru konta, 
salda i właściciela. Utwórz metody do wpłacania, wypłacania i wyświetlania salda.

## Obiektowosc 2
#### Zad 1
Zadanie z konstruktorem i hermetyzacją - Książka:
Stwórz klasę Book, reprezentującą książkę. Klasa powinna mieć prywatne pola, takie jak tytuł, autor i rok wydania.
Zaimplementuj konstruktor, który umożliwi ustawienie wartości początkowych dla pól klasy.
Utwórz metody dostępowe, aby uzyskiwać informacje o książce.
Przetestuj działanie klasy, tworząc kilka obiektów reprezentujących różne książki.

#### Zad 2
Rozszerz przykład z labu z samochodem:
Utwórz metody w klasie Car pozwalające na zwiększanie i zmniejszanie prędkości
Utwórz dwa obiekty klasy Car, Skodę i Citroena
Program powinien pozwolić użytkownikowi przy użīciu terminala na wybór jakiegoś samochodu i zwiększenie lub zmniejszenie jego prędkości oraz wydrukować prędkość danego samochodu po zmianie jej wartości
