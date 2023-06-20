#ifndef LAB22_TSLIST_H
#define LAB22_TSLIST_H

#include "TSElem.h"

class TSList {
protected:
    TSElem *tail;
    TSElem *head;
public:
    TSList() { head = nullptr; tail = nullptr; }
    ~TSList();
    void deleteFirst();
    int getLength() const;
    void pushBack(TomaString str);
    void pushLastButOne(TomaString str);
    friend std::ostream &operator<<(std::ostream &stream, const TSList &list);
};

#endif //LAB22_TSLIST_H
