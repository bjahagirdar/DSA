/*Write C++ program to store marks scored for first test of subject ‘Data structure and Algorithm’ for n students compute
    i)Average score of class
    ii)Highest score and lowest score of class.
    iii)marks scored by most of the students.
    iv)list of students who were absent for the test.
*/

#include <iostream>
#include <cstring>

using namespace std;

class student
{

	char div;
	int rollno;

	public:	string name;
			int marks, n;
			char a;
			void read()
			{
				cout << "\n Enter your name : ";
				cin >> name;

				cout << "\n Enter your roll number : ";
				cin >> rollno;

				cout << "\n Enter your division : ";
				cin >> div;

				cout << "\n Attendance";
				cout << "\n Enter p for present and a for absent : ";
				cin >> a;

				if(a == 'p')
				{	cout << "\n Enter your marks : ";
					cin >> marks;
				}
				else
					marks = -1;
			}

			void display()
			{
				cout << rollno << "\t" << name << "\t\t\t" << div << "\t\t" << a << "\t\t" << marks << "\n";
			}

			void absent()
			{
				if(a == 'a')
					cout << "\t\t" << name << "\n";
			}
};

int main()
{
	int i, n, ch, sum=0, d=0, min=1000, max=0;
	float avg;
	char x;
	student s[10];

	cout << "\n Enter number of students : ";
	cin >> n;

	for(i=0; i<n; i++)
		s[i].read();

	do
	{
		cout << "\nEnter your choice "
				"\n1 for display"
				"\n2 for average"
				"\n3 for maximum marks"
				"\n4 for minimum marks"
				"\n5 for list of absent students"
				"\n6 for most occuring marks"
				"\n Here :\t";
		cin >> ch;

		if(ch<7)
		{
		    switch(ch)
			{
			case 1:	cout << "Rollno\tName of Students\tDivision\tAttendance\tMarks\n";
					for(i=0; i<n; i++)
						s[i].display();
				break;
			case 2:for(i=0; i<n; i++)
					{
						if(s[i].a == 'p')
						{
							sum = sum+s[i].marks;
							d++;
						}
					}
					avg = sum/d;
					cout << "\nSum = " << sum << "\n" << "Average = " << avg << endl;
				break;
			case 3:	for(i=0; i<n; i++)
					{
						if(max < s[i].marks)
							max = s[i].marks;
					}
					cout << "\n Maximum=" << max << endl;
				break;
			case 4:	for(i=0; i<n; i++)
					{
						if(s[i].a == 'p')
						{
							if(min > s[i].marks)
								min = s[i].marks;
						}
					}
					cout << "\n Minimum=" << min << endl;
				break;
			case 5:	cout << "\n List of absent students :\n";
				for(i=0; i<n; i++)
				{
					s[i].absent();
				}
				break;
			case 6:
				int max_count = 0;

				for (int i=0; i<n; i++)
				{
   					int count=1;
					if(s[i].a == 'p')
                    {
                        for (int j=i+1; j<n; j++)
                            if (s[i].marks == s[j].marks)
                                count++;
                        if (count > max_count)
      						max_count = count;
                    }
				}

				for (int i=0; i<n; i++)
				{
   				 	int count=1;

					if(s[i].a == 'p')
   					{
   					    for (int j=i+1; j<n; j++)
       						if (s[i].marks == s[j].marks)
           						count++;
                        if (count == max_count)
      			 			cout << "\n" << s[i].marks << "\n" << count << endl;
                    }
				}
				break;
			}
		}
		else
			cout << "\n Invalid selection";

		cout << "\n If u want to continue press y or n \t";
		cin >> x;

	}while(x=='y' || x=='Y');

	cout << "\n **************************************** ";
	cout << "\n End";
    cout << "\n **************************************** ";

	return 0;
}