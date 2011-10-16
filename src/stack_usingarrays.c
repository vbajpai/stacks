/* Stack Implementation Using Array */

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
struct stack {
                 int top;
                 int elements[SIZE];
             }s;
void insert(void);
void del(void);
void disp(void);
int pops(struct stack *);
int stacktop(struct stack *);
int pushs(struct stack *,int);
int main()
{
 int ch;
 s.top = -1;
 while(1)
 {
       system("cls");
       printf("\n\n\nStack Implementation\n\n");
       printf("1. Push Elements\n");
       printf("2. Pop Elements\n");
       printf("3. Display Elements\n");
       printf("4. Exit\n\n");
       printf("Choice:");
       scanf("%d",&ch);
       fflush(stdin);
       switch(ch)
       {
        case 1:  insert();
                 break;
        case 2:  del();
                 break;
        case 3:  disp();
                 break;
        case 4: exit(1);
        default:   printf("Illegal Choice");
                   exit(1);
       }
 }
}
void insert(void)
{
     char ch1='Y';
     int val,x;
     while(ch1=='Y' || ch1=='y')
     {
             printf("\n\nEnter Value for %d:",s.top+1);
             scanf("%d",&val);
             x=pushs(&s,val);
             if(x==-1)
                      break;
             printf("\nEnter More(Y/N):");      
             fflush(stdin);  
             scanf("%c",&ch1);
     }
}

void disp()
{
     int i;
     if(s.top==-1)
                  printf("\nStack Empty");
     else
     {
     printf("\nStack List: ");
     for(i=0;i<=s.top;i++)
                          printf("%d->",s.elements[i]);
     }
     getchar();
}

void del()
{
     char ch='Y';
     int val,val1;     
     while(ch=='Y' || ch=='y')
     {
                   val1=stacktop(&s);
                   if(val1==-1)
                              break;                                             
                   printf("\n\nStack-Top:%d",val1);
                   printf("\nDelete(Y/N)?");
                   scanf("%c",&ch);
                   if(ch=='Y' || ch=='y')
                   {
                            val=pops(&s);
                            printf("\n%d Deleted!",val);
                            printf("\nMore(Y/N):");
                            fflush(stdin);
                            scanf("%c",&ch);
                   }
     }     
}

int stacktop(struct stack *p)
{
    int val;
    if(p->top==-1)
    {
                  printf("\nUnderflow");      
                  getchar();
                  return -1;       
    }
    else
    {    
                  val=p->elements[p->top];
                  return val;
    }
}

int pushs(struct stack *p, int temp)
{
    if(p->top==SIZE-1)
    {
                      printf("\nOverflow"); 
                      fflush(stdin); 
                      getchar();         
                      return -1;       
                                            
    }
    else
                      p->elements[++p->top] = temp;
                      return 1;
                      
}

int pops(struct stack *p)
{
    int val;
    if(p->top==-1)
    {
                  printf("\nUnderflow");                  
    }
    else
                  val=p->elements[p->top--];
                  return val; 
}
