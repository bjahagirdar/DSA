#include <iostream>

using namespace std;

class string_opt
{
	char s1[100], s2[100], s3[100];
	int i, j;
	int n, m;

public:
        string_opt()                                    //default constructor
        {
            n = m = 0;
        }

        void str_read();                                //to read a string from user
		int str_length();                               //to find the length of string s1
		void str_copy();                                //to copy the string s1 to s3
		void str_reverse();                             //for reversing the string s1
		void str_cat();                                 //to concatenate the strings s1 & s2 into s3
		void str_comp();                                //to compare the strings s1 & s2
		void str_freq();                                //to calculate the frequency of each letter in s1
		void str_apla();                                //to eliminate the alpha numeric values from s1
};

void string_opt :: str_read()
{
    cout << "\n Enter string : ";
    cin.getline(s1, 100);
}

int string_opt ::str_length()
{
    n=0;
    for(i=0; s1[i]!='\0'; i++)
    {
        n++;
    }
    return n;
}

void string_opt :: str_copy()
{
    for(i=0; s1[i]!='\0'; i++)
        s3[i] = s1[i];
    s3[i] = '\0';

    cout << "\n Copied string is : " << s3;
}

void string_opt :: str_reverse()
{
    str_length();
    j = n;

    for(i=0; s1[i]!='\0'; i++,j--)
    {
        s3[j-1] = s1[i];
    }
    s3[i] = '\0';

    cout << "\n Reversed string of string : " << s3;
}

void string_opt :: str_comp()
{
    int flag;
    cout << "\n Enter a string to be compared : ";
    cin >> s2;

    int m=0;
    for(i=0; s2[i]!='\0'; i++)
    {
        m++;
    }

    if(n > m)
    {
        for(i=0, flag=0; s1[i]!='\0'; i++)
        {
            if(s1[i] == s2[i])
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            cout << "\n The strings are same";
        else
            cout << "\n The strings are not same";
    }
    else
    {
        for(i=0, flag=0; s2[i]!='\0'; i++)
        {
            if(s1[i] == s2[i])
                flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            cout << "\n The strings are same";
        else
            cout << "\n The strings are not same";
    }
}

void string_opt :: str_cat()
{
    for(i=0,j=0; s1[i]!='\0'; i++,j++)
    {
        s3[j] = s1[i];
    }

    cout << "\n Enter a string to concatenate : ";
    cin >> s2;

    for(i=0; s2[i]!='\0'; i++,j++)
    {
        s3[j] = s2[i];
    }
    s3[j] = '\0';
    cout << "\n Concatenated string : " << s3;
}

void string_opt :: str_freq()
{
    int count[256] = {0};
    for(i=0; s1[i] != '\0'; i++)
    {
        count[s1[i]]++;
    }

    cout << "\nCharacter   Frequency\n";
    for(i=0; i < 256; i++)
    {
        if(count[i] != 0)
        {
            cout <<"  " << (char)i << "         " << count[i]<< endl;
        }
    }
}

void string_opt :: str_apla()
{
    j = 0;
    char alphabetString[100];                   //for storing s1 without alpha-numeric character
    cout << "\n Original string : " << s1;

    for(int i = 0; s1[i] != '\0'; ++i)
    {
        if ((s1[i] >= 'a' && s1[i]<='z') || (s1[i] >= 'A' && s1[i]<='Z'))
        {
            alphabetString[j++] = s1[i];
        }
    }
    alphabetString[j] = '\0';

    cout << "\n String without alpha-numeric characters : " << alphabetString;
}

int main()
{
	string_opt obj;                                     //creating object of class string_opt
	int ch;
	int m;
	char x;

	obj.str_read();

	do                                                  //do while loop to continue the operations
	{
	    cout << "\n ------------------------------------------------------------";
		cout << "\n Enter your choice "
				"\n 1 to find the length of the string "
				"\n 2 to copy the string "
				"\n 3 to reverse the string "
				"\n 4 to concatenate two strings "
				"\n 5 to compare the string "
				"\n 6 to find the frequency of each letter in string "
				"\n 7 to eliminate the alpha numeric characters from the string "
				"\n Here : ";
		cin >> ch;
        cout << "\n ------------------------------------------------------------";

		switch(ch)                                      //switch case for menu driven program
		{
			case 1:	m = obj.str_length();
                    cout << "\n Length of string : " << m;
				break;

			case 2:	obj.str_copy();
				break;

			case 3:	obj.str_reverse();
				break;

			case 4: obj.str_cat();
				break;

			case 5:	obj.str_comp();
				break;

			case 6:	obj.str_freq();
				break;

            case 7: obj.str_apla();
                break;

		}
        cout << "\n ------------------------------------------------------------";
		cout << "\n Do you want to continue? [Y/N]\t";
		cin >> x;

	} while(x == 'y' || x == 'Y');
	cout << "\n ------------------------------------------------------------";
	cout << "\n                            END                              ";
    cout << "\n ------------------------------------------------------------";

	return 0;
}
