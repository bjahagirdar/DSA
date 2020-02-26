#include <iostream>

using namespace std;

struct node                                         //creating a node
{
	bool bit;                                       //boolean data type to store bits
	node *next, *prev;
};

class binary
{
	int n;

public:
		node *start, *last;

		node *create_binary();                      //creating doubly linked list
		void ones_comp();                           //calculate one's complement
		void twos_comp();                           //calculate two's complement
		void addition();                            //adding two binary numbers
		void display(node *a);                      //displaying binary number
};

node *binary :: create_binary()
{
	start = NULL;

	node *temp, *new_node;

	cout << "\n Enter number of bits : ";
	cin >> n;
	cout << "\n Enter the binary number : ";
	for(int i=0; i<n; i++)
	{
		new_node = new node;
		cin >> new_node->bit;
		new_node->next = NULL;
		new_node->prev = NULL;

		if(start == NULL)
		{
			start = new_node;
			last = new_node;
		}
		else
		{
			temp = start;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
			last = new_node;
		}
		cout << "\t\t\t";
	}
	return start;
}

void binary :: ones_comp()
{
	node *temp;
	temp = start;

	while(temp != NULL)
	{
		if(temp->bit == 0)
			cout << 1;
		else
			cout << 0;

		temp = temp->next;
	}
}

void binary :: twos_comp()
{
	node *temp, *t, *x;
	bool flag = 0;
	temp = t = last;

	while(temp != NULL)
	{
		if(flag == 0)
		{
			if(temp->bit == 0)
				t->bit = 0;
			else
			{
				t->bit = 1;
				flag  =1;
			}
		}
		else
		{
			if(temp->bit == 0)
				t->bit = 1;
			else
				t->bit = 0;
		}

		x=t;
		t = t->prev;
		temp = temp->prev;
	}

	display(x);
}

void binary :: addition()
{
    node *start1,*start2;
    node *l1,*l2;

    cout << "\n\n Binary number 1 " << endl;
    start1 = create_binary();
    l1 = last;
    cout << "\n\n Binary number 2 " << endl;
    start2 = create_binary();
    l2 = last;

    cout << "\n Number 1 : ";
    display(start1);
    cout << endl;
    cout << "\n Number 2 : ";
    display(start2);
    cout << endl;

    cout << "\n Addition is : ";

    int a[20], p=0, carry=0;

    while(l1!=NULL && l2!=NULL)
    {
        if(l1->bit==l2->bit && l1->bit==0)
        {
            a[p] = 0 + carry;
            p++;
            carry = 0;
        }
        else if(l1->bit==l2->bit && l1->bit==1)
        {
            a[p] = 0 + carry;
            p++;
            carry = 1;
        }
        else if(l1->bit != l2->bit)
        {
            if(carry == 1)
            {
                a[p] = 0;
                p++;
            }
            else
            {
                a[p] = 1;
                p++;
            }
        }
        l1 = l1->prev;
        l2 = l2->prev;
    }
    while(l1 != NULL)
    {
        if(carry == 0)
        {
            a[p] = l1->bit;
            p++;
        }
        else if(l1->bit==1 && carry==1)
        {
            a[p] = 0;
            p++;
        }
        else if(l1->bit==0 && carry==1)
        {
            a[p] = 1;
            p++;
            carry=0;
        }
        l1 = l1->prev;
    }
    while(l2 != NULL)
    {
        if(carry == 0)
        {
            a[p] = l2->bit;
            p++;
        }
        else if(l2->bit==1 && carry==1)
        {
            a[p] = 0;
            p++;
        }
        else if(l2->bit==0 && carry==1)
        {
            a[p] = 1;
            p++;
            carry=0;
        }
        l2 = l2->prev;
    }
    if(carry == 1)
    {
        a[p] = carry;
        p++;
    }
    for(int i=p-1; i>=0; i--)
        cout << a[i];
}

void binary :: display(node *a)
{
	node *temp;
	temp = a;

	while(temp != NULL)
	{
		cout << temp->bit;
		temp = temp->next;
	}
}

int main()
{
    char x;
    int ch;
	node *p;
	binary obj;

	do
    {
        cout << "\n Enter your choice ";
        cout << "\n 1. One's Complement of binary number ";
        cout << "\n 2. Two's Complement of binary number ";
        cout << "\n 3. Addition of two binary numbers ";
        cout << "\n Here : ";
        cin >> ch;

        switch(ch)
        {
            case 1: obj.create_binary();
                    p = obj.start;
                    cout << "\n Binary Number : ";
                    obj.display(p);
                    cout << "\n One's complement of the number is : ";
                    obj.ones_comp();
                break;

            case 2: obj.create_binary();
                    p = obj.start;
                    cout << "\n Binary Number : ";
                    obj.display(p);
                    cout << "\n Two's complement of the number is : ";
                    obj.twos_comp();
                break;

            case 3: obj.addition();
                break;
        }

        cout << "\n Do you want to continue? [Y/N] \t";
        cin >> x;

    }while (x=='y' || x=='Y');

    cout << "\n --------------------------------------------- ";
    cout << "\n                      END                      ";
    cout << "\n --------------------------------------------- ";

	return 0;
}
