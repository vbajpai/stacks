/* Check Expression Parenthesis using STACK */

#include<stdio.h>
#include<process.h>
#define SIZE 20
enum booleon {
					  FALSE,
					  TRUE
				 }b=TRUE;
struct stack {
							int top;
							char elements[SIZE];
				  }s;
int emptys(struct stack *);
void pushs(struct stack *, char );
char pops(struct stack *);
main()
{
	  int i=0;
	  s.top=-1;
	  char str[SIZE];
	  char temp;
	  printf("Enter String:");
	  gets(str);
	  while(str[i]!='\0')
	  {
				 if(str[i]=='(' || str[i]=='[' || str[i]=='{')
								  pushs(&s,str[i]);

				 else if(str[i]=='}' || str[i]==']' || str[i]==')')
						{
						  if(emptys(&s))
											b=FALSE;
						  else
						  {
							temp = pops(&s);
							switch(temp)
							{
							case '{':  if(str[i]!='}')  b=FALSE;
										  break;
							case '[':  if(str[i]!=']')  b=FALSE;
										  break;
							case '(':  if(str[i]!=')')  b=FALSE;
										  break;
							}
						  }
						}
				 i++;
	  }
	  if(!emptys(&s))
						 b=FALSE;
	  if(b==TRUE)
					 printf("\nExpression Correct!");
	  else
					 printf("\nExpression Incorrect!");
	  fflush(stdin);
	  getchar();
	  return 0;
}
void pushs(struct stack *s,char temp)
{
	  if(s->top==SIZE-1)
	  {
							  printf("Overflow");
							  getchar();
							  exit(1);
	  }
	  else
							  s->elements[++s->top]=temp;

}

char pops(struct stack *s)
{
	  char temp;
	  if(emptys(s))
	  {
						printf("Underflow");
						getchar();
						exit(1);
	  }
	  else
						temp=s->elements[s->top--];
						return temp;
}
int emptys(struct stack *s)
{
	 if(s->top==-1)
						return 1;
	 else
						return 0;
}
