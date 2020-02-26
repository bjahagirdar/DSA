#include <iostream>
#define MAX 50

using namespace std;

class Stack
{
    char stk[MAX];
    int top;

public :
        Stack()
        {
            top = -1;
        }
        bool isEmpty();                                     //check whether the stack is empty or not
        bool isFull();                                      //check whether the stack is full or not
        void push(char exp);                                //push parenthesis into the stack
        char pop();                                         //pop parenthesis into the stack
        void check();                                       //check for proper parenthesis
};

bool Stack :: isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

bool Stack :: isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

void Stack :: push(char exp)
{
    if(!isFull())
    {
        top++;
        stk[top] = exp;
    }
}

char Stack :: pop()
{
    if(!isEmpty())
    {
        char ch = stk[top];
        top--;
        return ch;
    }
    else
    {
        return '\0';
    }
}

void Stack :: check()
{
    cout << "\n Enter @ at the end of the expression. " << endl;

    cout << "\n Enter the expression : ";
    cin.getline(stk, MAX, '@');

    char ch;
	bool flag=0;

	for(int i=0; stk[i]!='\0'; i++)
	{
		if(stk[i]=='(' || stk[i]=='[' || stk[i]=='{')
			push(stk[i]);

		if(stk[i]==')' || stk[i]==']' || stk[i]=='}')
		{
			ch = pop();
			if((stk[i]==')' && ch!='(') || (stk[i]==']' && ch!='[') || (stk[i]=='}' && ch!='{'))
			{
				cout << "\n Not parenthesized at " << i << " = " << stk[i] << endl;
				flag = 1;
				break;
			}
		}
	}

	if(isEmpty() == 1 && flag == 0)
        cout << "\n The expression is well parenthesized. ";
    else
        cout << "\n The expression is not properly parenthesized. ";
}

int main()
{
    char choice;

	do
	{
		Stack s;
		s.check();

		cout << "\n Do you want to continue?[Y/N] \t";
        cin >> choice;

	}while(choice=='y' || choice=='Y');

	cout << "\n --------------------------------------------- ";
	cout << "\n                       END                     ";
    cout << "\n --------------------------------------------- ";

	return 0;
}
