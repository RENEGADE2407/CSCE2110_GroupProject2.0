#include "CancellationHistory.h"

// Adds a cancelled reservation to the top of the stack
void CancellationHistory::Push(Reservation reservation)
{
    // Add the cancelled reservation to the stack
    // The most recently cancelled reservation will be on top
    cancellationStack.push(reservation);
}


// Removes the most recently cancelled reservation from the stack
bool CancellationHistory::Pop(Reservation& reservation)
{
    // Check if the stack is empty before attempting to remove a reservation
    if (cancellationStack.empty())
    {
        return false;
    }

    // Copy the most recently cancelled reservation
    reservation = cancellationStack.top();

    // Remove the reservation from the stack
    cancellationStack.pop();

    return true;
}


// Displays all cancelled reservations from most recent to oldest
void CancellationHistory::DisplayHistory() const
{
    // Check if there are no cancelled reservations
    if (cancellationStack.empty())
    {
        cout << "No cancellation history available." << endl;
        return;
    }

    cout << "===== Cancellation History =====" << endl;

    // Create a copy so displaying the history does not change the original stack
    stack<Reservation> tempStack = cancellationStack;

    // Display reservations from the most recent cancellation to the oldest
    while (!tempStack.empty())
    {
        Reservation reservation = tempStack.top();

        cout << "Reservation "
             << reservation.GetReservationID()
             << endl;

        // Remove the displayed reservation from the temporary stack
        tempStack.pop();
    }
}
