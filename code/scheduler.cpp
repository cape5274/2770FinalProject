#include "scheduler.h"

using namespace std;

void pq::MHPUp(int nodeindex) {
    while (nodeindex > 0) {
        int parent = (nodeindex - 1) / 2;
        if (heap[nodeindex].priority > heap[parent].priority) {
            swap(heap[nodeindex], heap[parent]);
            nodeindex = parent;
        } else {
            break;
        }
    }
}


pq* init_priority_queue() {
  // Initializing new pq 
  pq* queue = new pq();   //Using a pointer this will initazlize this

  return queue;
}
