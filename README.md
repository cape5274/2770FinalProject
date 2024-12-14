# 2770 Final Project
## Priorty Surgery Scheduler
As someone with experience in the healthcare field, I have witnessed firsthand the critical importance of efficient and effective patient management. In healthcare settings, especially in hospitals with multiple operating rooms, the ability to quickly and accurately prioritize surgeries is essential. Emergencies, such as life-threatening surgeries or urgent procedures, often need to be handled immediately, while elective surgeries may have a longer window for scheduling. This requires an organized system to ensure that the right patient receives the right care at the right time.

For this assignment, I chose to focus on the concept of priority queues, as they provide an effective and reliable method for scheduling surgeries in a hospital setting. By organizing surgeries based on priority (such as emergent, high priority, medium priority, and low priority), hospitals can quickly and efficiently allocate available operating rooms. This priority-based scheduling ensures that urgent procedures take precedence, reducing the risk of delays or complications in critical care.

I believe that priority queues can be a powerful tool for hospitals, particularly in emergency situations, where quick decision-making and resource management are crucial. This project aims to demonstrate how a priority queue can be applied to a surgical scheduling system, helping to improve hospital operations, enhance patient care, and streamline the scheduling process.

## Overview 
In a medical setting it is import to be able to organize the surgery schedule based off priorty, and duration of the surgery and the number of operating rooms avalible. This is a consitant issue that is handing in hospital settings. This project owuld be usuful in emergycy type settins or large hostipal with multiples operation rooms they oversee.  

## Workflow 
1. Organize Patient on surgery Priority
2. Schedule surgeries considering prodecure times and room avaliability
3. Start time for all procedure is 6AM (we have to have that defined)
4. Print out list of who is next, based off avaliabiltiy and priority 
## Goals 
For this project we will have two goals: 
* To Organize patient based off severity(priorty)
** Emergent Surgeries vs elective surgeries
** Three levels (High, Medium, Low )
* To the schedule these Patients based off procedure time and priorty of surgery
* We will also keep track of the number of rooms and their avaiabllity for the procedure.
** This will Cater this program to multi operating room hospitals 

We will try to assign each patient case(surgery) to an avaliable room and crate a system that will create a queue so that each syrgery will be attended to in an organized timely manner
## Pseudocode

For this part I relied heaviliy on Assignment 6 and the chapters that came with it, as it focused on priortiy queues. This is a short outline that I used at the begining of tis process to start my code and then later one was changed. 


### Define SurgeryType enum:
    - **EMERGENT**
    - **ELECTIVE**

### Define Priority enum:
    - **HIGH**
    - **MEDIUM**
    - **LOW**

### Define Surgery class:
    - patientName: string
    - surgeryType: SurgeryType
    - priority: Priority
    - duration: int  // Surgery duration in minutes

### Define PriorityQueue class:
    - surgeries: List of Surgery nodes (heap)
    - insertSurgery(surgery: Surgery): Adds surgery to queue based on priority
    - removeSurgery(): Removes the highest priority surgery from the queue

### Define Scheduler class:
    - rooms: int  // Number of operating rooms
    - roomAvailability: array[int]  // Tracks availability time for each room
    - surgeryQueue: PriorityQueue  // Queue to manage surgeries

    Function addSurgery(surgery: Surgery, priority: int):
        - Create a new Surgery node with the given priority
        - Add the surgery to the priority queue

    Function scheduleSurgeries():
        - Set the initial time (e.g., 6 AM -> 360 minutes)
        - While there are surgeries in the queue:
            - Get the surgery with highest priority
            - Find the first available room
            - If a room is available:
                - Assign the surgery to the roo
                - Print the surgery details (room and time)
            - If no room is available:
                - Print message that no room is available
            - Increment the time minute by minute

    Function printSchedule():
        - For each room:
            - Print when the room will be available next

We will also create a fake senario in order to test this function and see the outputs of this function.

### Main Function:
    - Initialize Scheduler with 5 rooms
    - Create sample surgeries with different durations
    - Add surgeries to the queue
    - Call scheduleSurgeries() to assign rooms to surgeries
    - Call printSchedule() to print the room availability summary


## Problems 
Heres are some issues that I had to solve while building this code: 
- The currentTime variable is initialized at 6 AM (360 minutes from midnight), representing the earliest possible time a surgery can start. As surgeries are scheduled, the program iterates through each surgery in the priority queue. For each surgery, the currentTime is updated by adding the duration of the surgery (in minutes) to it. This ensures that after a surgery is scheduled, the available time for the operating room is updated accordingly. The program continues scheduling surgeries until there are no more procedures left in the queue, adjusting the time incrementally for each surgery.

The program also tracks the availability of each operating room, updating the room’s availability time after a surgery is assigned to it. This means that if a room is occupied, the program waits until the room becomes available before scheduling another surgery in that room.

- Time Conversion: In the scheduleSurgeries() function, currentTime is converted to seconds (currentTime * 60) because strftime() (used for formatting the time) requires the time to be in seconds. The localtime() function then converts the time in seconds into a tm structure, which can be formatted and displayed using strftime(). strftime() formats the time into a human-readable format (hours and minutes, e.g., 06:00), which is then displayed to the user to indicate when a surgery is scheduled. 

- The priority queue relies on a heap data structure to maintain the order of surgeries based on their priority. When a node (surgery) is removed, the heap property should be restored. However, when replacing a node with heap[nodeIndex] = current_node;, the heap program was not running as desired and it caused issues in surgery scheduling and havingin surgies be assigned to rooms that were not avaliable. I ended up referening a previous assignment and creaing queue MHPDown and MHPUp  whose functions were to ensure the the order was restored as all times when called.
- 

 # Surgery Scheduler: A Priority-Based Surgery Scheduling System

This project is a simulation of a priority-based surgery scheduling system that assigns surgeries to available operating rooms based on priority and duration. The scheduler is designed to handle multiple rooms and ensure that emergent surgeries get higher priority over elective ones. We can edit the main.cpp file in the repositry and enter different feature that will give different schedules. 

### Features:
- **Priority Queue**: Surgeries are scheduled based on priority (High, Medium, Low).
- **Operating Rooms**: The scheduler can handle multiple operating rooms and assign surgeries based on room availability.
- **Time Management**: It starts scheduling from 6 AM and considers the time it takes for each surgery.

---


### **How to Run the Project** 

```
#### 1. Clone the Repository:

To get started, clone this repository to your local machine using Git.

in your terminal: 
git clone https://github.com/your-username/surgery-scheduler.git  

#### 2. Complieing the code: 
make sure that we are in the code folder you can do cd code to get into the folder if needed

cd code

#### 3. Running the code:

Once the code is complied then we can run it by entering ./scheudler  ```
