#ifndef LAB22_TSELEM_H
#define LAB22_TSELEM_H

#include "TomaString.h"

class TSElem {
public:
    TomaString str;
    TSElem *next;
    explicit TSElem(TomaString str, TSElem *next = nullptr) { this->str = str; this->next = next;}
    friend std::ostream &operator<<(std::ostream &stream, const TSElem &elem);
};

#endif //LAB22_TSELEM_H