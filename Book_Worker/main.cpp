#include <iostream>

bool safeStrcmp(const char* str1, const char* str2, size_t maxLength) {
    size_t i = 0;
    while (i < maxLength && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        ++i;
    }
    return i == maxLength || (str1[i] == '\0' && str2[i] == '\0');
}

#include "Book.h"
#include "Worker.h"

void findBooksByAuthor(const Book books[], int size, const char* author);
void findBooksByPublisher(const Book books[], int size, const char* publisher);
void findBooksAfterYear(const Book books[], int size, int year);
void findWorkersByExperience(const Worker workers[], int size, int minYears, int currentYear);
void findWorkersBySalary(const Worker workers[], int size, double minSalary);
void findWorkersByPosition(const Worker workers[], int size, const char* position);

int main() {
    Book books[] = {
        Book("Author1", "Title1", "Publisher1", 2001, 300),
        Book("Author2", "Title2", "Publisher2", 2005, 400),
        Book("Author1", "Title3", "Publisher1", 2010, 250)
    };
    int bookCount = sizeof(books) / sizeof(books[0]);

    Worker workers[] = {
        Worker("John Doe", "Engineer", 2010, 55000),
        Worker("Jane Smith", "Manager", 2008, 75000),
        Worker("Alice Brown", "Engineer", 2015, 60000)
    };
    int workerCount = sizeof(workers) / sizeof(workers[0]);
    int currentYear = 2024;

    std::cout << "Books by Author1:\n";
    findBooksByAuthor(books, bookCount, "Author1");

    std::cout << "\nBooks by Publisher1:\n";
    findBooksByPublisher(books, bookCount, "Publisher1");

    std::cout << "\nBooks published after 2005:\n";
    findBooksAfterYear(books, bookCount, 2005);

    std::cout << "\nWorkers with over 10 years of experience:\n";
    findWorkersByExperience(workers, workerCount, 10, currentYear);

    std::cout << "\nWorkers with salary above 60000:\n";
    findWorkersBySalary(workers, workerCount, 60000);

    std::cout << "\nWorkers with position 'Engineer':\n";
    findWorkersByPosition(workers, workerCount, "Engineer");

    return 0;
}

void findBooksByAuthor(const Book books[], int size, const char* author) {
    for (int i = 0; i < size; ++i) {
        if (safeStrcmp(books[i].getAuthor(), author, 100)) {
            books[i].display();
        }
    }
}

void findBooksByPublisher(const Book books[], int size, const char* publisher) {
    for (int i = 0; i < size; ++i) {
        if (safeStrcmp(books[i].getPublisher(), publisher, 100)) {
            books[i].display();
        }
    }
}

void findBooksAfterYear(const Book books[], int size, int year) {
    for (int i = 0; i < size; ++i) {
        if (books[i].getYear() > year) {
            books[i].display();
        }
    }
}

void findWorkersByExperience(const Worker workers[], int size, int minYears, int currentYear) {
    for (int i = 0; i < size; ++i) {
        if (workers[i].getYearsWorked(currentYear) > minYears) {
            workers[i].display();
        }
    }
}

void findWorkersBySalary(const Worker workers[], int size, double minSalary) {
    for (int i = 0; i < size; ++i) {
        if (workers[i].getSalary() > minSalary) {
            workers[i].display();
        }
    }
}

void findWorkersByPosition(const Worker workers[], int size, const char* position) {
    for (int i = 0; i < size; ++i) {
        if (safeStrcmp(workers[i].getPosition(), position, 100)) {
            workers[i].display();
        }
    }
}