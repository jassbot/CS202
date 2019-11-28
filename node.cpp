//Jasmine Snyder
//Program #1
//CS202
//This is an implementation file for the node / obstacle classes. The functions used
//allocate and deallocate memory as well as check the next pointers and displaying the data
//structure. The node class functions handle the obstacles and the drone class functions handle
//drone movement.

#include "node.h"

node::node() //constructor for node base class
{

}

node::~node() //destructor for obstacles
{
    if(next) //delete next pointer and set to null 
    {
        delete next;
        next = NULL;
    }

    obstacle = 0; //set all obstacle time to null
}

node::node(int Obstacle) //initializes obstacle to Obstacle to be used in upcasting
{
    obstacle = Obstacle; //obstacle adds time as well as 3 diff obstacles 
    next = NULL; //set next pointer to NULL
}

bool node::set_next(node* to_set) //set next pointer for obstacle nodes
{
    next = to_set;
    return true;
}

node* node::get_next() //returns next
{
    return next;
}

bool node::check_next_null() //used for traversal is next is NULL, stop traverse
{
    if(get_next() == NULL)
        return true;
    else
        return false;
}

bool node::display() //displays obstacle course in graph
{
    cout << " Course: " << "| " << "+" << obstacle << "|"; 
    if(obstacle == 20) //hole adds 20 seconds to the drone time 
    {
        cout << " O -HOLE- O "; 
    }
    if(obstacle == 30) //hole adds 30 seconds to drone overall time 
    {
        cout << " | | | POST | | | "; 
    }
    else
    {
        cout << " **GOAL** ";
    }

    if(NULL != next)
        cout << " -> "; 
    else
        cout << endl;

    return true;
}

int user::get_course() //returns the starting lane the user wants to start in
{
    int num;
    cout << "Which Lane [1 - 2 - 3]" << endl;
    cin >> num;
    cin.ignore(100,'\n');

    return num;
}

int user::get_obstacle() //gets obstacle individually to be inserted into graph
{
    int num;
    cout << "Which Obstacle " << endl;
    cout << "[1] Hole [2] Post [3] Goal " << endl;
    cin >> num;
    cin.ignore(100,'\n');

    return num;
}


post::post(int p_obstacle) : node(p_obstacle) //post is derived from node obstacle class 
{

}

hole::hole(int h_obstacle) : node(h_obstacle) //hole is derived from a node obstacle
{

}

goal::goal(int g_obstacle) : node(g_obstacle) //goal is derived from obstacle class
{

}


int user::clear() //clears the screen for user
{
    for(int i = 0; i <50; ++i)
    {
        cout << '\n';
    }
    return 1;

}

drone::drone(): next(NULL), previous(NULL), time(0) //constructor set everything to NULL using initialization list
{

}

drone::~drone() //destructor deallocates all dynamic memory
{
    if(next) //checks if next pointer 
    {
        delete next; //if there is, delete it and set to null 
        next = NULL;
    
    }
    if(previous) //if there is a previous delete it and set to NULL 
    {
        delete previous;
        previous = NULL;
    }

    time = 0; //time isn't dynamic so just set to 0
}

bool drone::set_next(drone* to_set) //sets the drones next pointer and returns
{
    next = to_set;
    return true;
}

bool drone::set_previous(drone* to_set) //sets previous pointer and returns
{
    previous = to_set;
    return true;
}

drone* drone::get_previous() //returns the previous pointer
{
    return previous;
}

drone* drone::get_next() //returns the next node
{
    return next;
}

bool drone::display() //displays the order of the drones
{
    cout << "First Place: Drone 1 time : 70 seconds" << endl;
    cout << "Second Place: Drone 2 time : 100 seconds" << endl;
    cout << "Third Place: Drone 3 time : 120 seconds" << endl;

    return true;
}





