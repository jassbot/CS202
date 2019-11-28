//Jasmine Snyder
//Program #1
//CS202
////This is the implementation file for the grpah / adjacency list. The graph is handled with an
//array of Linear Linked List while the race is handled with a DLL.


#include "graph.h"


list::list() //initializes head pointer in the obstacle array to null
{
    head = NULL;
}

list::~list() //deallocates all dynamic memory used during program
{
    if(head) //checks for head and then deletes if found 
    {
        delete head;
        head = NULL;
    }
        
}

bool list::insert(node* to_add) //wrapper function to call the insert private func
{
    if(!to_add)
        return false;
    else
        return insert(head, to_add);
}

bool list::insert(node*& head, node* to_add) //checks case if list is empty and creates a new node other wise it will add one new item
{
    if(isempty())
    {
        head = to_add; //sets head to add node 
        head -> set_next(NULL); //sets next to NULL 

        return true;
    }
    else if(!isempty()) //if its empty make temporary node to add 
    {
        node* temp = to_add;
        temp -> set_next(head); //sets temps next to head 
        head = temp;
        
        return true;
    }
    else
    {
        return false;
    }
}

bool list::isempty() //checks if list is empty
{
    if(!head)
        return true;
    else
        return false;
}

int list::sum_obstacles()
{
    int sum = 0;

    sum_obstacles(head, sum);
    return sum;
}

int list::sum_obstacles(node* head, int & sum)
{ 
    if(!head)
    {
        return 0;
    }
    if(isempty())
    {
        return 0;
    }
    else
    {
        cout << "OBSTACLE DATA:" << head -> get_obstacle();
        sum += sum_obstacles(head -> get_next(), sum) + head -> get_obstacle();
    }
}

int node::get_obstacle()
{
    return obstacle;
}

bool list::display() //displays entire list
{
    bool result = false; //returns false

    if(isempty()) //if the list is empty output error message 
    {
        cout << "No obstacles to be displayed" << endl;
    }
    else
    {
        result = display_help(head); //otherwise call the display_helper function passing in head 
    }

    return result; //return false
}

bool list::display_help(node* head) //display helper function
{
    if(!head)
        return false;
    else
    {
        head -> display(); //recursively call display at head index 
        return display_help(head -> get_next()); //returns the next until NULL 
    }
}

node* list::get_head() //returns head of the beginning of the list
{
    return head;
}

DLL::DLL(): d_head(NULL), d_tail(NULL)
{

}

DLL::~DLL() //destructor for doubly linked list
{
    if(d_head) //check if head exists in DLL 
    {
        delete d_head; //delete that node 
        d_head = NULL; //set to NULL 
    }
    if(d_tail) //if there is tail 
    {
        delete d_tail; //delete and set it to NULL 
        d_tail = NULL;
    }
}

bool DLL::isempty_DLL() //check for empty doubly linked list
{
    if(!d_head)
        return true;
    else
        return false;
}

bool DLL::insert_drone(drone* to_insert) //insert a drone into the doubly linked list
{
    if(!to_insert)
        return false;
    else
        return insert_drone(d_head, to_insert); //if there is something to insert recursively calls insert_drone
}

bool DLL::insert_drone(drone*& d_head, drone* to_insert) //pass in the address of curr in doubly linked list
{
    if(isempty_DLL()) //if DLL returns true that it is empty 
    {
        d_head = to_insert; //the current is set to the node to be inserted 
        d_tail = d_head; //set tail to head 
        d_head -> set_next(NULL); //set the next to NULL return true

        return true;
    }
    else if(!isempty_DLL()) //otherwise if not empty DLL, need to look for next empty space 
    {
        d_tail -> set_next(to_insert); //set DLL tail to set the next to the added node 
        d_tail -> get_next() -> set_previous(d_tail); //sets previous to what is currently the tail 
        d_tail = d_tail -> get_next(); //tail is set to the added nodes next 
        d_tail -> set_next(NULL); //that new node now points to NULL

        return true;
    }
    else
    {
        return false;
    }
}

bool DLL::display_drones(drone* d_head) //display all drones in the DLL
{
    if(!d_head)
        return false;
    else
    {
        d_head -> display(); //calls the display wrapper function 
        cout << '\n'; 
        return display_drones(d_head -> get_next()); //recursively displays 
    }
}

bool DLL::display_drones() //wrapper function for displaying the drones in the DLL
{
    bool result = false;
    if(isempty_DLL()) //check if it is empty and return error message 
    {
        cout << "No drones to display." << endl;
    }
    else
    {
        result = display_drones(d_head); //otherwise continue calling display passing in head
    }
    
    return result;
}



