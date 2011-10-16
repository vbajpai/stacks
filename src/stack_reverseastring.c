// String Reversal Using Stacks //

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NUL -1
#define TRUE 1
#define FALSE 0

void StrRevStack(char *);
char STACK[50],top=NUL;
void pushs(char *c);
char pops(void);
int emptys(void);
main(void)
{
    char s[50],t[50];
    
    system("cls");
    printf("\n\nString Reversal Using Stacks");
    printf("\n----------------------------\n\n");
	printf("Enter String:");
	gets(s);
	StrRevStack(s);
    printf("\n\nReversed String: %s",s);
    
getch();
}

void StrRevStack(char *a)
{
    int i=0;
    char ch; 
    while(*(a+i)!='\0')
    {
           pushs((a+i));            
           i++;            
    }  
    i = 0;
    while(!emptys())
    {
           ch=pops();        
           *(a+i)=ch;
           i++;
    }
}

void pushs(char *c)
{
      STACK[++top] = *c;                
}

char pops(void)
{
      char ch;
      ch = STACK[top--];
      return (ch);     
}

int emptys(void)
{
      if(top==NUL)
                  return(TRUE);
      else
                  return(FALSE);    
}

