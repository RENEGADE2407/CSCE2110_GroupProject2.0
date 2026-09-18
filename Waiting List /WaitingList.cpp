#include "WaitingList.h"

// Adds a student to the back of the waiting list
void WaitingList::AddStudent(int studentID, string studentName, string resourceID)
{
    // Create a WaitingStudent object with the provided information
    WaitingStudent student;

    student.StudentID = studentID;
    student.StudentName = studentName;
    student.ResourceID = resourceID;

    // Add the student to the back of the queue
    // This maintains FIFO (First In, First Out) behavior
    waitingQueue.push(student);
}


// Removes the student at the front of the waiting list
bool WaitingList::RemoveStudent(WaitingStudent& student)
{
    // Check if the waiting list is empty before attempting to remove a student
    if (waitingQueue.empty())
    {
        return false;
    }

    // Copy the first student into the provided variable
    student = waitingQueue.front();

    // Remove the first student from the queue
    waitingQueue.pop();

    return true;
}


// Displays all students currently in the waiting list
void WaitingList::DisplayWaitingList() const
{
    // Check if there are no students waiting
    if (waitingQueue.empty())
    {
        cout << "Waiting list is empty." << endl;
        return;
    }

    cout << "===== Waiting List =====" << endl;

    // Create a copy of the queue so the original queue is not changed
    queue<WaitingStudent> tempQueue = waitingQueue;

    int position = 1;

    // Display students from front to back
    while (!tempQueue.empty())
    {
        WaitingStudent student = tempQueue.front();

        cout << position << ". "
             << student.StudentName
             << " (Student ID: " << student.StudentID << ")"
             << " - Resource: " << student.ResourceID
             << endl;

        // Remove the displayed student from the temporary queue
        tempQueue.pop();

        position++;
    }
}
