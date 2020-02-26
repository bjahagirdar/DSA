#include<iostream>

using namespace std;
const int MAX=20;

class Student
{
	int roll_no[MAX];
	int n;

public:

	void accept(int num);
	bool linearSearch(int key);
	bool binarySearch(int key);
	int fibo(int j);
	bool fibSearch(int key);
	void display();

};

void Student :: accept(int num)
{
	n = num;
	cout << "\n Enter " << num << " Roll Numbers : \n";
	for(int i=0; i<n; i++)
	{
	    cout << " ";
		cin >> roll_no[i];
	}
}

void Student :: display()
{
	cout << "\n Roll Numbers of students who attended the program : \n";
	for(int i=0; i<n; i++)
	{
		cout << "\t" << roll_no[i];
	}
}

bool Student :: linearSearch(int key)
{
	for(int i=0; i<n; i++)
	{
		if(roll_no[i] == key)
			return true;
	}
	return false;
}

bool Student :: binarySearch(int key)
{
	int mid;
	int low=0;
	int high=n-1;

	while(low <= high)
	{
		mid = (low+high)/2;
		if(key == roll_no[mid])
		{
			return true;
		}
		if(key < roll_no[mid])
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return false;
}

int Student :: fibo(int j)
{
	if(j == 0)
		return 0;
	if(j == 1)
		return 1;
	else
		return ((fibo(j-1))+(fibo(j-2)));
}

bool Student :: fibSearch(int key)
{
	int f1, f2, j, mid;
	j=1;

	while(fibo(j) <= n)
		j++;

	f1 = fibo(j-2);
	f2 = fibo(j-3);
	mid = n-f1+1;

	while(key != roll_no[mid])
	{
		if(key > roll_no[mid])
		{
			if(f1 == 1)
				break;
			mid = mid + f2;
			f1 = f1 - f2;
			f2 = f2 - f1;
		}
		else
		{
			if(f2 == 0)
				break;
			mid = mid - f2;
			int temp = f1 - f2;
			f1 = f2;
			f2 = temp;
		}
	}

	if(roll_no[mid] == key)
		return true;
	else
		return false;
}
int main()
{
	Student s1;
	int choice;
	int key, n;
	do
	{
	    cout << "\n ------------------------------ ";
	    cout << "\n Enter your choice : ";
		cout << "\n 1. Linear Search ";
		cout << "\n 2. Binary Search ";
		cout << "\n 3. Fibonacci Search ";
		cout << "\n 4. Exit ";
		cout << "\n Here : ";
		cin >> choice;

		switch(choice)
		{
            case 1:
                    cout << "\n Enter Number of Students : ";
                    cin >> n;

                    s1.accept(n);

                    cout << "\n Enter Roll Number to Search : ";
                    cin >> key;
                    if(s1.linearSearch(key))
                        cout << "\n Roll no. " << key << " attended Program. ";
                    else
                        cout << "\n Roll no. " << key << " didn't attend Program. ";
                break;

            case 2:
                    cout << "\n Enter Number of Students : ";
                    cin >> n;

                    s1.accept(n);

                    cout << "\n Enter Roll Number to Search : ";
                    cin >> key;

                    if(s1.binarySearch(key))
                        cout << "\n Roll no. " << key << " attended Program. ";
                    else
                        cout << "\n Roll no. " << key << " didn't attend Program. ";
                break;

		case 3:
                    cout << "\n Enter Number of Students : ";
                    cin >> n;

                    s1.accept(n);

                    cout << "\n Enter Roll Number to Search : ";
                    cin >> key;

                    if(s1.fibSearch(key))
                        cout << "\n Roll no. " << key << " attended Program. ";
                    else
                        cout << "\n Roll no. " << key << " didn't attend Program. ";
                break;

        default :
                break;
		}

	}while(choice < 4);

	cout << "\n ---------------------------------------- ";
	cout << "\n                   END                    ";
	cout << "\n ---------------------------------------- ";

	return 0;
}
