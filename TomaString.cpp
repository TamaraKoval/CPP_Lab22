#include "TomaString.h"
#include <iostream>

int TomaString::length() {
    return curMarkPos;
}

void TomaString::append(char ch) {
    curMarkPos++;
    tomaString[curMarkPos] = MARK;
    tomaString[curMarkPos - 1] = ch;
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
    curMarkPos = i;
    if (curMarkPos < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

TomaString & TomaString::operator=(TomaString str) {
    int i;
    for (i = 0; i < str.length(); i++) {
        tomaString[i] = str[i];
    }
    tomaString[i] = MARK;
    curMarkPos = i;
    if (curMarkPos < N) {
        i++;
        for (; i <= N; i++) {
            tomaString[i] = 0;
        }
    }
    return *this;
}

bool TomaString::operator==(TomaString str) {
    for (int i = 0; i < curMarkPos; i++) {
        if (tomaString[i] != str[i]) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &stream, const TomaString &str) {
    for (int i = 0; i < str.curMarkPos; i++) {
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
