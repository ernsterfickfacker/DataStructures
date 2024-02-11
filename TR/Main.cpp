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
        cout << "              �������                  " << endl;
        std::cout << "������������� ������� ����� ���������:\n";
        Queue<int>queue_1(1);
        std::cout << queue_1;
        std::cout << "���������� ����� � ����� �������:\n";
        queue_1.AddEnd(10);
        queue_1.AddEnd(-15);
        queue_1.AddEnd(20);
        queue_1.AddEnd(-105);
        std::cout << queue_1;
        std::cout << "�������� ����� �� ����� �������:\n";
        queue_1.DeleteEnd();
        std::cout << queue_1;
        std::cout << "���������� ����� � ������ �������:\n";
        queue_1.AddBegin(8);
        std::cout << queue_1;
        std::cout << "�������� ����� ��  �����a �������:\n";
        queue_1.DeleteBegin();
        std::cout << queue_1;
         //�������������, ���������������
        std::cout << "��������� �� ������� �� ������������� � ��������������� ���� int\n";
        Queue<int>queue_3;
        Queue<int>out1; Queue<int>out2;
        std::cin >> queue_3;
        std::cout << "�������� ������� �� int:" << endl;
        std::cout << queue_3;
        SolutionQueuePositiveNegative(queue_3, out1, out2);
        std::cout << "������� �� ������������� ���������:" << endl;
        std::cout << out1;
        std::cout << "������� �� ��������������� ���������:" << endl;
        std::cout << out2;

        //�����, �������
        std::cout << "��������� �� ����� � ������ ������� \n";
        Queue<char>queue_2; //
        std::cin >> queue_2;
        std::cout <<"�������� ������� �� ��������:" <<endl;
        std::cout <<queue_2;
        Queue<char>out3; Queue<char>out4;
        SolutionQueueNumbersSymbols(queue_2, out3, out4);
        std::cout << "������� �� ����:" << endl;
        std::cout << out3;
        std::cout << "������� �� ��������:" << endl;
        std::cout << out4;


        //������
        List2<int> list_1(10);
        cout << "________________________________________________________________" << endl;
        cout << "              ��������������� ������                  " << endl;
        cout << "������, ��������������������� 1 ���������:  " << endl;
        cout << list_1 << endl;
        list_1.AddBegin(3);
        list_1.AddBegin(12);
        cout << "������ ����� ���������� ��������� � ������:  \n";
        cout << list_1 << endl;
        list_1.AddEnd(54);
        cout << "������ ����� ���������� �������� � �����:  \n"; 
        cout << list_1 << endl;
        list_1.DeleteBegin();
        cout << "������ ����� �������� �������� �� ������:  \n";
        cout << list_1 << endl;
        list_1.DeleteEnd();
        cout << "������ ����� �������� �������� �� �����:  \n";
        cout << list_1 << endl;
        
        //���� � ������ �� ����� ����� ������������ ������� ������ ��������� �����, ������� �� ������ ������ ��������.
        List2<int> list_2;
        cout << "������ ���� int, ������� ������  � ����������� �� �������\n";
        cin >> list_2;
        int intbuf1;
        intbuf1 = SearchMax(list_2);
        cout << "������������ ������� � �������:  \n" << intbuf1 << endl;
        cout << "������� ����� ��� ���������  \n";
        int param1;
        cin >> param1;
        cout << "������, �� �������� ������ :  " << endl;
        cout << list_2 << endl;
        Task1(list_2,param1);
        cout << "������, ����� �������� ������ :  " << endl;
        cout << list_2 << endl;

        //���� � ������ �� ������������ ����� ���������� ������������� ��������� ������ ��������� �����, ������� �� ������ ������������� ��������.
       
        List2<double> list_3;
        cout << "������ ���� double, ������� ������������� ��������  � ����������� �� �������\n";
        cin >> list_3;
        int intbuf2;
        intbuf2 = NumberPositive(list_3);
        cout << "���������� ������������� ��������� � �������:  \n" << intbuf2<< endl;
        cout << "������� ����� ��� ���������  \n";
        double param;
        cin >> param;
        cout << "������, �� �������� ������������� ���������:  " << endl;
        cout << list_3 << endl;
        Task2(list_3, param);
        cout << "������, ����� �������� ������������� ���������:  " << endl;
        cout << list_3 << endl;

        //��������� �������� � ������������
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

        std::cout << "���� try ���������� ���������, ���������� �� ������� \n" << endl;
}
    catch (const ClearEmpty& ex�eption) {
        printf( "���������� ClearEmpty       \n");
        printf("%s", ex�eption.getinfo());
       
       
    }
    catch (const TypeMismatch& ex�eption) {
        printf("���������� TypeMismatch       \n");
        printf("%s", ex�eption.getinfo());
      

    }

    catch (const SearchEmptyList& ex�eption) {
        printf("���������� SearchEmptyList       \n");
        printf("%s", ex�eption.getinfo());


    }
return 0;
}

