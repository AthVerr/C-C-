/*
  Name:������������� �����
  Date: 17/11/2010
  Description:�� ����������� ��������� ��������������� ��� ����� ������� ��� ����� ��� �� ��������� ��������� ��� Infix �� Postfix notation(���������� Reverse-Polish(I, P)).
� ���������� ��������� �� ��������� ��� ������������ ��� �� ����������� ��� ���������� 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ��� +, -, *, /,(, ).
�� ����������������� �������� ����� ��� �������� �������������� ��� �������������������.
�� ��������� �� ������� �� �� ���� �������� ��� ������������� ����� ������� � ������� ������ � ���������
��� �� ���������� ��� ���������� ��������� ��������������� ����������� ��� ������� ��� ��� ����� (������� �� ��� ��������� Reverse-Polish).
*/

#include <iostream>

using namespace std;

float Array[128];
int top = -1;

bool push( char *input,char *output);
bool pop(char *input);

int main()
{
    char input[128];
    float num2;
    char output[128];

    printf("Dwse mia arithmitiki parastasi : ");
    scanf( "%c" ,&input);

    printf("input: %s\n", input);
    if(push(input, output))
    {
        printf("output: %s\n", output);
        if(!pop(output))
            printf("\nInvalid input\n");
    }

       return 0;
}

bool push( char *input,char *output)
{
    float x;
  Array[++top] = x;
}
bool pop(char *input)
{
    return(Array[top--]);

}
