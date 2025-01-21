#include <string>
#include <iostream>

class book {
private:
    std::string title;
    std::string author;
    int published_in;

public:
    book(std::string tytuł, std::string autor, int rok_wydania): title(title), author(author), published_in(published_in) {}
    int dane_rok_wydania() const {
        return published_in;
    }
    std::string dane_autor() const {
        return author;
    }
    std::string dane_tytu() const {
        return title;
    }
    void wyswietl() {
        std::cout << "Title " << title << std::endl;
        std::cout << "Author " << author << std::endl;
        std::cout << "Published in " << published_in << std::endl;
        std::cout << std::endl;
    }
};
int main() {
    book book_1("Methamorphosis","Franz Kafka",1915);
    book book_2("Year 1984", "George Orwell", 1949);
    book book_3("The Plague", "Albert Camus", 1947);

    book_1.wyswietl();
    book_2.wyswietl();
    book_3.wyswietl();
    return 0;
}
