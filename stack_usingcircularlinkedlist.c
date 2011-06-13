// Stack Implementation Using Circular Linked List //

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct link {
                              int info;
                              struct link *next;
                    }LINK; 
LINK *stack;
void pushs(int x);
int emptys(void);
LINK * getnode(void);
void freenode(LINK *);
int pops();
main(void)
{
   int ch,e,temp=0,end=FALSE;
   LINK *x;
   stack=NULL;
   while(1)
   {
          system("cls"); 
          printf("\n\n\nStack Implementation Using Circular Linked List\n\n");
          printf("1. Insert Elements\n");
          printf("2. Delete Elements\n");
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
                     {
                                printf("\nUnderflow!");
                                fflush(stdin);
                                getchar();  
                     }
                     else
                     {
                        printf("\nStack Top: %d",(stack->next)->info);
                        printf("\n\nDelete(Y/N)?");
                        fflush(stdin);
                        scanf("%c",&ch);
                        if(ch=='Y' || ch=='y')
                        {
                                   temp = pops();
                                   printf("\n%d Deleted Successfully!",temp);
                        }
                        fflush(stdin);
                        getchar();      
                        
                     }          
                     
                     break;
              case 3:
                     x = stack;
                     if(x!=NULL)
                                       printf("\nStack:");
                     while(end==FALSE && x!=NULL)
                     {
                            x = x->next;          
                            printf("%d->",x->info);                              
                            if(x==stack)
                                       end = TRUE;
                     }
                     end = FALSE;
                     if(stack==NULL)
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
    if(stack==NULL)
                 return TRUE;
    else
                 return FALSE;    
}

void pushs(int x)
{
     LINK *p;
     p = getnode();
     p->info = x;
     if(emptys())
     {
            p->next = p;
            stack = p; 
     }
     else
     {     
           p->next = stack->next;
           stack->next = p;
     }
      
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
    x = stack->next;    // first node
    temp = x->info;   
    stack->next = x->next;           
    if(stack==x)                     // Single Node Deleted 
               stack = NULL;
    freenode(x);
    return temp;
}







