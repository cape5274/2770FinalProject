#include "scheduler.h"

#include <iostream>

using namespace std;


int main() {
    scheduler sched(5);  // 5 rooms available

        // Example surgeries with different durations
    Surgery surgery1 = {"Pat Surtain", SurgeryType::Emergent, Priority::High, 120}; // 120 minutes
    Surgery surgery2 = {"Chip", SurgeryType::Elective, Priority::Medium, 60}; // 60 minutes
    Surgery surgery3 = {"Travis Hunter", SurgeryType::Emergent, Priority::Low, 45}; // 45 minutes
    Surgery surgery4 = {"Coach Prime", SurgeryType::Elective, Priority::High, 60}; // 60 minutes
    Surgery surgery5 = {"Bo Nix", SurgeryType::Emergent, Priority::Medium, 300}; // 300

    // Add surgeries to the queue
    sched.addSurgery(surgery1, 3);
    sched.addSurgery(surgery2, 2);
    sched.addSurgery(surgery3, 1);
    sched.addSurgery(surgery4, 3);
    sched.addSurgery(surgery5, 2);

    // Call the scheduling function to assign surgeries to rooms
    sched.scheduleSurgeries();

    sched.printSchedule();

    return 0;
}