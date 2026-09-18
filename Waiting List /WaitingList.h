#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class WaitingList
{
public:

    // Stores information about a student waiting for a resource
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
    // Returns false if the queue is empty
    bool RemoveStudent(WaitingStudent& student);

    // Displays the students without changing the original queue
    void DisplayWaitingList() const;
};

#endif
