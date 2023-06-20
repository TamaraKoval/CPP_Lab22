#include "TomaString.h"
#include <iostream>

int TomaString::length() const {
    int i;
    for (i = 0; tomaString[i] != MARK; i++);
    return i;
}

void TomaString::append(char ch) {
    int length = this->length();
    if (length < N) {
        tomaString[length] = ch;
        tomaString[length + 1] = MARK;
    }
}

char & TomaString::operator[](unsigned index) {
    return tomaString[index];
}

TomaString & TomaString::operator=(const char *str) {
    int i;
    for (i = 0; str[i] && i < N - 1; i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    if (i < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

TomaString & TomaString::operator=(TomaString str) {
    int i;
    for (i = 0; str[i] != MARK; i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    if (i < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

bool TomaString::operator==(TomaString str) {
    int i;
    for (i = 0; tomaString[i] != MARK; i++) {
        if (tomaString[i] != str[i]) {
            return false;
        }
    }
    if (str[i] != MARK) {
        return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &stream, const TomaString &str) {
    int length = str.length();
    for (int i = 0; i < length; i++) {
        stream << str.tomaString[i];
    }
    return stream;
}

std::istream &operator>>(std::istream &stream, TomaString &str) {
    char buffer[200];
    stream >> buffer;
    str = buffer;
    return stream;
}
