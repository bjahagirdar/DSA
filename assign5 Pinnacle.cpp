/* Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly one may
cancel the membership of club. First node is reserved for president of club and last node is reserved for
secretary of club. Write C++ program to maintain club members information using singly linked list.
Store student PRN and Name. Write functions to
	a)Add and delete the members as well as president or even secretary.
	b)Compute total number of members of club .
	b)Display members .
	c)Display list in reverse order using recursion .
	e)Two linked lists exists for two divisions. Concatenate two lists.
*/

#include <iostream>
#include <cstring>

using namespace std;

struct node                                                 //creating a node
{
    string nam;
    int num;
    struct node *next;
};

class Pinnacle
{
    public:
		struct node *start;
        Pinnacle()                                          //constructor
        {
            start = NULL;
        }
        node* create_node(string, int);                     //allocating memory to the node
        void insert_begin();                                //to insert element at beginning
        void insert_pos();                                  //to insert element at any position
        void insert_last();                                 //to insert element at the end
        void insert_menu();                                 //insert menu
        void delete_first();                                //to delete element at beginning
        void delete_pos();                                  //to delete element at any position
        void delete_last();                                 //to delete element at the end
        void delete_menu();                                 //delete menu
        void length();                                      //to compute total number of nodes
        void reverse_list(node*);                           //to reverse the elements
        void concat_list(Pinnacle);                         //to concatenate 2 lists
        void display();                                     //to display the linked list
        void menu();                                        //menu

};

node *Pinnacle :: create_node(string name, int prn)
{
    struct node *temp;
    temp = new(struct node);

    if (temp == NULL)
    {
        cout << "Memory not allocated " << endl;
        return 0;
    }

    else
    {
        temp->nam = name;
        temp->num = prn;
        temp->next = NULL;
        return temp;
    }
}

void Pinnacle :: insert_begin()
{
    string name;
    int prn;
    start = NULL;
    cout << "\n Enter the name of the President : ";
    cin >> name;
    cout << "\n Enter the PRN : ";
    cin >> prn;

    struct node *temp, *p;
    p = NULL;
    temp = NULL;
    temp = create_node(name, prn);

    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }

    cout << "\n Element Inserted at beginning " << endl;
}

void Pinnacle::insert_last()
{
    string name;
    int prn;

    cout << "\n Enter the name of the Secretary : ";
    cin >> name;
    cout << "\n Enter the PRN number : ";
    cin >> prn;

    struct node *temp, *s;
    s = NULL;
    temp = NULL;
    temp = create_node(name, prn);
    s = start;

    while (s->next != NULL)
    {
        s = s->next;
    }

    temp->next = NULL;
    s->next = temp;

    cout << "\n Element Inserted at last" << endl;
}

void Pinnacle::insert_pos()
{
    int pos, counter = 0;
    string name;
    int prn;

    cout << "\n Enter the name of the student : ";
    cin >> name;
    cout << "\n Enter the PRN number : ";
    cin >> prn;

    struct node *temp, *s, *ptr;
    s = NULL;
    ptr = NULL;

    temp = create_node(name, prn);

    cout << "\n Enter the position at which node to be inserted: ";
    cin >> pos;

    int i;
    s = start;

    while (s != NULL)
    {
        s = s->next;
        counter++;
    }

    if (pos == 1)
    {
        if (start == NULL)
        {

            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;   //temp->next = start; start = temp;
            start = temp;
            start->next = ptr;
        }
    }

    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }

        ptr->next = temp;
        temp->next = s;
    }

    else
    {
        cout << "\n Position out of range" << endl;
    }
}

void Pinnacle :: insert_menu()
{
    int in;

    cout << "\n --------------------------------------------------- ";
    cout << "\n Enter the position where you want to add a member : ";
    cout << "\n 1. To add the President (at the start) ";
    cout << "\n 2. To add a member (at any position) ";
    cout << "\n 3. To add the Secretary (at the end) ";
    cout << "\n Here : ";
    cin >> in;

    switch(in)
    {
        case 1:
                cout << "\n For the President " << endl;
                insert_begin();
                display();
                cout << endl;
            break;

        case 2:
                cout << "\n For the member at given position " << endl;
                insert_pos();
                display();
                cout << endl;
            break;

        case 3:
                cout << "\n For the Secretary " << endl;
                insert_last();
                display();
                cout << endl;
            break;
    }

}

