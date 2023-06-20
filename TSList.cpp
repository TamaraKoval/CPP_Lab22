#include "TSList.h"

int TSList::getLength() const {
    if (head) {
        TSElem *p;
        int i;
        for (i = 0, p = head; p!= nullptr; p=p->next, i++);
        return i;
    }
    return 0;
}

void TSList::deleteFirst() {
    if (head != nullptr) {
        TSElem *temp = head;
        head = head->next;
        delete temp;
    }
}

TSList::~TSList() {
    for (int i = 0; i < this->getLength(); i++) {
        deleteFirst();
    }
}

void TSList::pushBack(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
    } else {
        tail->next = new TSElem(str);
        tail = tail->next;
    }
}

void TSList::pushLastButOne(TomaString str) {
    if (!head) {
        head = new TSElem(str);
        tail = head;
    } else {
        TSElem *q, *pr, *p;
        q = new TSElem(str);
        for (p = head, pr = nullptr; p != tail; pr = p, p = p->next);
        if (pr == nullptr) {
            q->next = head;
            head = q;
        } else {
            q->next = p;
            pr->next = q;
        }
    }
}

std::ostream &operator<<(std::ostream &stream, const TSList &list) {
    TSElem *p = list.head;
    for (int i = 0; i < list.getLength(); i++) {
        stream << *p << "\n";
        p = p->next;
    }
    return stream;
}