
#include <iostream>
#define MAX 10

using namespace std;

class queue
{
	int q[MAX];
	int front, rear;
public :
		queue()
		{
			front = -1;
			rear = -1;
		}
		bool accept(int n);
		void ready();
		void display();
};

bool queue :: accept(int n)
{
	if(rear == -1)
	{
		front = rear = 0;
		q[rear] = n;
		return true;
	}
	else
	{
		int pos;
		pos = (rear + 1) % MAX;
		if(pos == front)
		{
			cout << "\n The Parlor is full ";
			return false;
		}
		else
		{
			rear = pos;
			q[rear] = n;
			return true;
		}
	}
}

void queue :: ready()
{
	if(front == -1)
	{
		cout << "\n Parlor is full ";
	}
	else
	{
		cout << "\n Order No. " << q[front] << " is processed. " << endl;
		if(front == rear)
			front = rear = -1;
		else
			front = (front+1) % MAX;
	}
}

void queue :: display()
{
	int i=0;
	if(front == -1)
 	{
	 	cout<<"\n No orders yet. " << endl;
		return;
	}
	else
	{
		cout << " Order Id's : " << endl;
		for(i=front; i!=rear; i=((i+1)%MAX))
	 	{
			cout << " " << q[i] << "  ";
	 	}
		cout << q[rear];
	}
}

int main()
{
	queue obj;
	int n=0, x;
	char ch;

	cout << "\n Welcome to the Pizza Parlor ";
	while(x!=4)
	{
		cout << "\n --------------------------------------------- ";
		cout << "\n Enter your choice "
				"\n 1. Accept the order "
				"\n 2. Serve the order "
				"\n 3. Display "
				"\n 4. Exit "
				"\n Here : ";
		cin >> x;

		switch(x)
		{
			case 1 :	n++;
						if(obj.accept(n))
							cout << " Thank you for order. Order id is : " << n << endl;
						else
						{
							cout << "\n Please wait ";
							n--;
						}
				break;

			case 2 :	obj.ready();
				break;

			case 3 :	obj.display();
				break;
		}
	}

	cout << "\n Thank you for visiting " << endl;

	return 0;
}
