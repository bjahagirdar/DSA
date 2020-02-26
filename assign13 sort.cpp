#include <iostream>

using namespace std;

class FE
{
	float percent[100];
	int N;

public :
		void accept();
		void display();
		void selection_sort();
		void bubble_sort();
};

void FE :: accept()
{
	cout << "\n Enter the total number of students : ";
	cin >> N;
	cout << "\n Enter the percentages of students : ";
	for(int i=0; i<N; i++)
	{
	    cout << " ";
		cin >> percent[i];
	}
}

void FE :: selection_sort()
{
	float temp;
	int min;

	for(int i=0; i<N+1; i++)
	{
		min = i;
		for(int j=i+1; j<N; j++)
		{
			if(percent[min]>percent[j])
				min = j;
		}
		temp = percent[min];
		percent[min] = percent[i];
		percent[i] = temp;
	}
	display();
}

void FE :: bubble_sort()
{
	float temp;

	for(int i=0; i<N-1; i++)
	{
		for(int j=0; j<N-i-1; j++)
	    {
			if(percent[j] > percent[j+1])
			{
				temp = percent[j];
				percent[j] = percent[j+1];
				percent[j+1] = temp;
			}
	    }
	}
	display();
}

void FE :: display()
{
	int c;
	cout << "\n The top scorers are : " << endl;
	for(int i=N-1,c=0; i>=0 && c<5; i--,c++)
		cout << " " << c+1 << ". " << percent[i] << endl;
}

int main()
{
	FE obj;
	int ch=0;

	while(ch < 4)
	{
		cout << "\n ------------------------------------- ";
		cout << "\n Enter your choice : "
				"\n 1. Accept percentage "
				"\n 2. Selection sort "
				"\n 3. Bubble sort "
				"\n 4. Exit "
				"\n Here : ";
		cin >> ch;
		switch(ch)
		{
			case 1 : obj.accept();
				break;

			case 2 : cout << "\n -----------Selection Sort----------- ";
					 obj.selection_sort();
				break;

			case 3 : cout << "\n -------------Bubble Sort------------- ";
					 obj.bubble_sort();
				break;

			default : cout << "\n ------------------------------------- ";
					  cout << "\n                  END                  ";
					  cout << "\n ------------------------------------- ";
				break;
		}

	}

	return 0;
}
