/* Multiple Stack Implementation In One Array */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 10
struct stack {
                 int top1;
                 int top2;
                 int count;
                 int elements[SIZE];
             }s;
void insert(int);
void del(int);
void disp(void);
int pops(struct stack *,int);
int stacktop(struct stack *,int);
int pushs(struct stack *,int,int);
int main()
{
 int ch;
 s.top1 = -1;
 s.top2 = SIZE;
 s.count=0;
 while(1)
 {
       system("cls");
       printf("\n\nMultiple Stack Implementation In One Array\n");
       printf("------------------------------------------\n\n");
       printf("Array Size: 10\n\n");
       printf("1. Push Elements\n");
       printf("2. Pop Elements\n");
       printf("3. Display Elements\n");
       printf("4. Exit\n\n");
       printf("Choice:");
       scanf("%d",&ch);
       fflush(stdin);
       switch(ch)
       {
        case 1:  
                 if(s.count>=SIZE)
                 {
                          printf("\nOverflow");                           
                          getch();               
                          break;                 
                 }
                 printf("\n\n1. Stack1");
                 printf("\n2. Stack2");
                 printf("\n\nChoice:");
                 scanf("%d",&ch);
                 if(ch!=1 && ch!=2)
                 {
                          printf("\nInvalid Choice!");
                          getch();
                          break;
                 }
                 insert(ch);
                 break;
        case 2:  
                 printf("\n\n1. Stack1");
                 printf("\n2. Stack2");
                 printf("\n\nChoice:");
                 scanf("%d",&ch);
                 if(ch!=1 && ch!=2)
                 {
                          printf("\nInvalid Choice!");
                          getch();
                          break;
                 }
                 del(ch);
                 break;
        case 3:  disp();
                 break;
        case 4: exit(1);
        default:   printf("Illegal Choice");
                   exit(1);
       }
 }
}
void insert(int ch)
{
             int val,x;     
             if(ch==1)
                      printf("\n\nEnter Value for %d:",s.top1+1);
             else
                      printf("\n\nEnter Value for %d:",s.top2-1);
                                            
             scanf("%d",&val);
             pushs(&s,val,ch);                      
}

void disp(void)
{
     int i;
     if(s.top1==-1)
                  printf("\nStack 1 Empty!");
     else
     {
                  printf("\nStack 1: ");
                  for(i=0;i<=s.top1;i++)
                          printf("%d->",s.elements[i]);
     }
     if(s.top2==SIZE)
                  printf("\nStack 2 Empty!");     
     else
     {
                  printf("\nStack 2: ");
                  for(i=SIZE-1;i>=s.top2;i--)
                          printf("%d->",s.elements[i]);
     }     
     getchar();
}

void del(int ch)
{
                   char ch1;
                   int val,val1;         
                   val1=stacktop(&s,ch);
                   if(val1==-1)
                              return;                                             
                   printf("\n\nStack-Top:%d",val1);
                   printf("\nDelete(Y/N)?");
                   fflush(stdin);
                   scanf("%c",&ch1);
                   if(ch1=='Y' || ch1=='y')
                   {
                            val=pops(&s,ch);
                            printf("\n%d Deleted!",val);
                            getch();                    
                   }
        
}

int stacktop(struct stack *p,int ch)
{
    int val;
    if(ch==2)
    {
             if(s.top2==SIZE)
             {
                  printf("\nUnderflow");      
                  getch();
                  return -1;                         
             }
    }
    else
    {
            if(s.top1==-1)
             {
                  printf("\nUnderflow");      
                  getch();
                  return -1;                         
             }
    }       
         if(ch==1)
                  val=p->elements[p->top1];
         else
                  val=p->elements[p->top2];
         return val;
    
}

int pushs(struct stack *p, int temp,int ch)
{
    
            s.count++;
            if(ch==1)
                  p->elements[++p->top1] = temp;
            else
                  p->elements[--p->top2] = temp;
                                                
}

int pops(struct stack *p,int ch)
{
    int val;
        if(ch==1)
                  val=p->elements[p->top1--];
        else
                  val=p->elements[p->top2++];
        s.count--;
                  return val; 
}
