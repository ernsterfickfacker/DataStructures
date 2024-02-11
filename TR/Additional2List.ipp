#include <iostream>
#include "HeaderAdditional2List.h"
#include "HeaderBase2List.h"
using namespace std;
//Если в списке из целых чисел максимальный элемент больше заданного числа, удалить из списка чётные элементы.
template<typename T> 
void Task1(List2 <T>& source, T param) {
    if (std::is_same<T, int>::value) {
        if (SearchMax(source) > param) {
            ClearEven(source);
        }
        else cout<<"максимальный элемент меньше заданного числа"<<endl;
    }
    else throw TypeMismatch("несовпадение типов, требовались данные типа int \n");

}
//поиск максимума
template<typename T>
T SearchMax(List2 <T>& source) {
    T buf, buf2;
    if (!source.isEmpty()) {
        Node <T>* buf_n = source.GetBeginNode();
        buf = source.GetInfoBegin();
        while (buf_n != source.GetEndNode()) {
            buf_n = buf_n->Next();
            buf2 = source.GetInfoMiddle(buf_n);
            if (buf2 > buf) { buf = buf2; }
        }
        buf2 = source.GetInfoEnd();
        if (buf2 > buf) { buf = buf2; }
        buf_n = nullptr;
        return buf;
    }
    else throw SearchEmptyList("попытка поиска максимального элемента в пустом списке \n");
}
//удаление
template<typename T>
void ClearEven(List2 <T>& source) {
    if (!source.isEmpty()) {
        int buf;
        if (source.GetBeginNode() == source.GetEndNode()) { if ((source.GetInfoBegin() % 2) == 0) { source.DeleteLastEl(); } }
        else 
        {Node <T>* buf_n = source.GetBeginNode();
        buf_n = buf_n->Next();
        while (buf_n != source.GetEndNode()) {
            if ((source.GetInfoMiddle(buf_n) % 2) == 0) {
               //cout << source.GetInfoMiddle(buf_n) << endl;
                source.DeleteMiddle(buf_n); 
            }
            buf_n = buf_n->Next();
        }
       if ((source.GetInfoBegin() % 2) == 0) { source.DeleteBegin(); }
            if ((source.GetInfoEnd() % 2 )== 0) 
            {   //cout<< source.GetInfoEnd() <<endl;
                if (source.GetBeginNode() == source.GetEndNode()) { source.DeleteLastEl();}
                else  source.DeleteEnd();
            }
            buf_n = nullptr;
        }

        
    }
    else throw ClearEmpty("попытка удаления из пустого списка\n");
}

//Если в списке из вещественных чисел количество положительных элементов больше заданного числа, удалить из списка отрицательные элементы.
//поиск количества положительных
template<typename T>
int NumberPositive(List2 <T>& source) {
    T  buf2;
    int number=0;
    if (!source.isEmpty()) {
        Node <T>* buf_n = source.GetBeginNode();
        //buf = source.GetInfoBegin();
        while (buf_n != source.GetEndNode()) {
            buf2 = source.GetInfoMiddle(buf_n);
            if (buf2 > 0) { number++; }
            buf_n = buf_n->Next();
        }
        buf2 = source.GetInfoEnd();
        if (buf2 > 0) { number++; }
        buf_n = nullptr;
        return number;
    }
    else throw SearchEmptyList("попытка поиска количества положительных в пустом списке \n");
}

template<typename T>
void Task2(List2 <T>& source, T param) {
    if (std::is_same<T, double>::value) {
        if (NumberPositive(source) > param) {
            ClearNegative(source);
        }
        else cout << "максимальный элемент меньше заданного числа" << endl;
    }
    else throw TypeMismatch("несовпадение типов, требовались данные типа double \n");

}

template<typename T>
void ClearNegative(List2 <T>& source) {
    if (!source.isEmpty()) {
        //изначально один элемент и его надо удалить
        if (source.GetBeginNode() == source.GetEndNode()) { if (source.GetInfoBegin()< 0) { source.DeleteLastEl(); } }
        else
            //больше 1 элемента
        {
            Node <T>* buf_n = source.GetBeginNode();
            buf_n = buf_n->Next();
            while (buf_n != source.GetEndNode()) {
                if (source.GetInfoMiddle(buf_n) < 0 ) {
                    //cout << source.GetInfoMiddle(buf_n) << endl;
                    source.DeleteMiddle(buf_n);
                }
                buf_n = buf_n->Next();
            }
            if (source.GetInfoBegin()< 0) { source.DeleteBegin(); }
            if (source.GetInfoEnd() < 0)
            {
               // cout << source.GetInfoEnd() << endl;
                if (source.GetBeginNode() == source.GetEndNode()) { source.DeleteLastEl(); }
                else  source.DeleteEnd();
            }
            buf_n = nullptr;
        }
    }
    else throw ClearEmpty("попытка удаления из пустого списка\n");

}
template<typename T>
istream& operator>>(istream& stream, List2 <T>& source) {
    int n;
    cout<<"введите количество элементов списка"<<endl;
    stream >> n;
    cout << "введите элементы списка" << endl;
    if (n > 0) {
        T buffer;
        stream >> buffer;
        source.Init(buffer);
        for (int i = 1; i < n; i++) {
            stream >> buffer;
            source.AddEnd(buffer);
        }
    }
    return stream;
}


template<typename T>
ostream& operator<<(ostream& stream, List2 <T>& source) {
    if (!source.isEmpty()) {
        Node <T>* it = source.GetBeginNode();
        stream << "в прямом направлении: " << std::endl;
        while (!it->isEmpty()) {
            stream << it->GetInfo() << " ";
            it = it->Next();
        }
        stream << std::endl;
        stream << "в обратном направлении: " << std::endl;
        it = source.GetEndNode();
        while (!it->isEmpty()) {
            stream << it->GetInfo() << " ";
            it = it->Prev();
        }
        stream << std::endl;
    }
    return stream;
}




