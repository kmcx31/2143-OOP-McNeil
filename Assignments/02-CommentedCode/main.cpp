///////////////////////////////////////////////////////////////////////////////
// Author: Kevin McNeil Jr.
// Email:  shaqmantoo121@yahoo.com
// Label:  02-A02
// Title:  Commenting C++ Code
// Course: 2143-OOP
// Semester: Spring 2020
//
// Description:
//       Implements a doubley-linked list, automatically sorts and places elements into list, and prints output.
//
// Usage:
//
// Files:   main.cpp    :   driver program
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

//global array with size 100
int A[100];  

//struct node that holds a single number in memory to build the list
struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This class implements a list of nodes that hold single
 *      value integers with the capability of sorting the values as they are added
 *      and printing them out.
 * 
 * Public Methods:
 *      - void      Push(int val)
 *      - void      Insert(int val)
 *      - void      PrintTail()
 *      - string    Print()
 *      - int       Pop()
 *      - List      operator+(const List &Rhs)
 *      - int       operator[](int index)
 *      - friend    ostream &operator<<(ostream &os, List L)
 * 
 * Private Methods:
 * 
 * Usage:
 *      List L;         //initialize list
 * 
 *      L.Push(int);    //push value into list
 *      L.Pop();        //return value from list
 *      L.Print():      //print list
 *      
 */
class List
{
  private:
    Node *Head;     //pointer to track from of list
    Node *Tail;     //pointer to track end of list
    int Size;       //size counter to keep track of total size of list

  public:
    //default constructor
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Push value onto list
     * 
     * Params:
     *      int     :   numeral value
     * 
     * Returns:
     */

    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);
        
        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * Public : Insert
     * 
     * Description:
     *      Insert value into list.
     * 
     * Params:
     *      int     :   numeral value
     * 
     * Returns:
     */

    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }

    /**
     * Public : PrintTail
     * 
     * Description:
     *      Prints the last value of the list.
     * 
     * Params:
     * 
     * Returns:
     */

    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    /**
     * Public : Print
     * 
     * Description:
     *      Prints the List values
     * 
     * Params:
     * 
     * Returns:
     */

    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      Remove and return a value from the end of the List.
     * 
     * Params:
     * 
     * Returns:
     *      int value from list.
     */

    int Pop()
    {
        Size--;
        return 0; //
    }

    /**
     * Public : operator+
     * 
     * Description:
     *      Copies a previously made List to a new List.
     * 
     * Params:
     *      cont List&    :   An already made List
     * 
     * Returns:
     *      A new List with values from old List.
     */

    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1;    //initialize l1
    List L2;    //initialize l2

    for (int i = 0; i < 25; i++)    //for loop that pushes 0-24 onto L1
    {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++)  //for loop that pushes 50-99 onto L2
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;      //adds values of L1 and L2 togeth to create L3
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}