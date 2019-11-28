//Jasmine Snyder
//Program #1 
//CS202
//This is a header file that contains the classes for node (obstacles) and the derived classes from node.
//This file also contains a drone class that is managed by a Doubly Linked List. The DLL handles the drone race
//while the node obstacles are handled by the graph.

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

#ifndef NODE
#define NODE

class node //this is a container for the obstacles 
{
    public:
        node(); //constructor 
        node(int Obstacle); //initializes to diff types on obstacles
        ~node(); //destructor
        bool display(); //display function for obstacle 
        bool set_next(node* to_set); //set next node
        bool check_next_null(); //checks reaching the end of the list
        node* get_next(); //gets the pointer "next"
        int get_obstacle();

    protected:
        int obstacle; //time each obstacle takes to complete 
        node* next; //next pointer that points to next obstacle
};

class drone //container for drone info that is managed by a DLL
{
    public:
        drone(); //constructor 
        ~drone(); //destructor 

        drone* get_next(); //used for traversal  
        drone* get_previous(); //gets the node before the current
        
        bool display(); //display for DLL 
        bool set_next(drone* to_set); //sets the next pointer in the DLL class 
        bool set_previous(drone* to_set); //sets the previous

    protected:
        drone* next; //pointer to next drone 
        drone* previous; //previous pointer  
        int time; //depending on time each drone takes by obstacle changes position within the DLL
};


class hole: public node //a hole obstacle is derived from node
{
    public:
        hole(int h_obstacle); //initializes to the hole obstacle time
};

class post: public node //a post is an obstacle that is derived from node
{
    public:
        post(int p_obstacle); //initializes to post obstacle time
};

class goal: public node //goal is end of the race
{
    public:
        goal(int g_obstacle); //initializes to the goal time
};

class user //this classes manages functions that the user uses to build the obstacle course and race the drones
{
    public:
        int get_course(); //which index of array obstacle is added to
        int get_obstacle(); //user returns which obstacle to add
        int clear(); //clears screen
};

#endif












