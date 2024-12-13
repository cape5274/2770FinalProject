#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>



using namespace std;

// Reference for using the enum classes for this project 
// https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/

// We will be using these in order to define our Priorty values and Surgery Type.

enum class Priority { 
    High = 3, // Urgent or Emergency 
    Medium = 2 ,  // Required 
    Low = 1,   // Optional or elective 
};

enum class SurgeryType { 
    Emergent = 1, 
    Elective = 2
};



// Define the variables that we will take into consideration per surgery
struct Surgery { 
    string patName; //Patient Name 
    SurgeryType type; //Type of procedure
    Priority priority; // Urgency of surgery
    int duration; //Max time surgery can take  
};

// Using a priority queue in for this scheduler
struct pq_node{ 
    Surgery surgery; 
    float priority;
};
// Initiating the queue Referencing assignment 6 that includes sections INSERT
// in the textbook we are going to be using heap in order to manage priortiy for the surgeries 

struct pq {
    vector<pq_node> heap;
    int size; 

    pq(); // Initializing  
    ~pq() = default; //Destructor/ deleting to keep memory in check

    void MHPUp(int nodeindex); //Heap up 
    void MHPDown(int nodeindex); // Heap down 

    void insert_pq(pq_node newNode); //inserting the surgery into the heap 
    Surgery remove_pq(); // Removing the highest priority sruergy - once it get assigned a room  

};

Surgery peek_pq(pq*& queue);

class scheduler {
private: 
// These wwill not be able to be modified outside of the class
    int roomNum;  // room number
    vector<int> roomAvailability;// Vector of rooms and when they are free
    int currentTime;
    pq* surgeryQueue;   // Priority queue for the sugeries
public:
    scheduler(int rooms); 

    void addSurgery(Surgery surgery, float priority); 

    void scheduleSurgeries();

    void printSchedule();  
};

// Now we are going to focus on the scheduler calss and defining thisin order to organize the schedule based 
// on the avaliable rooms the location has.





#endif //  SCHEDULER_H