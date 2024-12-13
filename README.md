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


Define SurgeryType enum:
    - **EMERGENT**
    - **ELECTIVE**

Define Priority enum:
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
Heres are some issues that i had to solve while building this code: 
- Time problem
- issues with node 
