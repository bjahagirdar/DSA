#include <iostream>

using namespace std;

void quickSort(float[], int, int);

int main()
{
	float percent[100];
	int N;
	cout << "\n Enter the total number of students : ";
	cin >> N;
	cout << "\n Enter the percentages of students : " << endl;
	for(int i=0; i<N; i++)
	{
	    cout << " ";
		cin >> percent[i];
	}

	cout << "\n Student list : " << endl;
	for(int i=0; i<N; i++)
		cout << " " << percent[i] << "\n";

	quickSort(percent, 0, N-1);


	cout << "\n Top scorers are : " << endl;
	for(int i=N-1,c=0; i>=0 && c<5; i--,c++)
		cout << " " << c+1 << ". " << percent[i] << "\n";

	return 0;
}

int partition(float percent[], int low, int end)
{
	float temp;
	float pivot = percent[end];
	int i= (low-1);

	for(int j=low; j<=end-1; j++)
	{
			if(percent[j] <= pivot)
			{
				i++;
				temp = percent[i];
				percent[i] = percent[j];
				percent[j] = temp;

			}
	}
	temp = percent[i+1];
	percent[i+1] = percent[end];
	percent[end] = temp;

	return (i+1);
}

void quickSort(float percent[], int low, int end)
{
	if(low<end)
	{
		int p = partition(percent, low, end);
		quickSort(percent, low, p-1);
		quickSort(percent, p+1, end);
	}
}
