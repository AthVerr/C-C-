/*
  Name:������������� �����
  Date: 4/11/2010
  Description:  �� ����������� ��� ��������� �������� ���������� ��� �� ��� ���������� �� ������ � �� � ��������.
�� ��������� ������ �� �������� �� ������� � ��� ������ ��� �� �������� ��� ���������� �����.
� ������� �� �������������� �� � �������� ��������� �������� ��� �� �������� [1, 50000].
��� ��������, �� ��������� �� ������� �-����� �� ����:
1.	������� ������� ������� r ��� �� �������� [1, 50000].
2.	������� ��������� ��� ������� r ���� ������.
�����, �� ��������� �� ���������� �� ���� ������ ���������� ������ ��������� ��� ������ ��� �� ���� ����� ��� ���� ���������.
������ �� ��������� �� ���������� �� ������� ��� ������� ������� ��� �������� ���� ������ (������� ������������ �����������).

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 1000
#define LIMIT 50000

void binary_search(int N);

int main()
{
    int N,*A,;

    printf("Dwse arithmo stoixeiwn");
    scanf("%d",&N);
    A=(int*)malloc(N*sizeof(int));
    if(A==NULL)
    {
        printf("There is no memory available\n");
        system("pause");
        exit(1);
    }

    binary_search(N);

   free(A);
   system ("pause");
    return 0;
}

void binary_search(int n)
{
    long A[n], i, temp, apo, eos, mesos, o_s=0, count=0;
    double elapsed,aver_s,p,aver_t;
    clock_t start, end;

    srand((long) 2008011);

  A[0]=1 + rand( ) % 5;
    for(i=1; i<n-1; i++)
        A[i]=A[i-1]+1+rand( ) % 5;


    start = clock();

    for(i=0; i<M; i++)
    {
        temp= 1 + rand() % LIMIT;

        apo=0;
        eos=n;
        mesos=(apo+eos)/2;
        while(eos-apo>1 && temp!=A[mesos])
        {
            if(temp > A[mesos])
            {
                apo= mesos;
                mesos=(apo+eos)/2;
            }
            else
            {
                eos=mesos;
                mesos=(apo+eos)/2;
            }

            o_s++;

            if(temp==A[mesos])
            {
                count++;
            }
        }
    }

    end = clock();

    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    aver_s=o_s/M;
    aver_t=elapsed/M;
    p=((double)(count*100))/M;

    printf("O mesos oros sigrisewn einai:\t\t%.0f\n",aver_s);
    printf("\n O mesos xronos anazitisis einai:\t\t%.3f\n",aver_t);
    printf("\n To pososto epityximenwn anazitisewn einai: \t%0.1f percent \n",p);
}
