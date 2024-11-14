#include "Book.h"

Book::Book(const char* auth, const char* titl, const char* publ, int yr, int pgs)
    : year(yr), pages(pgs) {
    copyString(author, auth, 50);
    copyString(title, titl, 50);
    copyString(publisher, publ, 50);
}

void Book::copyString(char* dest, const char* src, int maxLen) {
    int i = 0;
    for (; i < maxLen - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void Book::display() const {
    cout << "Author: " << author << ", Title: " << title
        << ", Publisher: " << publisher << ", Year: " << year
        << ", Pages: " << pages << endl;
}

const char* Book::getAuthor() const {
    return author;
}

const char* Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}