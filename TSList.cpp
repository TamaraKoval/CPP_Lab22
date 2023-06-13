#include "TSList.h"

void TSList::deleteFirst() {
    if (head != nullptr) {
        TSElem *temp = head;
        head = head->next;
        length--;
        delete temp;
    }
}

TSList::~TSList() {
    for (int i = 0; i < length; i++) {
        deleteFirst();
    }
}

void TSList::pushBack(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
        length = 1;
    } else {
        tail->next = new TSElem(str);
        tail = tail->next;
        length++;
    }
}

void TSList::pushLastButOne(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
        length = 1;
    } else {
        TSElem *q, *pr, *p;
        q = new TSElem(str);
        for (p = head, pr = nullptr; p != tail; pr = p, p = p->next);
        if (pr == nullptr) {
            q->next = head;
            head = q;
            length++;
        } else {
            q->next = p;
            pr->next = q;
            length++;
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const TSList &list) {
    TSElem *p = list.head;
    for (int i = 0; i < list.length; i++) {
        stream << *p << "\n";
        p = p->next;
    }
    return stream;
}
