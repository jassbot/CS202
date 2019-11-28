//Jasmine Snyder
//Program #1 
//CS202
//04/29/2019
//This file contains the classes that manage the Linear Linked List within the graph that display the 
//obstacles. As well as the doubly linked list class that will manage the actual race of the drones.
//Many of the functions within the private section of these classes require wrapper functions to be called.


#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

#ifndef LIST
#define LIST
#include "node.h"

class list //this is the adjacency list that manages the obstacle course
{
    public:
        list(); //constructor for the list        
        ~list(); //destructor for the list class

        bool insert(node* to_add); //insert an obstacle 
        bool display(); //displays the entire list 
        bool isempty(); //checks if there is an obstacle there 
        bool start(); //start the race 
        int sum_obstacles(); //sums all the obstacle times

        node* get_head(); //gets the beginning of the list

    protected:
        node* head; //beginning of list node
        bool insert(node*& head, node* to_add); //insert a obstacle passing in the current node 
        bool display_help(node* head); //display helper function
        int sum_obstacles(node* head, int &);
};

class DLL //displays the race of drones
{
    public:
        DLL(); //constructor for DLL 
        ~DLL(); //destructor

        bool insert_drone(drone* to_insert); //insert a drone item 
        bool display_drones(); //display the race with drones 
        bool isempty_DLL(); //check if there is an empty slot

        drone* get_head(); //get the beginning of the DLL 
        drone* get_tail(); //gets the end of the list

    protected:
        drone* d_head; //head for DLL 
        drone* d_tail; //tail for DLL

        bool display_drones(drone* ); //displays all the drones within the list 
        bool insert_drone(drone*& d_head, drone* to_insert); //insert a drone 
};

#endif












