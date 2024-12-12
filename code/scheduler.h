#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Reference for using the enum classes for this project 
// https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/

// We will be using these in order to define our Priorty values and Surgery Type.

enum class Priority { 
    High, // Urgent or Emergency 
    Medium,  // Required 
    Low,   // Optional or elective 
};

enum class SurgeryType { 
    Emergent, 
    Elective
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
}
// Initiating the queue Referencing assignment 6 that includes sections INSERT
// in the textbook we are going to be using heap

struct pq {
    vector<pq_node> heap;
    int size; 

    pq() : size(0) // Initializing  
    ~pq() = default //Destructor/ deleting to keep memory in check

    void MHPUp(int nodeindex); //Heap up 
    void MHPDown(int nodeindex): // Heap down 

    void insert_pq(Surgery surgery, float priortiy); //inserting the surgery into the heap 
    Surgery remove_pg(); // Removing the highest priority sruergy - once it get assigned a room  

};

// Initializing the priority queue
pq* init_priority_queue(): 

/Function to peek the highest priority surgery 
Surgery peek_pq(pq*& queue);

class scheduler {
private: 
    int roomNum;  // room number
    vector<int> roomAvaliability;// Vector of rooms and when they are free
    pq* surgeryQueue;   // Priority queue for the sugeries
public:
    scheduler(int rooms);
    void addSurgery(); 
    void scheduleSugeries();
    void printSchedule()
}


#endif //  SCHEDULER_H