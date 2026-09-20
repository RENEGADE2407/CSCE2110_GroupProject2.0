#ifndef CANCELLATIONHISTORY_H
#define CANCELLATIONHISTORY_H

#include "../Reservation/Reservation.h"
#include <iostream>
#include <stack>
using namespace std;

class CancellationHistory
{
private:

    // Stack stores cancelled reservations in LIFO order
    stack<Reservation> cancellationStack;

public:

    // Adds a cancelled reservation to the top of the stack
    void Push(Reservation reservation);

    // Removes and returns the most recently cancelled reservation
    bool Pop(Reservation& reservation);

    // Displays all cancelled reservations from most recent to oldest
    void DisplayHistory() const;
};

#endif
