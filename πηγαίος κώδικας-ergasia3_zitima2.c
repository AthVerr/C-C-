/*
  Name:������������� �����
  Date: 11/11/2010
  Description:�� ����������� ��� ���� ��������������� ���� ������������ ������� ������ n ���������.
  ���� �������� ��� ����� �� ����� ���� �������� �������. �� ��������� ������ �� �������� ��� ��������� n ��� �� ����������� ��� ����.
  ��� ��������, �� ������� 200 ����� �� �������� ������ ����������� (�����������):
1.	������� ������� ������� r ��� �� �������� [1,150].
2.	�� r  != 150, �������� ��� r ���� ����. �� ������ �����������, �� ��������� ���������� �� ��������� ������ ���������.
�����������, �� ��������� ��������� ��� ���� 1.
3.	�� r = 150, ������� ��� ������� ���� ��� ��������� ��� �����. � �������� ��������� ������������� ��� �� ��������� ��������� ���� ������� ���������.
���� �� ��������� ���������� ��������, ���������� ��� ������� ������ ��������� ��� �������� � ���� �� ������ ���������.

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

 int isFull();
 int isEmpty();
 long list_tail = 0;
 long list_head = 0;
 long N;

 int main()
 {
    long counter, temp, i, j, length, max_length = 0;

    cout << "Dwste to megethos tis ouras: ";
    cin >> N;

    long *A = new long[N+1];

    for(i = 1; i <=N; i++)
    {
        A[i] = i;

    }

    list_head = 0;
    list_tail = 0;

    srand((long) 2008011);

    for(i = 0; i < 200; i++)
    {
        counter = 0;
        temp = 1 + rand() % 150;

        if(temp != 150 && isFull() == 0)
        {
            list_tail = (list_tail + 1) % (N+1);
            A[list_tail] = temp;

        }

        else if(isFull() == 1)
        {
                cout << endl << "Sfalma logo iperxeilisis ouras" << endl;
                return 0;
        }

        else if(temp == 150)
        {

             cout << endl << "o arithmos einai o: " << temp << endl;

             for(j = (list_head + 1); j <= list_tail && isEmpty() == 0; j++)
             {
                A[j] = 0;
                counter++;

             }

            if(max_length < counter)
                max_length = counter;

             list_head = 0;
             list_tail = 0;
        }

        if(max_length < counter)
                max_length = counter;

    }

     cout << "to programma termatizei " << endl << "o megistos arithmos stoixeiwn einai o: " << max_length << endl;

    return 0;
 }

 int isFull()
{
	return ((list_head == (list_tail+1)%N));
}

int isEmpty()
{
	if(list_head == list_tail)
		return 1;
	else
		return 0;
}
