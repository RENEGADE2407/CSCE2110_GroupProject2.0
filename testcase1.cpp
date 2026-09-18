#include <iostream>

#include "Waiting List/WaitingList.h"
#include "Cancellation History/CancellationHistory.h"

using namespace std;

int main()
{
    // ==========================================
    // Test Waiting List
    // ==========================================

    cout << "===== TESTING WAITING LIST =====" << endl;

    WaitingList waitingList;

    // Add three students to the waiting list
    waitingList.AddStudent(101, "Alice Smith", "R205");
    waitingList.AddStudent(102, "Bob Jones", "R205");
    waitingList.AddStudent(103, "Charlie Brown", "R205");

    // Display the waiting list
    cout << "\nInitial waiting list:" << endl;
    waitingList.DisplayWaitingList();

    // Remove the first student from the queue
    WaitingList::WaitingStudent student;

    if (waitingList.RemoveStudent(student))
    {
        cout << "\nStudent removed from waiting list: "
             << student.StudentName << endl;
    }
    else
    {
        cout << "\nWaiting list is empty." << endl;
    }

    // Display the waiting list after removing Alice
    cout << "\nWaiting list after removal:" << endl;
    waitingList.DisplayWaitingList();


    // ==========================================
    // Test Cancellation History
    // ==========================================

    cout << "\n\n===== TESTING CANCELLATION HISTORY =====" << endl;

    CancellationHistory history;

    // Create three test reservations
    Reservation reservation301(
        301,
        101,
        "Alice Smith",
        "R205",
        "09/18/2026"
    );

    Reservation reservation302(
        302,
        102,
        "Bob Jones",
        "R205",
        "09/18/2026"
    );

    Reservation reservation303(
        303,
        103,
        "Charlie Brown",
        "R205",
        "09/18/2026"
    );

    // Add the cancelled reservations to the stack
    history.Push(reservation301);
    history.Push(reservation302);
    history.Push(reservation303);

    // Display cancellation history
    cout << "\nCancellation history:" << endl;
    history.DisplayHistory();

    // Undo the most recent cancellation
    Reservation restoredReservation;

    if (history.Pop(restoredReservation))
    {
        cout << "\nRestored reservation: "
             << restoredReservation.GetReservationID()
             << endl;
    }
    else
    {
        cout << "\nNo cancellations available to undo." << endl;
    }

    // Display history after the undo
    cout << "\nCancellation history after undo:" << endl;
    history.DisplayHistory();


    // ==========================================
    // Test Empty Stack
    // ==========================================

    cout << "\n===== TESTING EMPTY STACK =====" << endl;

    // Remove the remaining two reservations
    history.Pop(restoredReservation);
    history.Pop(restoredReservation);

    // Try to remove from an empty stack
    if (history.Pop(restoredReservation))
    {
        cout << "A reservation was restored." << endl;
    }
    else
    {
        cout << "No cancellations available to undo." << endl;
    }

    return 0;
}
