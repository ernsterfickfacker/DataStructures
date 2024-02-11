#pragma once
#include <iostream>
#include "HeaderBaseQueueArr.h"

template <typename T>
Queue_parent<T>::Queue_parent() { //к-р умолчания
	p = new T[10];
	l_arr = 0; 
	d_arr = 10;
	n_arr = 0;
}
template <typename T>
Queue_parent<T>::Queue_parent(T elem) { 
	p = new T[10];
	l_arr = 0;
	d_arr = 10 - 1;
	n_arr = 1;
	p[n_arr-1] = elem;
	//cout << endl;
	//cout << "инициализация одним элементом"<<endl;
    /*cout << l_arr;
	cout << n_arr;
	cout << d_arr << endl;*/
}
template <typename T>
Queue_parent<T>::~Queue_parent() { 
	/*cout << "начало работы деструктора" << endl;
	cout << "l_arr" <<l_arr << endl;
	cout << "n_arr"<< n_arr << endl;
	cout << "d_arr "<< d_arr << endl;*/
	
	if (n_arr > 0) {
		delete[] p;
		l_arr = 0;
		d_arr = 0;
		n_arr = 0;
		//cout << "вызов деструктора" << endl;
	}
	/*else cout << "структура пуста" << endl;*/
}

template <typename T>
void Queue_parent<T>::Stock() {
	if (l_arr== 10) {
		ReduceStockBegin();
	}
	if (d_arr == 0) {
		IncreaseStockEnd();
	}
	else if (d_arr == 20) {
		ReduceStockEnd();
	}
}

template <typename T>
void Queue_parent<T>::ReduceStockBegin() {
	T* p2;
	p2 = new T[n_arr + d_arr];
	for (int i = 0; i < n_arr + d_arr; i++) {
		p2[i] = p[i + 10];
	}
	delete[] p;
	p = p2;
	l_arr-= 10;
}

template <typename T>
void Queue_parent<T>::ReduceStockEnd() {
	T* p2;
	p2 = new T[l_arr+ n_arr];
	for (int i = 0; i < l_arr+ n_arr; i++) {
		p2[i] = p[i];
	}
	delete[] p;
	p = p2;
	d_arr -= 10;
}

template <typename T>
void Queue_parent<T>::IncreaseStockEnd() {
	T* p2;
	p2 = new T[l_arr+ n_arr + d_arr + 10];
	for (int i = 0; i < l_arr+ n_arr + d_arr; i++) {
		p2[i] = p[i];
	}
	delete[] p;
	p = p2;
	d_arr += 10;
}

template <typename T>
bool Queue_parent<T>::isEmpty() {
	return (n_arr == 0);
}

template <typename T>
void Queue_parent<T>::AddEnd(T elem) {
	Stock();
	d_arr--;
	p[n_arr + l_arr] = elem; 
	n_arr++;
	
}

template <typename T>
void Queue_parent<T>::DeleteBegin() { 
	if (isEmpty()) throw ClearEmpty("попытка удаления из пустой очереди\n");
	else {
		Stock();
		p[l_arr] = 0;
		l_arr++;
		n_arr--;
	}
}
template <typename T>
T Queue_parent<T>::GetInfoBegin() {
	return p[l_arr];

}
 
template <typename T>
void Queue_parent<T>::TopToBottom(Queue_parent<T>& outcome) { 
	T buf;
	if (!isEmpty()) {
		buf = GetInfoBegin();
		outcome.AddEnd(buf);
		DeleteBegin();
	}
}




//
//template <typename T>
//void Queue_parent<T>::ReduceStockBegin() {
//	T* bufp;
//	bufp = new T[d_arr + n_arr];//убираем L
//	for (int i = 0; i < d_arr + n_arr; i++) {
//			bufp[i] = p[i+10];
//		}
//		delete[] p;//освободить прошлую память
//		p = bufp;
//		l_arr = 0;
//}
//
//template <typename T>
//void Queue_parent<T>::ReduceStockEnd() {
//	T*bufp;
//	bufp = new T[l_arr + n_arr];
//	for (int i = 0; i < l_arr + n_arr; i++) {
//		bufp[i] = p[i];
//	}
//	delete[] p;
//	p =bufp;
//	d_arr = 10;
//}
//template <typename T>
//void Queue_parent<T>::IncreaseStockEnd() {
//	T* bufp;
//	bufp = new T[l_arr + n_arr + d_arr + 10];
//	for (int i = 0; i <( l_arr + n_arr + d_arr); i++) {
//		bufp[i] = p[i];
//	}
//	delete[] p;
//	p = bufp;
//	d_arr += 10;
//}
//template <typename T>
//void Queue_parent<T>::Stock() {
//	if (l_arr >10) ReduceStockBegin();
//	if (d_arr > 10) ReduceStockEnd();//
//	else if (d_arr == 0) IncreaseStockEnd();
//}