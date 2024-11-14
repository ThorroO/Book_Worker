#pragma once
#ifndef WORKER_H
#define WORKER_H

#include <iostream>
using namespace std;

class Worker {
    char name[50];
    char position[50];
    int yearStarted;
    double salary;

    void copyString(char* dest, const char* src, int maxLen);

public:
    explicit Worker(const char* name, const char* position, int yearStarted, double salary);
    void display() const;
    const char* getPosition() const;
    int getYearsWorked(int currentYear) const;
    double getSalary() const;
};

#endif