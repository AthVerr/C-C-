/*
  Name:Βερροιοπούλου Αθηνά
  Date: 17/11/2010
  Description:Να υλοποιήσετε πρόγραμμα χρησιμοποιώντας τις δομές στοίβας και ουράς για να επιτύχετε μετατροπή από Infix σε Postfix notation(Αλγόριθμος Reverse-Polish(I, P)).
Η αριθμητική παράσταση θα εισάγεται σαν συμβολοσειρά που θα αποτελείται από χαρακτήρες 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 και +, -, *, /,(, ).
Οι χρησιμοποιούμενοι τελεστές έχουν τις συνήθεις προτεραιότητες και προσεταιριστικότητα.
Το πρόγραμμα θα ελέγχει αν το κάθε στοιχείο της συμβολοσειράς είναι αριθμός ή σύμβολο πράξης ή παρένθεση
και θα μετατρέπει την αριθμητική παράσταση χρησιμοποιώντας λειτουργίες της στοίβας και της ουράς (σύμφωνα με τον αλγόριθμο Reverse-Polish).
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
