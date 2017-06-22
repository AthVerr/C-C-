/*
  Name:Βερροιοπούλου Αθηνά-icsd08011
  Date: 20/1/2011
  Description:exersise 5
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>

FILE *Stocks;
FILE *Data;

typedef struct treeNode
{
	 char code[40];
	 char onoma_m[200];
	 float poso;
	 int arithmos_m;
	 float t_timi;
     struct treeNode *leftPtr;
     struct treeNode *rightPtr;
     struct treeNode *p;
}Node;

Node *root = NULL;
Node *cnt=NULL;

void save(char kwdikos[], char name[],float poso_ep,int NumberOfStocks,float price);
void inorder(Node *x);
Node* anazitisi(int *sygriseis);
Node* delete_metoxi (char code[],Node* root);
Node* findmin(Node* temp);
void Level(Node *root, int epipedo);
int height(Node *x);

//--------------------------------------------------------------------------
int main()
{
     char kwdikos[40];
	 char name[200];
	 float poso_ep;
	 int NumberOfStocks;
	 float price;
	 int n,i;
	 int choice;
	 int sygriseis=0;
     Node* temp,*temp1;

      root = NULL;
      Stocks=fopen("Stocks.txt","r");

      while(!feof(Stocks))
         {
            fscanf(Stocks,"%s%*c%s%*c%f%*c%d%*c%f",kwdikos,name,&poso_ep,&NumberOfStocks,&price);
            save(kwdikos,name,poso_ep,NumberOfStocks,price);
         }
        fclose(Stocks);

     do
     {
      printf("1.Inorder diasxisi\n");
      printf("2.Anazitisi\n");
      printf("3.Tropopihsi\n");
      printf("4.Diagrafi metoxis\n");
      printf("5.Exit\n");

      printf("\nEpilogi: ");
      scanf("%d",&choice);

    }while(choice == 1 && choice == 2 && choice == 3 && choice == 4 && choice == 5);



        if(choice==1){
           inorder(root);
           printf("The height of the tree is:%d\n",height(root));}

        else if(choice==2){
           temp=anazitisi(&sygriseis);

            if(temp==NULL)
            { printf("Den yparxei auti i epilogi\n");}
        else{
          printf("\nTitle %s\nName %s\nInvested %.4f NumberOfStocks %d\nvalue %.4f\n\n",temp->code,temp->onoma_m,temp->poso,temp->arithmos_m,temp->t_timi);
          printf("Xreiastikan %d sygriseis\n\n",sygriseis);
            }
        }

        else if(choice==3){
            temp=anazitisi(&sygriseis);

            if(temp==NULL){
        printf("Den yparxei auti i epilogi\n");
                          }
        else{
        printf("Give name[%s]:",temp->onoma_m);
        scanf("%s",temp->onoma_m);
        printf("Give the Invested amount[%.3f]:",temp->poso);
        scanf("%f",&temp->poso);
        printf("Give the NumberOfStocks[%d]:",temp->arithmos_m);
        scanf("%d",&temp->arithmos_m);
        printf("Give the value[%.3f]:",temp->t_timi);
        scanf("%f",&temp->t_timi);
        printf("Give the Title[%s]:",temp->code);
        scanf("%s",kwdikos);

           if ((strcmp(kwdikos,temp->code)!=0))
            {
              strcpy(name,temp->onoma_m);
              poso_ep=temp->poso;
              NumberOfStocks=temp->arithmos_m;
              price=temp->t_timi;
              delete_metoxi(temp->code,root);
              save(kwdikos,name,poso_ep,NumberOfStocks,price);
            }
        }
                          }
        else if(choice==4){

            printf("Give the Title:");
	        scanf("%s",kwdikos);
           temp=delete_metoxi(kwdikos,root);
        }
        else if(choice==5)
        {
            printf("You choose to quit\n");
            Data=fopen("Stocks.txt","w");
             n=height(root);
             for(i=1; i<=n; i++){
            Level(root, i);
        }
        fclose(Data);
            system("pause");
            exit(1);
        }
    return 0;
}

//------------------------------------------------------------------------------------------------------
void save(char kwdikos[], char name[],float poso_ep,int NumberOfStocks,float price)
{
     Node *temp1, *temp2;
     temp1=(Node*)malloc(sizeof(Node));
	 strcpy(temp1->code,kwdikos),strcpy(temp1->onoma_m,name);
	 temp1->poso=poso_ep,temp1->arithmos_m=NumberOfStocks,temp1->t_timi=price;
     temp1->leftPtr = NULL,temp1->rightPtr=NULL, temp1->p = NULL;

    if (root == NULL)
     {
        root = temp1;
        cnt = temp1;
     }

     else
     {
         temp2 = root;
		 while(temp1->p == NULL)
		 {
             if(strcmp(temp1->code,temp2->code) < 0)
			 {
                 if(temp2->leftPtr == NULL)
				 {
                     temp2->leftPtr = temp1;
					 temp1->p = temp2;
				 }
				 else
				 {
                     temp2 = temp2->leftPtr;
				 }
			 }

             if(strcmp(temp1->code,temp2->code)>0)
			 {
                 if(temp2->rightPtr == NULL)
				 {
                     temp2->rightPtr = temp1;
					 temp1->p = temp2;
				 }
				 else
				 {
                     temp2 = temp2->rightPtr;
				 }
			 }

		     if (strcmp(temp1->code,temp2->code)==0)
			 {
                 return;
             }
		 }
		 cnt = temp1;
     }
}

void inorder(Node *x)
{
    if (x == NULL) return ;
    inorder(x->leftPtr);
    printf("Title %s\nName %s\nInvested  %.4f NumberOfStocks %d\nvalue %.4f\n\n",x->code,x->onoma_m,x->poso,x->arithmos_m,x->t_timi);
    inorder(x->rightPtr);

}

Node * anazitisi(int *sygriseis)
{
     int x;
     Node *temp;
	 temp=root;
	 *sygriseis=0;
	 char kwdikos[40];

	 printf("Give the Title:");
	 scanf("%s",kwdikos);

	 while(temp != NULL)
	 {
         if(strcmp(temp->code,kwdikos) == 0)
		 {
	 	     *sygriseis=*sygriseis+1;
	 	      break;
		 }
		 if(strcmp(temp->code,kwdikos) >0)
	 	 {
			*sygriseis=*sygriseis+1;
             temp= temp->leftPtr;
		 }else
		 {
			 *sygriseis=*sygriseis+1;
             temp = temp->rightPtr;
		 }
	 }
	 return temp;
}

int height(Node *x)
{
    if (x == NULL) return(0);
      int hleft = height(x->leftPtr);
      int hright = height(x->rightPtr);
    if (hleft > hright) return(++hleft);
    else return(++hright);
}

void Level(Node *root, int epipedo)
{

    if(root==NULL)
    {
        return;
    }
    if(epipedo==1)
    {
        fprintf(Data,"%s %s %.2f %d %.2f\n",root->code,root->onoma_m,root->poso,root->arithmos_m,root->t_timi);
    }
    else if(epipedo>1)
    {
          Level(root->leftPtr, epipedo-1);
          Level(root->rightPtr, epipedo-1);
    }
}

Node* findmin(Node* temp)
{
if (temp==NULL || temp->leftPtr ==NULL)
return temp;
return findmin(temp->leftPtr);
}

Node* delete_metoxi (char x[],Node* y)
{

Node* temp;

    if (y==NULL)
    {
    printf("\nDen yparxei auti i epilogi\n");
    }

    else
    {

    if(strcmp(y->code,x)>0)
    y->leftPtr=delete_metoxi(x,y->leftPtr);

    else if(strcmp(x,y->code)>0)
    y->rightPtr=delete_metoxi(x,y->rightPtr);

    else{
        if(y->leftPtr && y->rightPtr)
        {
        temp=findmin(y->rightPtr);
        strcpy(y->code,temp->code);
        strcpy(y->onoma_m,temp->onoma_m);
        y->poso=temp->poso;
        y->arithmos_m=temp->arithmos_m;
        y->t_timi=temp->t_timi;
        y->rightPtr=delete_metoxi(y->code,y->rightPtr);
        }

    else {
        temp=y;

        if(y->leftPtr==NULL)
        y=y->rightPtr;
        else if (y->rightPtr==NULL)
        y=y->leftPtr;
        free(temp);
         }
        }
    }
return y;
}
