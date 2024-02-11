#include <iostream>
#include "HeaderBaseQueueArr.h"
#include "HeaderAdditionalQueueArr.h"
#include "HeaderBase2List.h"
#include "HeaderAdditional2List.h"
#include "HeaderException.h"
#include <locale.h>
#include <exception>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    try {
        cout << "              очередь                  " << endl;
        std::cout << "Инициализация очереди одним элементом:\n";
        Queue<int>queue_1(1);
        std::cout << queue_1;
        std::cout << "Добавление чисел в конец очереди:\n";
        queue_1.AddEnd(10);
        queue_1.AddEnd(-15);
        queue_1.AddEnd(20);
        queue_1.AddEnd(-105);
        std::cout << queue_1;
        std::cout << "Удаление чисел из конца очереди:\n";
        queue_1.DeleteEnd();
        std::cout << queue_1;
        std::cout << "Добавление чисел в начало очереди:\n";
        queue_1.AddBegin(8);
        std::cout << queue_1;
        std::cout << "Удаление чисел из  началa очереди:\n";
        queue_1.DeleteBegin();
        std::cout << queue_1;
         //отрицательные, неотрицательные
        std::cout << "Разделить на очередь из отрицательных и неотрицательных типа int\n";
        Queue<int>queue_3;
        Queue<int>out1; Queue<int>out2;
        std::cin >> queue_3;
        std::cout << "исходная очередь из int:" << endl;
        std::cout << queue_3;
        SolutionQueuePositiveNegative(queue_3, out1, out2);
        std::cout << "очередь из отрицательных элементов:" << endl;
        std::cout << out1;
        std::cout << "очередь из неотрицательных элементов:" << endl;
        std::cout << out2;

        //цифры, символы
        std::cout << "Разделить на цифры и другие символы \n";
        Queue<char>queue_2; //
        std::cin >> queue_2;
        std::cout <<"исходная очередь из символов:" <<endl;
        std::cout <<queue_2;
        Queue<char>out3; Queue<char>out4;
        SolutionQueueNumbersSymbols(queue_2, out3, out4);
        std::cout << "очередь из цифр:" << endl;
        std::cout << out3;
        std::cout << "очередь из символов:" << endl;
        std::cout << out4;


        //список
        List2<int> list_1(10);
        cout << "________________________________________________________________" << endl;
        cout << "              двунаправленный список                  " << endl;
        cout << "список, проинициализированный 1 элементом:  " << endl;
        cout << list_1 << endl;
        list_1.AddBegin(3);
        list_1.AddBegin(12);
        cout << "список после добавления элементов в начало:  \n";
        cout << list_1 << endl;
        list_1.AddEnd(54);
        cout << "список после добавления элемента в конец:  \n"; 
        cout << list_1 << endl;
        list_1.DeleteBegin();
        cout << "список после удаления элемента из начала:  \n";
        cout << list_1 << endl;
        list_1.DeleteEnd();
        cout << "список после удаления элемента из конца:  \n";
        cout << list_1 << endl;
        
        //Если в списке из целых чисел максимальный элемент больше заданного числа, удалить из списка чётные элементы.
        List2<int> list_2;
        cout << "список типа int, удалить четные  в зависимости от условия\n";
        cin >> list_2;
        int intbuf1;
        intbuf1 = SearchMax(list_2);
        cout << "максимальный элемент в очереди:  \n" << intbuf1 << endl;
        cout << "введите число для сравнения  \n";
        int param1;
        cin >> param1;
        cout << "список, до удаления четных :  " << endl;
        cout << list_2 << endl;
        Task1(list_2,param1);
        cout << "список, после удаления четных :  " << endl;
        cout << list_2 << endl;

        //Если в списке из вещественных чисел количество положительных элементов больше заданного числа, удалить из списка отрицательные элементы.
       
        List2<double> list_3;
        cout << "список типа double, удалить отрицательные элементы  в зависимости от условия\n";
        cin >> list_3;
        int intbuf2;
        intbuf2 = NumberPositive(list_3);
        cout << "количество положительных элементов в очереди:  \n" << intbuf2<< endl;
        cout << "введите число для сравнения  \n";
        double param;
        cin >> param;
        cout << "список, до удаления отрицательных элементов:  " << endl;
        cout << list_3 << endl;
        Task2(list_3, param);
        cout << "список, после удаления отрицательных элементов:  " << endl;
        cout << list_3 << endl;

        //генерация ситуаций с исключениями
        // ClearEmpty
        /*Queue<int>queue_5;
        queue_5.DeleteBegin();*/

        //TypeMismatch
        /* Queue<double>queue_4(1.5);
        queue_4.AddEnd(78.4);
        Queue<double>out01; Queue<double>out02;
        SolutionQueuePositiveNegative(queue_4, out01, out02);*/

        //SearchEmptyList
        List2<int> list_4;
        int mistake;
        mistake = SearchMax(list_4);

        std::cout << "блок try выполнился полностью, исключения не пойманы \n" << endl;
}
    catch (const ClearEmpty& exсeption) {
        printf( "исключение ClearEmpty       \n");
        printf("%s", exсeption.getinfo());
       
       
    }
    catch (const TypeMismatch& exсeption) {
        printf("исключение TypeMismatch       \n");
        printf("%s", exсeption.getinfo());
      

    }

    catch (const SearchEmptyList& exсeption) {
        printf("исключение SearchEmptyList       \n");
        printf("%s", exсeption.getinfo());


    }
return 0;
}

