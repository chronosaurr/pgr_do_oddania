#include <iostream>
#include <vector>
#include <iomanip> // Do formatowania wyników

struct Student {
    std::string first_name;
    std::string last_name;
    std::string index_number;
    float grade;
};

int main() {
    // Predefiniowana lista studentów
    std::vector<Student> studenci = {
        {"Jan", "Kowalski", "s14616", 0.0},
        {"Anna", "Nowak", "s2137", 0.0},
        {"Piotr", "Zielinski", "s15987", 0.0},
        {"Kasia", "Wiśniewska", "s17543", 0.0},
        {"Tomasz", "Mazur", "s18321", 0.0},
        {"Ewa", "Kaczmarek", "s19001", 0.0},
        {"Adam", "Szulc", "s19234", 0.0},
        {"Maria", "Wójcik", "s20045", 0.0},
        {"Karol", "Lewandowski", "s20456", 0.0},
        {"Magdalena", "Pawlak", "s20789", 0.0}
    };

    std::cout << "Add the final grades for every student. Grades should range from 2.0 to 5.0. " << std::endl;

    // Wprowadzanie ocen
    for (auto& student : studenci) {
        float ocena;
        while (true) {
            std::cout << "Add the final grade for " << student.first_name << " " << student.last_name
                      << " (" << student.index_number << "): ";
            std::cin >> ocena;

            // Sprawdzenie poprawności wprowadzonej oceny
            if (ocena >= 2.0 && ocena <= 5.0) {
                student.grade = ocena;
                break;
            } else {
                std::cout << "Incorrect input. Grades must range from 2.0 to 5.0." << std::endl;
            }
        }
    }

    // Wyświetlenie ocen
    std::cout << "\nFinal grades for the group:" << std::endl;
    float suma_ocen = 0.0;

    for (const auto& student : studenci) {
        std::cout << student.index_number << ": " << student.grade << std::endl;
        suma_ocen += student.grade;
    }

    // Wyświetlenie średniej ocen
    float srednia = suma_ocen / studenci.size();
    std::cout << "\nAverage grade: " << std::fixed << std::setprecision(2) << srednia << std::endl;

    return 0;
}
