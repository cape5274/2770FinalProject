#include "scheduler.h"

using namespace std;

pq* init_priority_queue() {
  // Initializing new pq 
  pq* queue = new pq();   //Using a pointer this will initazlize this

  return queue;
}

Surgery peek_pq(pq*& queue) { 
    if (queue-->size = 0){ 
        return "";   // This will check if the queue is empty
    }

    return queue->heap[0].surgery;  // surgery and patient with the most priority being returned
}

void pq::insert_pq(Surgery surgery, float priority) {
    pq_node newNode = {surgery, priority}; // Creating a node with the surgery and priortiy value 
    heap.push_back(newNode);  // Adding a node
    size++; // Increasing the size of the heap
    MHPUp(size - 1) // Restore the health but moving node up 

}

Surgery pq::remove_pq(pq*& queue) { 
    if (size == 0){ 
        return "Priority Queue is empty"  // Checking to see if the queue is empty 
    }

    Surgery highestPrioritySurgery = heap[0].surgery; // saving the srugery with the highest priorty 
    
    heap[0] = heap[size - 1]; 
    heap.pop_back();
    size--;

    queue->MHPDown(0);

    return highestPrioritySurgery;

}

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

scheduler::scheduler(int rooms) : roomNum(rooms), roomAvaliability(rooms,0), surgeryQueue(init_priority_queue()){}

void scheduler::addSurgeyry(Surgery surgery, float priority) { 
    int currentTime = 0; 
    while (surgeryQueue->size  > 0) {
        Surgery surgery = peek_pq(surgeryQueue);  // Geting the highest priorty surgery to assign them to a room 
        surgeryQueue->remove_pq(); //we are removing the highest priorty in order to move to the next 
        // procedure that needs asignment

        bool assisgned = false; 

    }


} void scheduler::printSchedule() {   // This is going to print out our schedule in our main cpp file
    cout << "Scheduling Summary:" << endl;
    for (int i = 0; i < roomNum; ++i) {
        cout << "Room " << i + 1 << " is available at time " << roomAvailability[i] << endl;
    }
}
