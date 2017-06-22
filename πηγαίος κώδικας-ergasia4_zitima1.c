/*
  Name:Βερροιοπούλου Αθηνά
  Date: 17/11/2010
  Description: Να υλοποιήσετε μια ουρά προτεραιότητας μέγιστου στοιχείου χρησιμοποιώντας τη δομή του σωρού.
Τα στοιχεία της ουράς προτεραιότητας θα είναι ακέραιοι αριθμοί.
Το πρόγραμμα θα διαβάζει τον αριθμό n των στοιχείων που εισάγονται στην ουρά και θα εκτελεί τα παρακάτω βήματα:
1. Διαδοχική εισαγωγή n τυχαίων αριθμών στην ουρά προτεραιότητας. Οι τυχαίοι αριθμοί θα επιλέγονται από το διάστημα [1, 50000].
2. Εξαγωγή από την ουρά προτεραιότητας των n/10 μεγαλύτερων αριθμών.
Το πρόγραμμα θα επιστρέφει το μέσο αριθμό συγκρίσεων μεταξύ στοιχείων του πίνακα και το μέσο χρόνο τόσο για την εισαγωγή νέου στοιχείου όσο και
για την εξαγωγή του μέγιστου στοιχείου.
*/

#include <iostream>
#include <time.h>

using namespace std;

int insert(int r,int *queue,int &temp,int n);
int deleteMax(int *queue,int &temp);
clock_t start, end;
double elapsed;
int count = 0;

int main()
{
    int temp = 0, n, i,count;

    cout << "Dwse ta stoixeia tou pinaka";
    cin >> n;
    int *queue = new int[n+1];
    queue[0] = -1;

    srand((long)2008011);

    start = clock();

    for(i = 1; i <= n; i++)
    {
        insert(rand()%50000,queue,temp,n);
    }

    end = clock();

    int m_s = (int)count / n;
    cout << "o mesos arithmos sygrisewn tou pinaka einai: " << m_s << endl;
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "o mesos xronos gia tin eisagwgi new stoixeiou tou pinaka einai: " << elapsed << endl;

    count = 0;

    start = clock();

    for(i = 0; i < n/10; i++)
    {
        deleteMax(queue,temp);
    }

    end = clock();

    cout << "o mesos arithmos sigriseon kata tin eksagogi megistou stoixeiou einai: " << count/(n/10) << endl;
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "o mesos xronos eksagogis megistou stoixeiou tou pinaka: " << elapsed/(n/10) << endl;

    return 0;

}

int insert(int r,int *queue,int &temp,int n)
{
    int i,count;

    if(temp >= n)
    {
        count++;
        return 0;
    }

    for(i = temp; i >= 0; i--)
    {
        if(queue[i] > r)
        {
            count++;
            queue[i+1] = queue[i];
        }
        else{
            queue[i+1] = r;
            temp++;
            return 0;
        }
    }

    return 0;
}

int deleteMax(int *queue,int &temp)
{
    temp--;
    return temp + 1;
}
