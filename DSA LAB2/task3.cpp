#include <iostream>
using namespace std;


class Publication {
public:
    virtual void display() = 0;
};


class Book : public Publication {
private:
    string title;
    string author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() {
        cout << "Book Title: " << title
            << ", Author: " << author
            << ", Pages: " << pages << endl;
    }
};


class Newspaper : public Publication {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() {
        cout << "Newspaper Name: " << name
            << ", Date: " << date
            << ", Edition: " << edition << endl;
    }
};


class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newspaperCount = 0;

public:

    void addBook(Book b) {
        books[bookCount] = b;
        bookCount++;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newspaperCount] = n;
        newspaperCount++;
    }

    void displayCollection() {

        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    
    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    
    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    
    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return NULL;
    }

    
    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newspaperCount; i++) {
            if (newspapers[i].getName() == name) {
                return &newspapers[i];
            }
        }
        return NULL;
    }
};


int main() {

    
    Book book1("The kite", "J.D", 277);
    Book book2("To Kill ", "Law", 324);

    
    Newspaper newspaper1("GEO", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("Express", "2024-10-12", "Evening Edition");

    
    Library library;

    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    
    Book* foundBook = library.searchBookByTitle("The kite");

    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    
    Newspaper* foundNewspaper = library.searchNewspaperByName("GEO");

    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}