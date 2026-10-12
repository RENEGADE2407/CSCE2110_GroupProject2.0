#include "WaitingList.h"

// Adds a student to the back of the waiting list
void WaitingList::AddStudent(int studentID, string studentName, string resourceID)
{
    // Make a copy of the queue to check for duplicates
    queue<WaitingStudent> tempQueue = waitingQueue;

    // Check whether this student is already waiting for this resource
    while (!tempQueue.empty())
    {
        WaitingStudent currentStudent = tempQueue.front();

        if (currentStudent.StudentID == studentID &&
            currentStudent.ResourceID == resourceID)
        {
            cout << "Student is already on the waiting list for this resource."
                 << endl;
            return;
        }

        tempQueue.pop();
    }

    // Create a WaitingStudent object with the provided information
    WaitingStudent student;

    student.StudentID = studentID;
    student.StudentName = studentName;
    student.ResourceID = resourceID;

    // Add the student to the back of the queue
    // This maintains FIFO (First In, First Out) behavior
    waitingQueue.push(student);

    cout << "Student added to waiting list." << endl;
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



int WaitingList::CountWaitingForResource(string resourceID) const
{

    int count = 0;

    queue<WaitingStudent> tempQueue = waitingQueue;

    //goes thu every student in the waiting list
    while (!tempQueue.empty())
    {
        //checks if student is waiting for this resourece
        if(tempQueue.front().ResourceID == resourceID)
        {
            ++count;
        }
    

    //move to next student in queue
    tempQueue.pop();
    }

    return count;
            
}
    
