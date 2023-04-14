﻿#include <string>
#include <iostream>
#include <vector>
#include <ctime>

enum class BookType { Art, Technical };

class Book {
public:

    Book(const std::string& _authorName, const std::string& _bookTitle, BookType _bookType) :
        authorName(_authorName),
        bookTitle(_bookTitle),
        bookType(_bookType) {}

    BookType GetBookType()const {
        return bookType;
    }

private:
    const std::string authorName;
    const std::string bookTitle;
    const BookType bookType;
};

class LibraryBook {
public:

    ~LibraryBook() {
        for (int i = 0; i < size(lib); ++i) {
            delete lib[i];
        }
    }
    void addBook(const std::string& author, const std::string& bookName, BookType bookType) {
        if ((author == "") || (bookName == "")) {
            std::cout << "Book name or author was not found\n";
        }
        else {
            lib.push_back(new Book(author, bookName, bookType));
        }
    }

    void CounterTypeWithSwitch() {
        int artBook = 0;
        int techBook = 0;

        for (const Book* book : lib) {
            switch (book->GetBookType()) {
            case BookType::Art:
                ++artBook;
                break;
            case BookType::Technical:
                ++techBook;
                break;
            }
        }
        std::cout << "Art book: " << artBook << '\n';
        std::cout << "Technical book: " << techBook << '\n';
    }

    void CounterTypeWithIf() {
        int artBook = 0;
        int techBook = 0;
        for (const Book* book : lib) {
            if (book->GetBookType() == BookType::Art) {
                ++artBook;
            }
            else {
                ++techBook;
            }
        }

        std::cout << "Art book: " << artBook << '\n';
        std::cout << "Technical book: " << techBook << '\n';
    }

private:
    std::vector<Book*> lib;
};

int main()
{
    LibraryBook libBook;

    libBook.addBook("Help", "Beaver", BookType::Art);
    libBook.addBook("Barbecue", "love donuts", BookType::Technical);

    std::cout << "With switch\n";
    libBook.CounterTypeWithSwitch();
    std::cout << "******************\n";
    std::cout << "With if\n";
    libBook.CounterTypeWithIf();
}