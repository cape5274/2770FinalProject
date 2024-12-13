#include "scheduler.h"

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
    heap.push_back(newNode);  // Add the new node to the heap
    size++;
    MHPUp(size - 1);
}

Surgery pq::remove_pq(pq*& queue) { 
    if (size == 0){ 
        return "Priority Queue is empty"  // Checking to see if the queue is empty 
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

void scheduler::scheduleSurgeries(){  
    while (surgeryQueue->size > 0) {
        pq_node currentSurgeryNode = surgeryQueue->remove_pq();
        Surgery surgery = currentSurgeryNode.surgery;
        

        bool assigned = false; 

        for (int i = 0; i < roomNum; ++i) { 
            if (roomAvailability[i] <= currentTime) { 
                //Assigning the procedure to a room that it is avaliable
                roomAvailability[i] = currentTime + surgery.duration; 
                cout << "Surgery for patient " << surgery.patName << " assigned to room " << i + 1 << "at time " << currentTime << endl; 
                // Out statement with the room assignment and the tme that surery will occur in the room 
                assigned = true; 
                break;
            }

        }

        if (!assigned) { 
        cout << "No rooms are avaliable at this time for surgery: " << surgery.patName << endl; 
            // Added an cout statement is all rooms are taken
        }
    }

}


void scheduler::printSchedule() {   // This is going to print out our schedule in our main cpp file
    cout << "Scheduling Summary:" << endl;
    for (int i = 0; i < roomNum; ++i) {
        cout << "Room " << i + 1 << " is available at time " << roomAvailability[i] << endl;
    }
}