void Pinnacle :: delete_first()
{
    if (start == NULL)
    {
        cout<<"\n Pinnacle club is empty "<<endl;
        return;
    }

    struct node *p, *q;
    q = start;
    p = start->next;
    start = p;
    delete(q);

    cout << "\n The first node is deleted ";
}

 void Pinnacle :: delete_last()
 {
    struct node *p, *q;

    q = start;
    p = start->next;

    while(p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    q->next = NULL;
    delete(p);

    cout << "\n The node at the end is deleted ";
 }

void Pinnacle :: delete_pos()
{
    int pos, i, counter = 0;

    if (start == NULL)
    {
        cout<<"\n Pinnacle club is empty "<<endl;
        return;
    }

    cout << "\n Enter the position of value to be deleted : ";
    cin >> pos;

    struct node *s, *ptr;

    s = start;
    if (pos == 1)
    {
        start = s->next;
        delete (s);
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }

        if (pos > 1 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
            delete(s);
        }
        else
        {
            cout << "\n Position out of range" << endl;
        }

        cout << "\n Element Deleted" << endl;
    }
}

void Pinnacle :: delete_menu()
{
    int del;

    cout << "\n ----------------------------------------------------- ";
    cout << "\n Enter the position where you want to delete element : ";
    cout << "\n 1. To delete at the start";
    cout << "\n 2. To delete in middle of list";
    cout << "\n 3. To delete at the end";
    cout << "\n Here : ";
    cin >> del;

    switch(del)
    {
        case 1 :
                cout << "\n Deleting at start" << endl;
                delete_first();
                display();
            break;

        case 2 :
                cout << "\n Delete a particular node: " << endl;
                delete_pos();
                display();
            break;

        case 3 :
                cout << "\n Deleting at end" << endl;
                delete_last();
                display();
            break;
    }
}

void Pinnacle :: length()
{
    struct node *p;
    int len=0;
    p = start;

    while(p != NULL)
    {
        p = p->next;
        len++;
    }

    cout << "\n Total number of members in th club : " << len;
}

void Pinnacle :: reverse_list(struct node* p)
{
    if(p->next == NULL)
    {
        start = p;
        return;
    }

    reverse_list(p->next);
    struct node* q = p->next;
    q->next = p;
    p->next = NULL;

    struct node *temp;
    temp = start;
    cout << "\n Reverse Members of Pinnacle club are: " << endl;
    while (temp != NULL)
    {
        cout << temp->nam << ", " << temp->num << "-> ";
        temp = temp->next;
    }
    cout << " NULL" << endl;

}

void Pinnacle :: concat_list(Pinnacle s_b)
{
	struct node *temp;
	temp = start;

	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = s_b.start;
}

void Pinnacle :: display()
{
    struct node *temp;
    temp = NULL;

    if (start == NULL)
    {
        cout << "\n The Pinnacle club is Empty" << endl;
        return;
    }

    temp = start;
    cout << "\n Members of Pinnacle club are: " << endl;

    while (temp != NULL)
    {
        cout << temp->nam << ", " << temp->num << "-> ";
        temp = temp->next;
    }

    cout << " NULL" << endl;
}

void Pinnacle :: menu()
{
    int choice;
    char x;

    do
    {
        cout << "\n ---------------------------------------------- ";
        cout << "\n Enter your choice " << endl;
        cout << " 1. Add a member " << endl;
        cout << " 2. Remove a member " << endl;
        cout << " 3. Compute total number of members in club " << endl;
        cout << " 4. Reversing the members of the club " << endl;
        cout << " 5. Display the members of the club " << endl;
        cout << " Enter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1: insert_menu();
                break;

            case 2: delete_menu();
                break;

            case 3: length();
                break;

            case 4: reverse_list(start);
                break;

            case 5:
                    cout << "\n Display elements of link list" << endl;
                    display();
                    cout << endl;
                break;

            default:
                    cout << "\n Wrong choice" << endl;
        }
        cout << "\n Do you want to remain in this division ? [Y/N] \t";
        cin >> x;

    }while(x=='y' || x=='Y');
}

int main()
{
    char div, x1;
    Pinnacle s_a, s_b;                                      //creating 2 objects of class Pinnacle for 2 divisions

    do
    {
        cout << "\n ********************************************** ";
        cout << "\n                  PINNACLE CLUB                 ";
        cout << "\n ********************************************** ";
        cout << "\n Enter your division : [A/B] \t ";
        cin >> div;

        switch(div)
        {
            case 'a' :
                    cout << "\n ---------------------------------------------- " << endl;
                    cout << "\n                   DIVISION A                   " << endl;
                    cout << "\n ---------------------------------------------- " << endl;
                    s_a.menu();
                    s_a.display();
                break;
            case 'b' :
                    cout << "\n ---------------------------------------------- " << endl;
                    cout << "\n                   DIVISION B                   " << endl;
                    cout << "\n ---------------------------------------------- " << endl;
                    s_b.menu();
                    s_b.display();
                break;
        }
        cout << "\n Do you want to enter details of other division? [Y/N] \t";
        cin >> x1;

    }while(x1=='y' || x1=='Y');

    cout << "\n Appending both the divisions ";
    s_a.concat_list(s_b);
    s_a.display();

    cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
    cout << "\n                      END                       ";
    cout << "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";

    return 0;
}
