#ifndef LAB22_TOMASTRING_H
#define LAB22_TOMASTRING_H

#include <ostream>

const unsigned N = 80;

class TomaString {
    static const char MARK = '@';
    char tomaString[N + 1]{};
    char &operator[](unsigned index);
public:
    TomaString() { tomaString[0] = MARK; }
    static int getMaxLength() { return N; }
    int length() const;
    void append(char ch);
    TomaString & operator=(const char *str);
    TomaString & operator=(TomaString str);
    bool operator==(TomaString str);
    friend std::ostream &operator<<(std::ostream &stream, const TomaString &str);
    friend std::istream &operator>>(std::istream &stream, TomaString &str);
};

#endif //LAB22_TOMASTRING_H
