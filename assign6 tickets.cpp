/* The ticket booking system of Cinema theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume some random booking to start with. Use array to
store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be canceled.
*/

#include <iostream>
#include <string>

using namespace std;

struct node
{
    int status;
    string name;
    node *next;
    node *prev;
};

class Cinema													 //creating a class Cinema
{
    node *new_node;
public:
        node *head[10];
        Cinema()
        {
            for(int i=0; i<10; i++)
            {
                head[i] = NULL;
            }
        }

        void create_list();                                     //creating a doubly circular linked list
        void book_seat();                                       //for inserting element in the list
        void cancel_seat();                                     //for deleting element from the list
        void display();                                         //for displaying the list

};

void Cinema :: create_list()
{
    for(int i=0; i<10; i++)
    {
        for(int j=1; j<=7; j++)
        {
            new_node = new node;
            new_node->status = 0;
            new_node->name = " ";
            new_node->next = new_node->prev = NULL;

            if(head[i] == NULL)
            {
                head[i] = new_node;
                new_node->prev = head[i];
                new_node->next = head[i];
            }
            else
            {
                node *current_node;
                current_node = head[i];

                while(current_node->next != head[i])
                {
                    current_node = current_node->next;
                }

                new_node->next = current_node->next;
                current_node->next = new_node;
                new_node->prev = current_node;
                head[i]->prev = new_node;
            }
        }
    }
}

void Cinema :: display()
{
    cout << "\n *********************** SCREEN ************************* " << endl;
    cout << "\t";

    for(int j=0; j<7; j++)
    	cout << " " <<j+1 << "\t";

    cout << "\n";

    for(int i=0; i<10; i++)
    {
        node *current_node;
        current_node = head[i];
        cout << i+1 << "\t";
        do
        {
            if(current_node->status == 0)
                cout << " A " << "\t";
            else
                cout << " NA " << "\t";

            current_node = current_node->next;

        }while(current_node != head[i]);

        cout<<"\n";
    }
    cout << "\n";
}

void Cinema :: book_seat()
{
    int r,s;
    cout << " ********************************************** " << endl;
    cout << " For booking of seat " << endl;
    cout << " Enter row no. : ";
    cin >> r;
    cout << " Enter seat no. : ";
    cin >> s;

    if((r>0 && r<11) && (s>0 && s<8))
    {
        node* current_node;
        current_node = head[r-1];

        for(int j=1; j<s; j++)
        {
            current_node = current_node->next;
        }

        if(current_node->status == 0)
        {
            current_node->status = 1;
            cout << " Enter name : ";
            cin >> current_node->name;
        }
        else
            cout << " Seat is unavailable" << endl;
    }
    else
    	cout << "\n Invalid Selection " << endl;
}

void Cinema :: cancel_seat()
{
    int r, s;
    cout << " ********************************************** " << endl;
    cout << " For Cancellation of seat " << endl;
    cout << " Enter row no. : ";
    cin >> r;
    cout << " Enter seat no. : ";
    cin >> s;

    if((r>0 || r<11) && (s>0 || s<8))
    {
        node* current_node;
        current_node = head[r-1];

        for(int j=1; j<s; j++)
        {
            current_node = current_node->next;
        }

        if(current_node->status == 1)
        {
        	current_node->status = 0;
        	cout << "\n Seat is deleted ";
        }
        else
            cout << " Seat is already cancelled " << endl;
    }
}

int main()
{
    Cinema obj;
    char x;
    int ch, no_t;
    obj.create_list();

    do
    {
            cout << "\n ================= MENU ================= " << endl;
            cout << " ENTER YOUR CHOICE " << endl;
            cout << " 1. DISPLAY AVAILABALE SEATS " << endl;
            cout << " 2. BOOKING OF SEATS " << endl;
            cout << " 3. CANCELLING OF SEATS " << endl;
            cout << "    HERE : \t";
            cin >> ch;

            switch(ch)
            {
                case 1:
                        obj.display();
                    break;

                case 2:
                		cout << "\n Enter the number of tickets : ";
                    	cin >> no_t;
                    	for(int i=0; i<no_t; i++)
                        {
                            obj.book_seat();
                        }
                        obj.display();
                    break;

                case 3:
                        obj.cancel_seat();
                        obj.display();
                    break;

                default :
                        cout << "\n Invalid Selection!! " << endl;
            }

        cout << " ********************************************** " << endl;
        cout << " Do you want to book/cancel more seats? [Y/N] \t";
        cin >> x;

    }while(x=='Y' || x=='y');

    cout << " ********************************************** " << endl;
    cout << "                      END                       " << endl;
    cout << " ********************************************** " << endl;

    return 0;
}
