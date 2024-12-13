#include "scheduler.h"

#include <iostream>

using namespace std;

#include "scheduler.h"

int main() {
    scheduler sched(5);  // 5 rooms available

    // Example surgery
    Surgery surgery1 = {"John Doe", SurgeryType::Emergent, Priority::High, 2};
    sched.addSurgery(surgery1, 3);

    // Call the scheduling function to assign surgeries to rooms
    sched.scheduleSurgeries();

    return 0;
}