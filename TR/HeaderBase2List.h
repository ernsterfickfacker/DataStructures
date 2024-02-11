#pragma once
#pragma once
#include <iostream>
#include "HeaderException.h"
using namespace std;
template<typename T>

class List2;

template<typename T>
class Node {
public:
    bool isEmpty();
    Node<T>* Next();
    Node<T>* Prev();
    T GetInfo();

    friend List2<T>;
protected:
  T value;
    Node* prev;
    Node* next;
};

template<typename T>
class List2 {
    Node<T>* begin, * end;
public:
    //Конструкторы
    List2();
    List2( T x);
    List2(List2<T>& source);
    //удаление последнего элемента списка
    void DeleteLastEl();
    //Деструктор
    ~List2();
    bool isEmpty();
    void Init( T x);
    void AddBegin( T x);
    void AddEnd( T x);
    void AddMiddle( T x, Node<T>* n);
    void DeleteBegin();
    void DeleteEnd();
    void DeleteMiddle(Node<T>*& n);
    //void DeleteMiddle(Node<T> *n);
    T GetInfoBegin();
    T GetInfoEnd();
    T GetInfoMiddle(Node<T>* n);
    // получение уазателей на начало и конец
    Node<T>* GetBeginNode();
    Node<T>* GetEndNode();


};

#include "Base2List.ipp"


