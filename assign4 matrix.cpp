/*To write a C++ program for sparse matrix realization and operations on it- Transpose,
                    Fast Transpose and addition of two matrices.                       */

#include <iostream>

using namespace std;

class matrix
{
	int r, c, a[10][10], b[10][3], st[10][3], ft[10][3];
	int i, j, k=0, count=0;

public:
	void readmatrix()								//get rows, columns and elements of matrix
	{
		cout << "\n Enter number of rows:\t";
		cin >> r;

		cout << "\n Enter number of columns:";
		cin >> c;

		cout << "\n Enter elements of matrix:\n";
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cout << "\t";
				cin >> a[i][j];
			}
		}
	}

	void sparse_represent()							//to convert into 3 column form
	{

		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				if(a[i][j] != 0)
					count++;
			}
		}

		b[0][0] = r;
		b[0][1] = c;
		b[0][2] = count;
		k=1;

		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				if(a[i][j] != 0)
				{
					b[k][0] = i;
					b[k][1] = j;
					b[k][2] = a[i][j];
					k++;
				}
			}
		}

	}

	void simple_transpose()							//to calculate simple transpose
	{
		st[0][0] = b[0][1];
		st[0][1] = b[0][0];
		st[0][2] = b[0][2];
		k=1;

		for(i=0; i<c; i++)
		{
			for(j=1; j<=count; j++)
			{
				if(b[j][1] == i)
				{
					st[k][0] = b[j][1];
					st[k][1] = b[j][0];
					st[k][2] = b[j][2];
					k++;
				}
			}
		}

		for(i=0; i<=count; i++)
		{
			cout << st[i][0] << "\t" << st[i][1] << "\t" << st[i][2] << "\n";
		}
	}

	void fast_transpose()							//to calculate fast transpose
	{
		ft[0][0] = b[0][1];
		ft[0][1] = b[0][0];
		ft[0][2] = b[0][2];

		int terms[10],rpos[10];

		for(i=0; i<c; i++)
			terms[i] = 0;

		for(i=1; i<count; i++)
			terms[b[i][1]]++;

		rpos[0] = 1;

		for(i=1; i<=c; i++)
			rpos[i] = rpos[i-1] + terms[i-1];

		for(i=1; i<=count; i++)
		{
			j = rpos[b[i][1]];
			ft[j][0] = b[i][1];
			ft[j][1] = b[i][0];
			ft[j][2] = b[i][2];
			rpos[b[i][1]]++;
		}

		for(i=0; i<=count; i++)
		{
			cout << ft[i][0] << "\t" << ft[i][1] << "\t" << ft[i][2] << "\n";
		}
	}

	void addition(matrix m1 , matrix m2)				//to add two sparse matrices
	{
		b[0][0] = m1.r;
        b[0][1] = m1.c;
	    i=1;
	    j=1;
	    k=1;

	    while(i<=m1.count && j<=m2.count)
		{
			if(m1.b[i][0] == m2.b[j][0])
			{
				if(m1.b[i][1] == m2.b[j][1])
				{
					b[k][0] = m1.b[i][0];
					b[k][1] = m1.b[i][1];
					b[k][2] = m1.b[i][2] + m2.b[j][2];
					i++;
					j++;
					k++;
				}
				else
				{
					if(m1.b[i][1] < m2.b[j][1])
					{
						b[k][0] = m1.b[i][0];
						b[k][1] = m1.b[i][1];
						b[k][2] = m1.b[i][2];
						i++;
						k++;
					}
					else
					{
						b[k][0] = m1.b[j][0];
						b[k][1] = m1.b[j][1];
						b[k][2] = m1.b[j][2];
						k++;
						j++;
					}
				}//inner if loop ends
			}
			else
			{
				if(m1.b[i][0] < m2.b[j][0])
				{
					b[k][0] = m1.b[i][0];
					b[k][1] = m1.b[i][1];
					b[k][2] = m1.b[i][2];
					i++;
					k++;
				}
				else
				{
					b[k][0] = m2.b[j][0];
					b[k][1] = m2.b[j][1];
					b[k][2] = m2.b[j][2];
					k++;
					j++;
				}
			}//outer if loop ends
		};//1st while ends

		while(i <= m1.count)
		{
			b[k][0] = m1.b[i][0];
			b[k][1] = m1.b[i][1];
			b[k][2] = m1.b[i][2];
			i++;
			k++;
		};//2nd while loop ends

		while(j <= m2.count)
		{
			b[k][0] = m2.b[j][0];
			b[k][1] = m2.b[j][1];
			b[k][2] = m2.b[j][2];
			k++;
			j++;
		};//3rd while loop ends

		count = k-1;
    }

	void sparse_diplay(matrix m1 , matrix m2)				//to display addition
	{
		if(m1.r >= m2.r)
			b[0][0] = m1.r;
		else
			b[0][0] = m2.r;
		if(m1.c >= m2.c)
			b[0][1] = m1.c;
		else
			b[0][1] = m2.c;
		b[0][2] = m1.count + m2.count;

		for(i=0; i<=count; i++)
		{
            cout << b[i][0] << "\t" << b[i][1] << "\t" << b[i][2] << "\n";
		}
	}
	void sparse_diplay()									//to display in tuple representation
		{
			for(i=0; i<=count; i++)
			{
	            cout << b[i][0] << "\t" << b[i][1] << "\t" << b[i][2] << "\n";
			}
		}


	void display_matrix()									//to display in matrix format
	{
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				cout << a[i][j] << "\t";
			}
			cout << "\n";
		}
	}
};

int main()
{
	int ch;
	char x;
	matrix m1,m2,m3;

	cout << "\n Enter the details of matrix";
	m1.readmatrix();

	do
	{
		cout << "\n Enter your choice"
				"\n 1 to display the matrix"
				"\n 2 to convert matrix into 3 column representation"
				"\n 3 for simple transpose of matrix"
				"\n 4 for fast transpose if matrix"
				"\n 5 for addition"
				"\n Here:\t";
		cin >> ch;

		switch(ch)
		{
			case 1:	cout << "\n Given Matrix : " << "\n";
                    m1.display_matrix();
				break;

			case 2:	cout << "\n 3 Column Representation : " << endl;
                    m1.sparse_represent();
                    m1.sparse_diplay();
				break;

			case 3:	cout << "\n Simple Transpose : " << endl;
                    m1.simple_transpose();
				break;

			case 4:	cout << "\n Fast Transpose : " << endl;
                    m1.fast_transpose();
				break;

			case 5:	m2.readmatrix();
					cout << "\n Matrix1:\n";
					m1.display_matrix();
					cout << "\n Matrix2:\n";
					m2.display_matrix();
                    m2.sparse_represent();
                    cout << "\n Addition of matrix is:\n";
					m3.addition(m1,m2);
					m3.sparse_diplay(m1,m2);
				break;
		}

		cout << "\n Do you want to continue? [Y/N]\t";
		cin >> x;

	}while(x=='y' || x=='Y');

	cout << "\n *************************************** ";
	cout << "\n                   END                   ";
	cout << "\n *************************************** ";

	return 0;
}