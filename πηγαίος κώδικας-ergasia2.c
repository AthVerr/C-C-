/*
  Name:Βερροιοπούλου Αθηνά
  Date: 4/11/2010
  Description:  Να υλοποιήσετε τον αλγόριθμο δυαδικής αναζήτησης και να τον εφαρμόσετε σε πίνακα Α με Ν στοιχεία.
Το πρόγραμμα αρχικά θα διαβάζει το μέγεθος Ν του πίνακα και θα δεσμεύει την αντίστοιχη μνήμη.
Ο πίνακας θα αρχικοποιείται με Ν τυχαίους ακέραιους αριθμούς από το διάστημα [1, 50000].
Στη συνέχεια, το πρόγραμμα θα εκτελεί Μ-φορές τα εξής:
1.	Επιλογή τυχαίου αριθμού r από το διάστημα [1, 50000].
2.	Δυαδική αναζήτηση του αριθμού r στον πίνακα.
Τέλος, το πρόγραμμα θα επιστρέφει το μέσο αριθμό συγκρίσεων μεταξύ στοιχείων του πίνακα και το μέσο χρόνο για κάθε αναζήτηση.
Επίσης το πρόγραμμα θα επιστρέφει το ποσοστό των τυχαίων αριθμών που βρέθηκαν στον πίνακα (ποσοστό επιτυχημένων αναζητήσεων).

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
