#pragma once
#include "HeaderAdditionalQueueArr.h"
#include "HeaderBaseQueueArr.h"
#include <exception>

template <typename T>
void Queue<T>::AddBegin(T elem) {
	Queue<T> bufQueue;
	while (!this->isEmpty()) { this->TopToBottom(bufQueue); }
	this->AddEnd(elem);
while (!bufQueue.isEmpty()) { bufQueue.TopToBottom(*this); }
}

template <typename T>
void Queue<T>::DeleteEnd()  {
	Queue<T> bufQueue;
	int buf =0;
	if (this->isEmpty()) throw ClearEmpty("попытка удаления из пустой очереди\n");
	else {
		buf = this->Number();
		//cout << buf << endl;
		for (int i = 0; i < buf - 1; i++) {
			this->TopToBottom(bufQueue);
			//std::cout << "буферная очередь  " << bufQueue << endl;
		}
		this->DeleteQueue();
		while (!bufQueue.isEmpty()) {
			bufQueue.TopToBottom(*this);
			//std::cout << "начальная очередь" << *this << endl;
		}
	}
}
template <typename T>
int Queue<T>::Number() {
	int buf = 0;
	Queue<T> bufQueue;
	while (!this->isEmpty()) { this->TopToBottom(bufQueue); buf++; }

	while (!bufQueue.isEmpty()) {
		bufQueue.TopToBottom(*this);

	};
	return buf;
}
template <typename T>
void Queue<T>::DeleteQueue() {
	if (this->isEmpty()) throw ClearEmpty("попытка удаления из пустой очереди\n");
	else {
		while (!this->isEmpty()) {
			this->DeleteBegin();
		}
	return;
	}
}
template <typename T>
T Queue<T>::GetInfoEnd() {
	Queue<T> bufQueue; T elem;
	while (!this->isEmpty()) {
		elem = this->GetInfoBegin();
		this->TopToBottom(bufQueue);
	}
	while (!bufQueue.isEmpty()) {
		bufQueue.TopToBottom(*this);
	}
	return elem;
}

template <typename T>
ostream& operator << (ostream& stream, Queue_parent<T>& que) {
	Queue_parent<T> buf;
	if (!que.isEmpty()) {
		while (!que.isEmpty()) {
			//cout<< que.GetInfoBegin() <<endl;
			stream << que.GetInfoBegin() << " ";
			que.TopToBottom(buf);
		}
		stream << endl;
		while (!buf.isEmpty()) {
			buf.TopToBottom(que);
		}
	}
	return stream;
}
template <typename T>
istream& operator >> (istream& stream, Queue_parent<T>& que) {
	int n;
	T buf;
	cout << "введите количество данных в очереди " << endl;
	stream >> n;
	cout << "введите данные " << endl;
	for (int i = 0; i < n; i++) {
	stream >> buf;
		que.AddEnd(buf);
	}
	return stream;
}
//Создать структуру из целых чисел.Разделить её содержимое на отрицательные и неотрицательные числа.
template <typename T>
void SolutionQueuePositiveNegative(Queue<T>& source, Queue<T>& outcomeN, Queue<T>& outcomeP) {
	T buf;
	if (std::is_same<T, int > ::value) {

		while (!source.isEmpty()) {
			buf = source.GetInfoBegin();

			if (buf < 0) {
				source.TopToBottom(outcomeN);
			}
			else source.TopToBottom(outcomeP);
		}
	}
	else throw TypeMismatch("несовпадение типов, требовались данные типа int\n");
}
//Создать структуру из символов.Разделить её содержимое на цифры и прочие символы.
template <typename T>
void SolutionQueueNumbersSymbols(Queue<T>& source, Queue<T>& outcomeN, Queue<T>& outcomeS) {
	T buf;
	if (std::is_same<T, char > ::value) {
		while (!source.isEmpty()) {
			buf = source.GetInfoBegin();
			if ((buf == '0') || (buf == '1') || (buf == '2') || (buf == '3') || (buf == '4') || (buf == '5') || (buf == '6') || (buf == '7') || (buf == '8') || (buf == '9')) {
				source.TopToBottom(outcomeN);
			}
			else source.TopToBottom(outcomeS);
		}
	}
	else throw TypeMismatch("несовпадение типов, требовались данные типа char\n");
}

#include "BaseQueueArrRealization.ipp"