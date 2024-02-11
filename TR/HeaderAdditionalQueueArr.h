#pragma once
#include "HeaderBaseQueueArr.h"

template <typename T>
class Queue : public Queue_parent<T> {
public:
    Queue() : Queue_parent<T>() {}
    Queue(T elem) : Queue_parent<T>(elem) {}
    Queue(Queue<T>& que) : Queue_parent<T>(que) {}
    T GetInfoEnd();
    void AddBegin(T elem);
    void DeleteEnd();
    int Number();
    void DeleteQueue();
};
template <typename T>
void SolutionQueuePositiveNegative(Queue<T>& source, Queue<T>& outcomeN, Queue<T>& outcomeP);
template <typename T>
void SolutionQueueNumbersSymbols(Queue<T>& source, Queue<T>& outcomeN, Queue<T>& outcomeS);
template <typename T>
ostream& operator << (ostream& stream, Queue_parent<T>& que);
template <typename T>
istream& operator >> (istream& stream, Queue_parent<T>& que);

#include "AdditionalQueueArrRealization.ipp"
#include "BaseQueueArrRealization.ipp"
