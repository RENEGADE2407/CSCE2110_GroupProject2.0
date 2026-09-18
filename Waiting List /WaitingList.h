#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <iostream>
#include <string>
#include <queue>

class WaitingList
{
public:

    // Stores the information for a student waiting for a resource
    struct WaitingStudent
    {
        int StudentID;
        string StudentName;
        string ResourceID;
    };

private:

    // Queue stores students in FIFO order
    queue<WaitingStudent> waitingQueue;

public:

    // Adds a student to the back of the waiting list
    void AddStudent(int studentID, string studentName, string resourceID);

    // Removes the student at the front of the waiting list
    // Returns true if a student was removed, false if the queue is empty
    bool RemoveStudent(WaitingStudent& student);

    // Displays all students currently in the waiting list
    void DisplayWaitingList() const;
};

#endif
