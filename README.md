# CS202
Background:
  For Program 1, create an object oriented program that will simulate the notion of drone racing
  through an obstacle course.
 
  Some relationships should be hierarchial, others can be containment. Push common elements up to
  base class. Nodes will be classes instead of structs. 
  
  Obstacle course need to be three different types of obstacles.
  1. Goal posts
  2. Black holes
  3. Touch and GO
  
  Must implement two of the above list of obstacles and add one other of your own. 
  
  Data Structure:
  Drones in the race should be handled with a doubly linked list. Consider where the front running
  drones are located (head or tail) and what happens when there are severe collisions. You need
  both a head and a tail pointer.
  
  Obstacle course should be implemented with a Graph. Your graph should be implemented using an
  adjacency list which is a dynamically allocated array of head pointers to edge lists. Each
  head pointer points to a LLL of straightaway's and adjacent obstacles. There should be more than
  one path from the start to the finish line.
  
  All traversals implemented recursively.
  All arrays implemented dynamically with non-constant size.
