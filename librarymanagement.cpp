#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
    }

    void issueBook(int id) {
        for (auto &b : books) {
            if (b.id == id && !b.isIssued) {
                b.isIssued = true;
                return;
            }
        }
    }

    void returnBook(int id) {
        for (auto &b : books) {
            if (b.id == id && b.isIssued) {
                b.isIssued = false;
                return;
            }
        }
    }

    void searchByTitle(string title) {
        for (auto &b : books) {
            if (b.title == title) {
                cout << b.id << " " << b.title << " " << b.author << endl;
            }
        }
    }

    void searchByAuthor(string author) {
        for (auto &b : books) {
            if (b.author == author) {
                cout << b.id << " " << b.title << " " << b.author << endl;
            }
        }
    }
};

int main() {
    Library lib;
    lib.addBook(1, "C++", "Bjarne");
    lib.addBook(2, "Java", "James");

    lib.issueBook(1);
    lib.returnBook(1);

    lib.searchByTitle("C++");
    lib.searchByAuthor("James");

    return 0;
}
