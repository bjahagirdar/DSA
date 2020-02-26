#include <iostream>
#include <cstring>

using namespace std;

class Student
{
	int N;
	int roll[20];
	string name[20];

public:
	void accept();                              //Function to accept no. of students
	int funion(Student, Student);               //Function to find union
    void intersect(Student, Student);           //Function to find intersection
    void diff(Student, Student);                //Function to find difference
    void display();                             //Function to display result
};

void Student :: accept()
{
	cout << "\n Enter total no of students : ";
	cin >> N;

	for(int i=0; i<N; i++)
	{
		cout << "\n Enter name of student : ";
		cin >> name[i];
		cout << " Enter roll no. : ";
		cin >> roll[i];
	}

}

int Student :: funion(Student a, Student b)
{
    int index = a.N;
    int flag;
    int i, j;

    cout << "{ ";
	for(i=0; i<a.N; i++)
	{
		name[i] = a.name[i];
		roll[i] = a.roll[i];
		cout << name[i] << "-" << roll[i] << " ";
	}

	for(i=0; i<b.N; i++)
	{
	    flag = 0;
		for(j=0; j<a.N; j++)
		{
			if(b.roll[i] == a.roll[j])
			{
				flag=1;
				break;
			}
        }

		if(flag == 0)
        {
            roll[index] = b.roll[i];
            name[index] = b.name[i];
            cout << name[index] << "-" << roll[index] << " ";
            index++;
        }
    }
       cout << "}" << endl;

       return index;
}

void Student :: intersect(Student a, Student b)
{
    int i, j, k;
    k=0;
    cout << "{ ";
    for(i=0; i<a.N; i++)
    {
        for(j=0; j<b.N; j++)
        {
            if(a.roll[i] == b.roll[j])
            {
                roll[k] = a.roll[i];
                name[k] = a.name[i];
                cout << name[k] << "-" << roll[k] << " ";
                k++;
            }
        }
    }
    cout << "}" << endl;
}

void Student :: diff(Student a, Student b)
{
    int i, j, k, diff, flag;
    k=0;
    flag=0;

    cout << "{ ";
    for(i=0; i<a.N; i++)
    {
        flag=0;

        for(j=0; j<b.N; j++)
        {
            if(a.roll[i] == b.roll[j])
            {
                flag=1;
                break;
            }
        }

        if(flag == 0)
        {
            roll[k] = a.roll[i];
            name[k] = a.name[i];
            cout << name[k] << "-" << roll[k] << " ";
            k++;
        }
    }
    cout << "}" << endl;
}

int main()
{
    Student cricket_obj, badmin_obj, union_obj, inter_obj, diff_obj;
    int m=0;
    int n=0;

    cout << "\n Enter total number of students in SE COMP : ";
    cin >> n;

    cout << "\n Enter student details who play cricket : ";
    cricket_obj.accept();

    cout << "\n Enter student details who play badminton : ";
    badmin_obj.accept();

    cout << "\n List of students who play cricket or badminton are : ";
    m = union_obj.funion(cricket_obj, badmin_obj);

    cout << "\n List of students who play both cricket and badminton are : ";
    inter_obj.intersect(cricket_obj, badmin_obj);

    cout << "\n List of students who play only cricket are : ";
    diff_obj.diff(cricket_obj, badmin_obj);

    cout << "\n List of students who play only badminton are : ";
    diff_obj.diff(badmin_obj, cricket_obj);

    cout << "\n Number of students who play neither cricket nor badminton are : " << n-m;

    return 0;
}
