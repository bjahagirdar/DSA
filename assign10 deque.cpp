#include<iostream>

using namespace std;

#define SIZE 5

class dequeue
{
	int a[10], front, rear, count;

public:
	dequeue();
	void insert_begin(int);
	void insert_end(int);
	void delete_begin();
	void delete_end();
	void display();
};

dequeue :: dequeue()
{
	front = -1;
	rear  = -1;
	count = 0;
}

void dequeue :: insert_begin(int item)
{
	int  i;
	if(front == -1)
	{
		front++;
		rear++;
		a[rear] = item;
		count++;
	}
	else if(rear >= SIZE-1)
		cout << "\n Insertion is not possible, overflow!!! ";
	else
	{
		for(i=count; i>=0; i--)
		{
			a[i] = a[i-1];
		}
		a[i] = item;
		count++;
		rear++;
	}
}

void dequeue :: insert_end(int item)
{
	if(front == -1)
	{
		front++;
		rear++;
		a[rear] = item;
		count++;
	}
	else if(rear >= SIZE-1)
	{
		cout << "\n Insertion is not possible, overflow!!! ";
		return;
	}
	else
		a[++rear] = item;
}

void dequeue :: display()
{
	for(int i=front; i<=rear; i++)
		cout << a[i] << " ";
}


void dequeue :: delete_begin()
{
	if(front == -1)
	{
		cout << "\n Deletion is not possible. Dequeue is empty. ";
		return;
	}
	else
	{
		if(front == rear)
		{
			front = rear = -1;
			return;
		}
		cout << "\n The deleted element is : " << a[front];
		front = front + 1;
	}
}

void dequeue :: delete_end()
{
	if(front == -1)
	{
		cout << "\n Deletion is not possible. Dequeue is empty. ";
		return;
	}
	else
	{
		if(front == rear)
		{
			front = rear = -1;
		}
		cout << "\n The deleted element is : " << a[rear];
		rear = rear-1;
	}
}

int main()
{
	int c, item;
	dequeue obj;

	do
	{
		cout << "\n\n --------DEQUEUE OPERATION-------- \n";
		cout << "\n 1. Insert at beginning ";
		cout << "\n 2. Insert at end ";
		cout << "\n 3. Deletion from front ";
		cout << "\n 4. Deletion from rear ";
		cout << "\n 5. Display ";
		cout << "\n 6. Exit ";
		cout << "\n Enter your choice : ";
		cin >> c;

		switch(c)
		{
            case 1:
                    cout << "\n Enter the element to be inserted : ";
                    cin >> item;
                    obj.insert_begin(item);
                break;

            case 2:
                    cout << "\n Enter the element to be inserted : ";
                    cin >> item;
                    obj.insert_end(item);
                break;

            case 3:
                    obj.delete_begin();
                break;

            case 4:
                    obj.delete_end();
                break;

			case 5:
                    obj.display();
                break;

            default:
                    cout << "\n Invalid Choice!! ";
                break;
		}

	}while(c<6);

    cout << "\n ------------------------------------------ ";
    cout << "\n                     END                    ";
    cout << "\n ------------------------------------------ ";

	return 0;
}
