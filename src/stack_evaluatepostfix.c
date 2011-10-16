/* WAP to evaluate a Postfix Expression Using Stack */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 20
struct stack {
					  int top;
					  double elements[SIZE];
				 }s;
double oper(char,double,double);
void pushs(struct stack *,double);
double pops(struct stack *);
int isdigits(char);
main()
{
	  s.top=-1;
	  char str[SIZE];
	  int i=0;
	  double val1,val2,result;
	  printf("Enter Postfix Expression:");
	  scanf("%s",str);
	  while(str[i]!='\0')
	  {
				if(isdigits(str[i]))
										 pushs(&s,(double)(str[i]-'0'));
				else
				{
										 val1=pops(&s);
										 val2=pops(&s);
										 result=oper(str[i],val1,val2);
										 pushs(&s,result);
				}
				i++;
	  }
	  result=pops(&s);
	  printf("\n\nResulting Value:%lf",result);
	  fflush(stdin);
	  getchar();
	  return 0;
}

double oper(char temp, double x, double y)
{
		 double result;
		 switch(temp)
		 {
						 case '+':  result=x+y;
										break;
						 case '-':  result=x-y;
										break;
						 case '*':  result=x*y;
										break;
						 case '/':  result=x/y;
										break;
						 case '$':  result=pow(x,y);
		 }
		 return result;
}

int isdigits(char temp)
{
		 if(temp>='0' && temp<='9')
						  return 1;
		 else
						  return 0;
}

void pushs(struct stack *s, double x)
{
	  if(s->top==SIZE-1)
     {
                       printf("Overflow");
							  getchar();
							  exit(1);
     }
	  else
							  s->elements[++s->top]=x;
}

double pops(struct stack *s)
{
		 double temp;
		 if(s->top==-1)
       {
							printf("Underflow");
                     getchar();
                     exit(1);       
		 }
		 temp=s->elements[s->top--];
		 return temp;
}
