// Program to Convert Infix Expression to Prefix Expression Using Stack //

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 20
#define FALSE 0
#define TRUE 1


struct stack {
					int top;
					char elements[SIZE];
             }s;
				 
int isdigits(char);
void popandtests(struct stack *, char *,int *);
int emptys(struct stack *);
void pushs(struct stack *, char);
char pops(struct stack *);
int prcd(char, char);

main()
{
	  char infix[SIZE],postfix[SIZE],top;
	  int i=0,j=0,und=FALSE;
	  s.top=-1;
	  
	  printf("\n\nInfix -> Prefix Implementation \n");
	  printf("------------------------------- \n\n");
	  printf("Enter Infix Expression:");
	  scanf("%s",infix);
	  strrev(infix);
	  
	  while(infix[i]!='\0')
	  {
				 if(isdigits(infix[i]))
										  postfix[j++]=infix[i];
				 else
				 {
					  popandtests(&s,&top,&und);
					  
					  while(!und && prcd(top,infix[i]))
					  {
										 postfix[j++]=top;
										 popandtests(&s,&top,&und);
					  }
					  
					  if(!und)
										 pushs(&s,top);
					  if(und || infix[i]!='(')
                               pushs(&s,infix[i]);
					  else
										 top=pops(&s);
				 }
				 i++;
	  }
	  while(!emptys(&s))
	  {
							  top=pops(&s);
							  postfix[j++] = top;
	  }
							  postfix[j]='\0';
	  strrev(postfix);
	  printf("\n\nPrefix Expression:%s",postfix);	 
	  getch();
	  return 0;
}

int isdigits(char temp)
{
	 if(temp > '0' && temp <'9')
                return TRUE;
	 else
                return FALSE;    
}

void popandtests(struct stack *s, char *top,int *und)
{
	  if(emptys(s))
                 *und=TRUE;
	  else
      {
				*und=FALSE;
                 *top=s->elements[s->top--];                 
	  }
     
}

int emptys(struct stack *s)
{
	  if(s->top==-1)
                   return TRUE;
	  else
                   return FALSE;
}

void pushs(struct stack *s, char temp)
{
			 if(s->top==SIZE-1)
             {
									 printf("Overflow");
									 getch();
								//	 exit(1);
			 }
			 else
				  s->elements[++s->top]=temp;
}

char pops(struct stack *s)
{
	  if(emptys(s))
	  {
						printf("Underflow");
						getchar();
				//		exit(1);
     }
	  else
                  return (s->elements[s->top--]);  
}

int prcd(char val1,char val2)
{
	 switch(val1)
    {
	  case '+':
                if(val2=='+' || val2=='-')
									  return TRUE;
                             break;
	  case '-':
                if(val2=='+' || val2=='-')
									  return TRUE;
                             break;
	  case '*':
                if(val2=='+' || val2=='-' || val2=='*' || val2=='/')
									  return TRUE;
                             break; 
	  case '/':
                if(val2=='+' || val2=='-' || val2=='*' || val2=='/')
									  return TRUE;
                             break; 
	  case '$':
                if(val2=='+' || val2=='-' || val2=='*' || val2=='/' || val2=='$')
									  return TRUE;
									  break;
	  case ')':        return FALSE;
	                   break;
     }
     
     if(val2=='(')
                  return TRUE;
     else if(val2==')')
                  return FALSE;     
                  

     return FALSE;

}
