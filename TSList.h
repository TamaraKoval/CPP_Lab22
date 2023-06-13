#ifndef LAB22_TSLIST_H
#define LAB22_TSLIST_H

#include "TSElem.h"

class TSList {
protected:
    TSElem *tail;
    TSElem *head;
    int length;
public:
    TSList() { head = nullptr; tail = nullptr; length = 0;}
    ~TSList();
    void deleteFirst();
    int getLength() const { return length; }
    void pushBack(TomaString str);
    void pushLastButOne(TomaString str);
    friend std::ostream &operator<<(std::ostream &stream, const TSList &list);
};

#endif //LAB22_TSLIST_H
