#include "Worker.h"

Worker::Worker(const char* nm, const char* pos, int yrStarted, double sal)
    : yearStarted(yrStarted), salary(sal) {
    copyString(name, nm, 50);
    copyString(position, pos, 50);
}

void Worker::copyString(char* dest, const char* src, int maxLen) {
    int i = 0;
    for (; i < maxLen - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void Worker::display() const {
    cout << "Name: " << name << ", Position: " << position
        << ", Year Started: " << yearStarted << ", Salary: " << salary << endl;
}

const char* Worker::getPosition() const {
    return position;
}

int Worker::getYearsWorked(int currentYear) const {
    return currentYear - yearStarted;
}

double Worker::getSalary() const {
    return salary;
}