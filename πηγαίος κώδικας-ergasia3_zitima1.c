/*
  Name:Βερροιοπούλου Αθηνά
  Date: 11/11/2010
  Description: Να υλοποιήσετε μια στοίβα χρησιμοποιώντας διασυνδεδεμένη λίστα. Κάθε στοιχείο της στοίβας πρέπει αποτελείται από έναν χαρακτήρα.
Χρησιμοποιώντας τη στοίβα, να υλοποιήσετε πρόγραμμα που θα ελέγχει τη σωστή χρήση των παρενθέσεων σε μία αριθμητική παράσταση.
Το πρόγραμμα θα διαβάζει μιαν αριθμητική παράσταση σαν συμβολοσειρά που αποτελείται από χαρακτήρες – μεταβλητές, σύμβολα αριθμητικών πράξεων (+, – *, /, ^),παρενθέσεις, και ενδεχομένως κάποια κενά.
Το πρόγραμμα θα ελέγχει την αριθμητική παράσταση και θα αποφαίνεται σχετικά με τη σωστή χρήση των παρενθέσεων (και μόνο).Αν υπάρχει πρόβλημα,θα επισημαίνεται η πρώτη παρένθεση χωρίς ταίριασμα.

*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>

using namespace std;

typedef struct node
{
    int next;
    struct node *prev;
}Node;

Node *list_handler(char deixtis);
bool push(int);
int pop();
Node *head;
int i = 0;

int main()
{
    char deixtis;
    int counter;
    counter = 0;

    cout << "Dwse mia arithmitiki parastasi:";

    while ((deixtis = getchar()) != '\n' && i >= 0)
    {
        if(deixtis == '(')
        {
            counter++;
            push(counter);
        }

        if(deixtis== ')')
        {
            if(i == 0)
            {
                cout << "Lathos xrisi tis " << counter << " (." << endl;
                return 0;
            }
            else if(i > 0)
            {
                counter++;
                cout << counter << " = " << pop() << endl;
            }
        }
    }

    if(i> 0)
        cout << "Lathos xrisi tis " << i << " {." << endl;

    return 0;
}


Node *list_handler(int temp)
{
    Node *p = new Node;
    p -> next = temp;
    return(p);
}


bool push(int temp)
{
    Node *p =list_handler(temp);

    p -> prev = head;
    head = p;
    cout << p -> next << endl;
    i++;

    return true;
}

int pop()
{
    int temp= 0;

    if(head != NULL);
    {
        temp= head -> next;
        head = head -> prev;
        i--;
    }

    return temp;
}
