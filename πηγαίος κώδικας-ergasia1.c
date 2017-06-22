/*
  Name:Βερροιοπούλου Αθηνά
  Date: 14/10/2010
  Description: Στην πρώτη εργαστηριακή άσκηση καλείστε να προσδιορίσετε πειραματικά, το χρόνο εκτέλεσης της σειριακής αναζήτησης.
Να υλοποιήσετε τον αλγόριθμο σειριακής αναζήτησης και να τον εφαρμόσετε σε πίνακα Α με Ν στοιχεία.
Το πρόγραμμα αρχικά θα διαβάζει το μέγεθος Ν του πίνακα και θα δεσμεύει την αντίστοιχη μνήμη.
Ο πίνακας θα αρχικοποιείται με Ν τυχαίους ακέραιους αριθμούς από το διάστημα [1, 50000].
Στη συνέχεια, το πρόγραμμα θα εκτελεί Μ-φορές τα εξής:
1.	Επιλογή τυχαίου αριθμού r από το διάστημα [1, 50000].
2.	Σειριακή αναζήτηση του αριθμού r στον πίνακα.
Τέλος, το πρόγραμμα θα επιστρέφει το μέσο αριθμό συγκρίσεων μεταξύ στοιχείων του πίνακα και το μέσο χρόνο για κάθε σειριακή αναζήτηση.
Επίσης το πρόγραμμα θα επιστρέφει το ποσοστό των τυχαίων αριθμών που βρέθηκαν στον πίνακα (ποσοστό επιτυχημένων αναζητήσεων).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 1000

int main()
{

    int *A;
    int N;
    int i,temp;
    clock_t start, end;
    double elapsed;
    int j,found=0;
    int s=0;//oros sigkrisis
    long o_s=0;//olles oi sigkriseis
    float p=0.0; //pososto tyxaiwn arithmwn pou vrethikan ston pinaka
    double all_time=0; //olos o xronos
    double aver_t;
    long aver_s;

    printf("Dwse arithmo stoixeiwn");
    scanf("%d",&N);  //Eisagwgi arithmou stoixeiwn tou pinaka
    A=(int*)malloc(N*sizeof(int));  // Desmeusi xwrou mnimis
    if(A==NULL)   //Elegxos diathesimotitas mnimis
    {
        printf("There is no memory available\n");
        system("pause");
        exit(1);
    }
    //paragwgi tyxaiwn arithmwn
    srand((long)2008011);/* Αρχικοποίηση γεννήτριας τυχαίων αριθμών με ΑΜ */
    for(i=0;i<N;i++)//Gemisma pinaka me tixaies times
    {
        temp=rand() % 50000;/* n τυχαίοι αριθμοί στο διάστημα [1,LIMIT] */
     *(A+i)=temp;
    }

    for (i=0;i<M;i++)
    {
        temp=rand() % 50000;//Apodosi tyxaias metavlitis pros anazitisi
        start= clock();//wra enarksis anazitisis

        /* Κώδικας του οποίου το χρόνο εκτέλεσης θέλουμε να μετρήσουμε */
        for(j=0;(j<N)&&(found==0);j++)
        {
            s++; //aujanw ton oro sigkrisis kata 1
            found=(temp==(*(A+j)));//Sinthiki eksodou an vrethei o arithmos
        }

        end= clock();//wra liksis anazitisis

        o_s+=s;
        s=0;
        if(found==1)
            p++;
        elapsed = ((double)(end-start));//xronos anazitisis gia tin kathe metavliti
        all_time+=elapsed;
        found=0;
    }
    aver_t=all_time/(double)M;//Euresi tou mesou xronou anazitisis
    aver_s=o_s/M;//Euresi tou mesou orou sigkrisewn

    printf("O mesos xronos anazitisis einai: = %.3f\n",aver_t);
    printf("O mesos oros sigrisewn einai: = %d\n",aver_s);
    printf("To pososto epityximenwn anazitisewn einai: = %0.1f percent.\n",(p/(float)10));

    free(A); // apodesmeusi xwrou mnimis

   system ("pause");
   return 0;
}
