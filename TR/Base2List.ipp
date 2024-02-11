#include "HeaderBase2List.h"

//узел
template<typename T>
bool Node <T>::isEmpty() {
    return this == 0; 
}

template<typename T>
Node <T>* Node <T>::Next() {
    return this->next;
}

template<typename T>
Node <T>* Node <T>::Prev() {
    return this->prev;
}

template<typename T>
 T Node <T>::GetInfo() {
    return this->value;
}

// онструктор
template<typename T>
List2 <T>::List2(T x) {
    Node <T>* buf_list;
    buf_list = new Node <T>;
    buf_list->value = x;
    buf_list->next = buf_list->prev = nullptr;
    begin = end = buf_list;
}

template<typename T>
List2 <T>::List2() {
    begin = end = nullptr;
}

template<typename T>
List2 <T>::List2(List2 <T>& source) {
    Node <T>* buf_list;
    buf_list = new Node <T>;
    buf_list->value = source.begin->GetInfo();
    buf_list->next = buf_list->prev = nullptr;
    begin = end = buf_list;

    buf_list = source.begin->Next();
    while (!buf_list->isEmpty()) {
        AddEnd(buf_list->GetInfo());
        buf_list = buf_list->Next();
    }
}
//удаление последнего элемента списка
template<typename T>
void List2 <T>::DeleteLastEl() {
    delete begin;
    begin = nullptr;
    end = nullptr;
}

template<typename T>
List2 <T>::~List2() {
    Node <T>* buf_list = begin;
    while (begin != end) {
        this->DeleteBegin();
    }
    if (!begin->isEmpty()) this->DeleteLastEl();
}

//двунаправленный список
template<typename T>
bool List2 <T>::isEmpty() { 
    return begin == nullptr;
}

template<typename T>
void List2 <T>::Init(T x) {
    Node <T>* buf_list;
    buf_list = new Node <T>;
    buf_list->value = x;
    buf_list->next = buf_list->prev = nullptr;
    begin = end = buf_list;
}

template<typename T>
void List2 <T>::AddBegin(T x) {
    Node <T>* buf_list;
    buf_list = new Node <T>;
    buf_list->prev = nullptr;
    buf_list->value = x;
    buf_list->next = begin;
    begin->prev = buf_list;
    begin = buf_list;
}

template<typename T>
void List2 <T>::AddEnd(T x) {
    Node <T>* buf_list;
    buf_list = new Node <T>;
    buf_list->prev = end;
    buf_list->value = x;
    buf_list->next = nullptr;
    end->next = buf_list;
    end = buf_list;
}

template<typename T>
void List2 <T>::AddMiddle(T x, Node <T>* n) {
    Node <T>* buf_list, * buf_list2;
    buf_list = new Node <T>;
    buf_list2 = n->Next();
    buf_list->value = x;
    buf_list->prev = n;
    n->next = buf_list;
    buf_list->next = buf_list2;
    buf_list2->prev = buf_list;
}

template<typename T>
void List2 <T>::DeleteBegin() {
    Node <T>* buf_list;
    buf_list = begin;
    begin = begin->Next();
    buf_list->next = nullptr;
    begin->prev = nullptr;
    delete buf_list;
}

template<typename T>
void List2 <T>::DeleteEnd() {
    Node <T>* buf_list;
    buf_list = end;
    end = end->Prev();
    buf_list->prev = nullptr;
    end->next = nullptr;
    delete buf_list;
}

template<typename T>
void List2 <T>::DeleteMiddle(Node <T>*& n) {
    Node <T>* buf_list, * buf_list2;
    buf_list = n;
    n = buf_list->Prev();
    buf_list2 = buf_list->Next();
     buf_list->prev = nullptr;
    buf_list->next = nullptr;
    n->next = buf_list2;
    buf_list2->prev = n;//buf_list2 было nullptr

    delete buf_list;
}



template<typename T>
 T List2 <T>::GetInfoBegin() {
    return this->begin->GetInfo();
}

template<typename T>
 T List2 <T>::GetInfoEnd() {
    return this->end->GetInfo();
}

template<typename T>
 T List2 <T>::GetInfoMiddle(Node <T>* n) {
    return n->GetInfo();
}
template<typename T>
Node <T>* List2 <T>::GetBeginNode() {
    return begin;
}

template<typename T>
Node <T>* List2 <T>::GetEndNode() {
    return end;
}

