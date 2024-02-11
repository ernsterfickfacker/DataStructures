#pragma once
#include <iostream>
#include "HeaderException.h"
#include "HeaderBase2List.h"
using namespace std;
template<typename T>
ostream& operator <<(ostream& stream, List2<T>& source);
template<typename T> 
istream& operator >>(istream& stream, List2<T>& source);
template<typename T>
T SearchMax(List2 <T>& source);
template<typename T>
void ClearEven(List2 <T>& source);
template<typename T>
void Task1(List2 <T>& source, T param);
template<typename T>
int NumberPositive(List2 <T>& source);
template<typename T>
void ClearNegative(List2 <T>& source);
template<typename T>
void Task2(List2 <T>& source, T param);
#include "Additional2List.ipp"