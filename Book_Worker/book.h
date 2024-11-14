#pragma once
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book {
    char author[50];
    char title[50];
    char publisher[50];
    int year;
    int pages;

    void copyString(char* dest, const char* src, int maxLen);

public:
    explicit Book(const char* author, const char* title, const char* publisher, int year, int pages);
    void display() const;
    const char* getAuthor() const;
    const char* getPublisher() const;
    int getYear() const;
};

#endif