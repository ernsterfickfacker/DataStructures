//модуль базовых подпрограмм
#pragma once
#include <iostream>
#include "HeaderException.h"
using namespace std;

template <typename T>
class Queue_parent {
public: 
	Queue_parent();
	explicit Queue_parent(T elem);
	~Queue_parent();
	bool isEmpty() ;
	void AddEnd(T elem);
	void DeleteBegin();
	void TopToBottom(Queue_parent<T>& outcome);
	T GetInfoBegin();

	
protected:
	T* p;
	int l_arr;
	int d_arr;
	int n_arr;
private:
	void ReduceStockBegin();
	void ReduceStockEnd();
	void IncreaseStockEnd();
	void Stock();
};


#include "BaseQueueArrRealization.ipp"
#include "AdditionalQueueArrRealization.ipp"