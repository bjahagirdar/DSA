#include <stdio.h>
#include <iostream>
#include <string.h>
#define size 50

using namespace std;

class conversion
{
	char stack[size];
	int tos=0, ele;
	char infix[30], postfix[30];

public :
	void push(int);
	char pop();
	int prec(char);
	void infix_postfix();
	void infix_prefix();
};

void conversion ::  push(int ele)
{
    stack[tos] = ele;
    tos++;
}

char conversion :: pop()
{
    tos--;
    return(stack[tos]);
}

int conversion :: prec(char symbol)
{
	if(symbol== '(')
		return 0;
	if(symbol== ')')
		return 0;
	if(symbol=='+' || symbol=='-')
		return 1;
	if(symbol=='*' || symbol=='/')
		return 2;
	if(symbol=='^')
		return 3;

	return 0;
}

void conversion :: infix_postfix()
{
	int i=0, j=0, length;
	char temp;

	cout << "\n Enter an infix expression : ";
	cin >> infix;
	length = strlen(infix);

	for(i=0; i<length; i++)
	{
		if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!=')' && infix[i]!='(' )
			postfix[j++] = infix[i];
		else
		{
			if(tos == 0)
				push(infix[i]);
			else	//2nd else
			{
				if(infix[i]!=')' && infix[i]!='(')
				{
					if(prec(infix[i]) <= prec(stack[tos-1]))
					{
						temp = pop();
						postfix[j++] = temp;
						push(infix[i]);
					}
					else
						push(infix[i]);
				}
				else	//3rd else
				{
					if(infix[i] == '(')
						push(infix[i]);
					if(infix[i] == ')')
					{
						temp = pop();
						while(temp != '(')
						{
							postfix[j++] = temp;
							temp = pop();
						}
					}
	            }//end of 3rd else
			}//end of 2nd else
		}//end of outer else
	}
	while(tos!=0)
   	{
		postfix[j++] = pop();
    }
    postfix[j++] = '\0';
	cout << " The Postfix expression is : " << postfix;
}

int main()
{
	conversion obj;
	char ch;

	do
	{
		obj.infix_postfix();
		cout << "\n Do you want to continue? [Y/N] : ";
		cin >> ch;

	}while(ch=='y' || ch=='Y');

	cout << "\n ------------------------------------- ";
	cout << "\n                   END                 ";
	cout << "\n ------------------------------------- ";

	return 0;
}
