// Stack Implementation Using Linked List Which Is Implemented Using Arrays //

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
#define NUL -1
#define TRUE 1
#define FALSE 0
typedef struct linklist {
                         int info;
                         int next;
                        }LINK;
struct stack {
                        int top; 
             }s;
LINK l[SIZE]; 
int avail=0;
void pushs(struct stack *,int);
void freenode(int);
int getnode(void);
int pops(struct stack *);
main(void)
{
      s.top=NUL;
      int ch,e,ch1,x;
      int i;
      // Initialising the pool of available nodes //
      for(i=0;i<SIZE-1;i++)
                     l[i].next=i+1;
      l[SIZE-1].next=NUL;
      while(1)
      {
              system("cls");
              printf("\n\nStack Implementation Using Linked List Implemented Using Array\n\n\n");       
              printf("1. Push Elements\n");
              printf("2. Pop Elements\n");
              printf("3. Display Elements\n");
              printf("4. Exit\n\n");
              printf("Enter Choice:");
              scanf("%d",&ch);
              switch(ch)
              {
               case 1:
                        printf("\n\nEnter Element:");
                        scanf("%d",&e);
                        pushs(&s,e);                                                          
                        break;
               case 2:
                        x=s.top;
                        if(x==NUL)
                        {
                                     printf("\nUnderflow!");
                                     fflush(stdin);
                                     getchar();
                        }
                        else
                        {
                         printf("\nStack Top: %d",l[s.top].info);
                                    x = pops(&s);
                                    printf("\n\n%d Deleted!",x);
                                    fflush(stdin);
                                    getchar();
                         
                        }
                        break;
               case 3:
                        x=s.top;
                        if(x!=NUL)
                        {
                              printf("\nStack: ");
                              while(x!=NUL)
                               {
                                    printf("%d->",l[x].info);
                                    x = l[x].next;
                               }
                        }
                        else
                               printf("\nStack Empty");
                         fflush(stdin);
                         getchar();
                        break;
               case 4:
                        exit(1);                              
              }            
      }          
}

void pushs(struct stack *s,int e)                            
{
          int p;
          p=getnode();
          if(p!=NUL)
          {
           l[p].info=e;
           l[p].next=s->top;
           s->top=p;          
          }     
}

int getnode()
{
           int p;  
           if(avail==NUL)
           {
                         printf("\nOverflow!");    
                         fflush(stdin);
                         getchar();
                         return NUL;
           }
           else
           {
                         p = avail;
                         avail=l[avail].next;                        
                         return p;    
           }
                                       
}

void freenode(int x)
{
  l[x].next=avail;
  avail=x;     
}

int pops(struct stack *x)
{
    int temp;
    int temp2=x->top;
    temp = l[x->top].info;
    x->top = l[x->top].next;    
    freenode(temp2);
    return temp;   
}

