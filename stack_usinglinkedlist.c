// Stack Implementation Using Linked List //

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct link {
                              int info;
                              struct link *next;
                    }LINK; 
typedef struct stack {
                              LINK *top;
                     }STACK;
STACK s;

void pushs(int x);
int emptys(void);
LINK * getnode(void);
void freenode(LINK *);
int pops();
main(void)
{
   int ch,e,temp;
   LINK *x;
   s.top = (LINK*) NULL;
   while(1)
   {
          system("cls"); 
          printf("\n\n\nStack Implementation Using Linked List\n\n");
          printf("1. Push Elements\n");
          printf("2. Pop Elements\n");
          printf("3. Display Elements\n");
          printf("4. Exit\n\n");
          printf("Enter Choice:");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1:
                     printf("\nEnter Element:");
                     scanf("%d",&e);
                     pushs(e);                           
                     break;
              case 2:
                     if(emptys())
                           printf("\nUnderflow!");             
                     else
                     {
                       temp = pops();
                       printf("\n%d Deleted!",temp);                       
                     }         
                     fflush(stdin);
                     getchar();                        
                     break;
              case 3:
                     x = s.top;
                     if(s.top!=NULL)
                                       printf("\nStack: ");
                     while(x!=NULL)
                     {
                            printf("%d->",x->info);  
                            x = x->next;
                     }
                     if(s.top==NULL)
                            printf("\nStack Empty!");    
                            fflush(stdin);
                            getchar();                                           
                     
                     break;
              case 4:
                     exit(0);        // returning 0 means successful 
          }
          
   }                 
}

int emptys(void)
{
    if(s.top==NULL)
                 return TRUE;
    else
                 return FALSE;    
}

void pushs(int x)
{
     LINK *p;
     p = getnode();
     p->info = x;
     p->next = s.top;
     s.top = p;   
}

LINK * getnode(void)
{
     LINK *p;
     p = (LINK*)malloc(sizeof(LINK));
     return p;     
}

void freenode(LINK *x)
{
     free(x);    
}

int pops()
{
    int temp;
    LINK *x;
    temp = s.top->info;
    x = s.top->next;      
    freenode(s.top);
    s.top = x;
    return temp;
}







