#include "scheduler.h"
#include <iomanip>
#include <ctime>

using namespace std;

pq::pq() : size(0) {}


void pq::MHPUp(int nodeindex) {
    while (nodeindex > 0) {
        int parent = (nodeindex - 1) / 2;
        if (heap[nodeindex].priority > heap[parent].priority) {
            swap(heap[nodeindex], heap[parent]);
            nodeindex = parent;    //Moving up the heap 
        } else {
            break;
        }
    }
}


void pq :: MHPDown(int nodeindex){
  int childindex = 2 * nodeindex + 1; //Calcuation of the left child
  pq_node current_node = heap[nodeindex];

  while (childindex < size){
    int maxindex = childindex; 

    if (childindex+ 1 < size && heap[childindex].priority < heap [childindex + 1].priority){
      maxindex = childindex + 1; // looking at the priority of the right child
    } // using the calulation to know that its index is + 1 of the left

    if (current_node.priority >= heap[maxindex].priority){
      break; // Check to see if everything is in order 
    }

    heap[nodeindex] = heap[maxindex]; // We are having our current node = the largest child is larger than parent
    nodeindex = maxindex;  // Moving index to largest child 
    childindex = 2* nodeindex + 1; //Moving to the next childindex if applicable 
  }

  heap[nodeindex] = current_node;
}    //USED AFTER REMOVING THE HGHEST PRORITY ELEMENT OF THE HEAP

Surgery peek_pq(pq*& queue) { 
    if (queue->size = 0){ 
        return Surgery();  // This will check if the queue is empty
    }

    return queue->heap[0].surgery;  // surgery and patient with the most priority being returned
}

void pq::insert_pq(pq_node newNode) {
    heap.push_back(newNode);  // Adding the new node to the heap
    size++;
    MHPUp(size - 1);  // Restore the heap property
}

Surgery pq::remove_pq() { 
    if (size == 0){ 
        cout << "Priority Queue is empty!" << endl;
        return Surgery(); // Checking to see if the queue is empty 
    }

    Surgery highestPrioritySurgery = heap[0].surgery; // saving the srugery with the highest priorty 
    
    heap[0] = heap[size - 1]; // MOving last element to the root
    heap.pop_back();
    size--;

    MHPDown(0); // Retoringt eh heap my movin the node down 

    return highestPrioritySurgery;

}

scheduler::scheduler(int rooms) : roomNum(rooms), roomAvailability(rooms,0), surgeryQueue(new pq()){}

void scheduler::addSurgery(Surgery surgery, float priority) { 
    pq_node newNode = {surgery, priority};
    surgeryQueue->insert_pq(newNode); // Adding a procedure to the queue based aoff its assigned priority

} 
 
// added a boolean flag in order to track assignments because the program kept 
// assignment procedures to the same room. also to help the code run more defined 


void scheduler::scheduleSurgeries(){  
    // Start time at 6 AM (360 minutes from midnight)
    currentTime = 6 * 60;  // We are defining this as the firt possible time a surgery 
    // could be scheduled 

    while (surgeryQueue->size > 0) {
        // Starting the loop as long as the queue is empty 
        Surgery currentSurgery = surgeryQueue->remove_pq();
        // Using the removed pg function in order to remove the next surgery 
        if (currentSurgery.patName.empty()) {
            // Checking if there is info is not invalid 
            cout << "Priority Queue is empty!" << endl;
            break;  // Exit if the queue is empty beause there are no surgies to schedule 
        }

        bool assigned = false; 

        for (int i = 0; i < roomNum; ++i) { 
            if (roomAvailability[i] <= currentTime) { 
                //Assigning the procedure to a room that it is avaliable
                roomAvailability[i] = currentTime + currentSurgery.duration; 

                time_t rawTime = currentTime * 60; // Convert to minutes for proper display
                struct tm* timeInfo = localtime(&rawTime);
                char buffer[80];
                strftime(buffer, sizeof(buffer), "%H:%M", timeInfo);
                // https://stackoverflow.com/questions/70696610/is-there-an-easier-way-to-get-the-current-time-in-hhmmss-format Reference for why i
                // represented time, in earlier process steps the time kepy accumulation and I had to search how to manage and display time
                // property and in the format that I wanted 


                cout << "Surgery for patient " << currentSurgery.patName << " assigned to room " << i + 1 << " at time " << put_time(timeInfo, "%H:%M") << endl;; 
                // Out statement with the room assignment and the tme that surery will occur in the room 
                assigned = true; 
                break;
            }

        }

        if (!assigned) { 
        cout << "No rooms are avaliable at this time for surgery: " << currentSurgery.patName << endl; 
            // Added an cout statement is all rooms are taken
        }

        currentTime++ ;
    }

}

// Originally for this printSchedule function the time was prining our in seconds 
// and it was hard to understand or read. used this stackoverflow forum 
// https://stackoverflow.com/questions/70696610/is-there-an-easier-way-to-get-the-current-time-in-hhmmss-format 
// and converted the time in seconds to as structure. and then used a buffer 

void scheduler::printSchedule() {   // This is going to print out our schedule in our main cpp file
    cout << "Scheduling Summary:" << endl;  // the heading of the summary 
    for (int i = 0; i < roomNum; ++i) {
            // Using roomNum  as the number of loops to perform
        time_t rawTime = roomAvailability[i] * 60; // Convert minutes to seconds
        struct tm* timeInfo = localtime(&rawTime);
        char buffer[80];
        // Buffer temporaliy hold data while its being processed or transferred 
        // in this section involves a formatted string that involes time. 
        strftime(buffer, sizeof(buffer), "%H:%M", timeInfo);
        cout << "Room " << i + 1 << " is available at time " << buffer << endl;
    }
}
