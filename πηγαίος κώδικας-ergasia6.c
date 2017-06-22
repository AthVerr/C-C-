/*
  Name:Βερροιοπούλου Αθηνά
  Date: 13/1/2011
  Description:Να υλοποιήσετε τους αλγορίθμους ταξινόμησης με επιλογή, ταξινόμησης με εισαγωγή, ταξινόμησης φυσαλίδας,
ταξινόμησης με χρήση σωρού, ταξινόμησης με συγχώνευση, γρήγορης ταξινόμησης (quicksort) και να τους εφαρμόσετε σε πίνακα Α με Ν στοιχεία.
Το πρόγραμμα αρχικά θα εμφανίζει ένα μενού με επιλογές.
Στην συνέχεια το πρόγραμμα θα διαβάζει το μέγεθος Ν του πίνακα και θα δεσμεύει την αντίστοιχη μνήμη.
Αν για μέγεθος δοθεί η τιμή -1, τότε το πρόγραμμα θα πρέπει να επανέρχεται στο αρχικό μενού.
Για τη δοθείσα τιμή του Ν και ανάλογα με την επιλογή του χρήστη το πρόγραμμα θα εκτελεί 10-φορές τα εξής:
1.	Αρχικοποίηση του πίνακα με Ν τυχαίους ακέραιους αριθμούς στο διάστημα [1, 30000].
2.	Ταξινόμηση του πίνακα (σε αύξουσα σειρά) με τον αλγόριθμο ταξινόμησης που επιλέχθηκε.
Το πρόγραμμα θα επιστρέφει το μέσο αριθμό συγκρίσεων μεταξύ στοιχείων του πίνακα και το μέσο χρόνο ταξινόμησης.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 30000

int  Selection_Sort(int *A, int size);
int swap(int &x, int &y);
int Insertion_Sort(int *A,int size);
int Bubble_Sort(int *A,int size);
int Heap_Sort(int *A,int size);
int fixHeap(int *A, int i, int hs);
int Merge_Sort(int *A ,int left,int right);
int Merge(int*, int, int, int);
int Quicksort(int *A,int left,int right);
void fillArray(int*, int);
int countcomp = 0;


//------------------------------------------------------------------------------

int main()
{

    int size,choice;
    int *A,left, right;
    int i,j, countcomp = 0;
    double AvComp, elapsed = 0, AvTime;
    clock_t start, end;

  do
   {

    printf("\n\nEpilogi Tropou Tajinomisis: ");
    printf("\n  1.Selection Sort.");
    printf("\n  2.Insertion Sort.");
    printf("\n  3.Bubble Sort.");
    printf("\n  4.Heap Sort.");
    printf("\n  5.Merge Sort.");
    printf("\n  6.Quicksort.");
    printf("\n  7.Exit.");

    do
    {
        printf("\n\nEpilogi: ");
        scanf("%d",&choice);

        if(choice<7 && choice>0);
        else if(choice==7)
        {
            printf("You choose to quit\n");
            system("pause");
            exit(1);
        }
        else
            printf("\nLathos eisagogi\n");

    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7);

    printf("Dwse to megethos tou pinaka > ");
    scanf("%d",&size);
    A=(int*)malloc(size*sizeof(int));

    }while(size==-1);
//------------------------------------------------------------------------------

srand((long)2008011);

 for(i = 0; i < 10; i++)
    {
        fillArray(A, size);

        start = clock();

        if(choice==1)
           countcomp += Selection_Sort(A,size);
        else if(choice==2)
           countcomp += Insertion_Sort(A,size);
        else if(choice==3)
            countcomp += Bubble_Sort(A,size);
        else if(choice==4)
            countcomp += Heap_Sort(A,size);
        else if(choice==5)
            countcomp += Merge_Sort(A ,left, right);
        else if(choice==6)
            countcomp += Quicksort(A,left, right);

        end = clock();

        elapsed += ((double) (end - start)) / CLOCKS_PER_SEC;

    }

     AvComp = countcomp / 10.0;
     AvTime = elapsed / 10.0;

    printf("Mesos Arithmos Siggriseon: %.2f \n",AvComp);
    printf("Mesos Xronos Taksinomisis: %.2f \n",AvTime);
   free(A);
    return 0;
}

//------------------------------------------------------------------------------

int  Selection_Sort(int *A, int size)
{
    int i, j, max, countcomp = 0;

    for(i = size; i > 0; i--)
    {
        max = 0;
        for(j = 1; j < i; j++)
        {
            if(A[max] < A[j])
            {
                max = j;

                countcomp++;
            }


            swap(A[max], A[i-1]);
        }
    }

    return countcomp;
};

int Insertion_Sort(int *A,int size)
{
     int i,max, countcomp = 0;
    int l=0,r=(size-1),j,v;

     for(i=l+1;i<=r;i++)
      swap(A[l],A[i]);
       for(i=l+2;i<=r;i++)
        {
            int j=i;
            A[v]=A[i];
            while((A[v] < A[j-1]))
            {
              A[j]=A[j-1];j--;

                countcomp++;
            }
        A[j]=v;
        }
     return countcomp;
};

int Bubble_Sort(int *A,int size)
{
    int i,j,l=0, r=size-1;

    countcomp=0;

    for (i=1;i<r;i++)
     for(j=r;j>i;j--)
     {
        countcomp++;
        if(A[j-1]>A[j])
            swap(A[j-1],A[j]);
     }

    return countcomp;
};

int Heap_Sort(int *A,int size)
{
      long i, hs;

    hs = size;

    for(i = size/2; i > 0; i--)
    {
        countcomp = fixHeap(A, i, hs);
    }

     return countcomp;
};

int Merge_Sort(int *A ,int left,int right)
{
    int mid, j;

    countcomp++;
    if(left >= right)
        return 0;
      countcomp++;
    mid = (left + right)/2;
    Merge_Sort(A, left, mid);
    Merge_Sort(A, mid + 1 , right);
    Merge(A, left, mid, right);

  return countcomp;

};

int Quicksort(int *A,int left,int right)
{

    int x = A[left + rand() % (right - left + 1)];

    int i = left, j = right, temp;

    do
    {
        while (A[i] < x)
        {
            i++;
            countcomp++;
        }
        while (A[j] > x)
        {
            j--;
            countcomp++;
        }

        if (i <= j)
        {
            temp=A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);


    if (left < j)
        Quicksort(A, left, j);
    if (i < right)
        Quicksort(A, i, right);

};

//------------------------------------------------------------------------------

int fixHeap(int *A, int i, int hs)
{
    long mc, l, r;
    int  countcomp=0;

    mc = i;
    l = 2 * mc;
    r = 2 * mc + 1;

    countcomp += 2;

    if((l <= hs) && (A[l] > A[mc]))
        mc = l;

    if((r <= hs) && (A[r] > A[mc]))
        mc = r;

    if(mc != i)
    {
        swap(A[i], A[mc]);
        fixHeap(A, mc, hs);
    }



    return countcomp;
}

int Merge(int*, int, int, int)
{

};

int swap(int &x, int &y)
{
    long temp;

    temp = x;
    x = y;
    y = temp;

    return 0;
}


void fillArray(int *A, int size)
{
    int i, r;

    for(i = 0; i < size; i++)
    {
        r = rand() % 30000;

        A[i] = r;
    }
}
