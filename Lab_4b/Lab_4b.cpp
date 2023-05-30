#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

struct Structur {
    std::string author;
    std::string title;
    std::string year;
    std::string pages;
};

bool Rus(char ch) {

    if (ch >= 0 && ch <= 127) {
        return false;
    }
    return true;
}

void printStructur(const std::vector<Structur>& Structur, bool withNumbers) {
    for (size_t i = 0; i < Structur.size(); i++) {
        if (withNumbers) {
            std::cout << i + 1 << ". ";
        }
        std::cout << Structur[i].author << " " << Structur[i].year << ". " << Structur[i].title << " " << Structur[i].pages << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector <Structur> structur;
    std::ifstream file("4b.txt");
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string author, title, year, pages;
        std::istringstream iss(line);
        std::getline(iss, author, ',');
        std::getline(iss, year, ',');
        std::getline(iss, title, ',');
        iss >> pages;
        Structur ref = { author, title, year, pages };
        structur.push_back(ref);
    }
    file.close();


    sort(structur.begin(), structur.end(), [](const Structur& a, const Structur& b) {

        if (Rus(a.author[0]) && !Rus(b.author[0])) {
            return true;
        }
        else if (!Rus(a.author[0]) && Rus(b.author[0])) {
            return false;
        }
        else {
            return a.author < b.author;
        }
        });

    std::cout << "Пронумерованный список литературы:" << std::endl;
    printStructur(structur, true);

    std::cout << std::endl << "Непронумерованный список литературы:" << std::endl;
    printStructur(structur, false);
}