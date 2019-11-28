//Jasmine Snyder
//Program #1 
//CS202
//This is the main implementation file where all function calls take place as well as initializing
//our array for our obstacle course. 

#include "node.h"
#include "graph.h"


int main()
{
    list* course[3]; //array of head pointers to LLL
    node* to_add = NULL; //pointer used to insert obstacles
    list my_list;
    user my_course; //object for user class -- used for menu
    drone* to_insert = NULL;
    DLL my_drone; //object for drone class to control movement of drone 
    char response; //used for main menu 
    int user_input; //menu input from user
    int which_obstacle; //user selects which obstacle
    int which_course; //returns which course to be started on 
    char answer; //Y to add more obstacles
    int time; //drone time

    for(int i = 0; i < 3; ++i) //initialize array
    {
        course[i] = new list(); //new list at each index in array
    }

    do
    {
        cout << "[1] Add Obstacle " << endl; //will display where beginning end are 
        cout << "[2] View Map " << endl; //adds an obstacle for drone to avoid 
        cout << "[3] Time to Race " << endl; //start drones at beginning of list       
        cin >> user_input;
        cin.ignore(100,'\n');

        my_course.clear();

        switch(user_input)
        {
            case 1:
                do
                {
                    which_obstacle = my_course.get_obstacle(); //user adds an obstacle
                    which_course = my_course.get_course(); //used returns which course they'd like to add obstacle to
                    if(which_obstacle == 1)
                    {
                        to_add = new hole(20); //hole obstacle adds 20 seconds
                    }
                    if(which_obstacle == 2)
                    {
                        to_add = new post(30); //post adds 30 seconds
                    }
                    if(which_obstacle == 3)
                    {
                        to_add = new goal(2);
                    }

                    course[which_course - 1] -> insert(to_add); //inserts obstacle to appropriate course 
                    my_course.clear();

                    cout << "Add more obstacle for drone?" << endl;
                    cin >> answer;
                    cin.ignore(100,'\n');
                } while(answer == 'y' || answer == 'Y');

                break;
            
            case 2: //display whole map of obstacles
                my_course.clear();
                cout << '\n' << "Current Map " << endl;
                cout << '\n';
                course[0] -> display();
                cout << '\n';
                course[1] -> display();
                cout << '\n';
                course[2] -> display();
                cout << '\n';

                break;

            case 3: //ready to race the drones
                char response;
                int lane;

                my_course.clear();
                cout << '\n' << "Current Obstacle Course " << endl;
                cout << '\n';
                course[0] -> display();
                cout << '\n';
                course[1] -> display();
                cout << '\n';
              
                cout << "Ready? [Y/N]" << endl;
                cin >> response;
                cin.ignore(100,'\n');

                my_course.clear();

                cout << "Which Lane? [1 - 2 - 3]" << endl;
                cin >> lane;
                cin.ignore(100,'\n');

                if(lane == 1)
                { 
                    course[0] -> display();
                    time = course[0] -> sum_obstacles();
                    cout << '\n';
                    cout << "Total course time: " << time << endl;

                    to_insert = new drone;
                    my_drone.insert_drone(to_insert);
                    my_drone.display_drones();
                }
                if(lane == 2)
                { 
                    course[1] -> display();
                    time = course[1] -> sum_obstacles();
                    cout << '\n';
                    cout << "Total course time: " << time << endl;

                    to_insert = new drone;
                    my_drone.insert_drone(to_insert);
                    my_drone.display_drones();
                
                }
                if(lane == 3)
                {
                    course[2] -> display(); 
                    time = course[2] -> sum_obstacles();
                    cout << '\n';
                    cout << "Total course time: " << time << endl;

                    to_insert = new drone;
                    my_drone.insert_drone(to_insert);
                    my_drone.display_drones(); 
                }

        } 

        
        cout << "Main Menu?" << endl;
        cin >> response;
        cin.ignore(100,'\n');
        my_course.clear();

    } while(response == 'y' || response == 'Y');

    //destroy course array
    int i = 0;
    for(i = 0; i < 3; ++i)
    {
        delete course[i];
        course[i] = NULL;
    }

    return 0;
}











