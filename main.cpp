#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "ResourceManager/ResourceManager.h"
#include "ReservationManager/ReservationManager.h"
#include "Waiting List/WaitingList.h"

using namespace std;

// Loads reservations from the reservation data file
bool LoadReservationsFromFile(
    string filename,
    ReservationManager& reservationManager)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error: Could not open file \""
             << filename << "\"." << endl;

        return false;
    }

    string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream lineStream(line);

        string reservationIDString;
        string studentIDString;
        string studentName;
        string resourceID;
        string reservationDate;

        getline(lineStream, reservationIDString, '|');
        getline(lineStream, studentIDString, '|');
        getline(lineStream, studentName, '|');
        getline(lineStream, resourceID, '|');
        getline(lineStream, reservationDate);

        if (reservationIDString.empty() ||
            studentIDString.empty() ||
            studentName.empty() ||
            resourceID.empty() ||
            reservationDate.empty())
        {
            cout << "Warning: Skipping invalid reservation: "
                 << line << endl;

            continue;
        }

        int reservationID = stoi(reservationIDString);
        int studentID = stoi(studentIDString);

        Reservation reservation(
            reservationID,
            studentID,
            studentName,
            resourceID,
            reservationDate
        );

        if (!reservationManager.CreateReservation(reservation))
        {
            cout << "Warning: Could not load reservation "
                 << reservationID << "." << endl;
        }
    }

    inputFile.close();

    return true;
}

// Displays the main menu
void DisplayMenu()
{
    cout << "\n========================================" << endl;
    cout << " CAMPUS RESOURCE RESERVATION SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Display all resources" << endl;
    cout << "2. Display resource availability" << endl;
    cout << "3. Display active reservations" << endl;
    cout << "4. Search for a reservation" << endl;
    cout << "5. Create a reservation" << endl;
    cout << "6. Cancel a reservation" << endl;
    cout << "7. Display waiting list" << endl;
    cout << "8. Add student to waiting list" << endl;
    cout << "9. Remove student from waiting list" << endl;
    cout << "10. Display cancellation history" << endl;
    cout << "11. Undo most recent cancellation" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    ResourceManager resourceManager;
    ReservationManager reservationManager;
    WaitingList waitingList;

    // Load resources when the program starts
    if (!resourceManager.LoadResourcesFromFile("resources.txt"))
    {
        cout << "Warning: Resources could not be loaded." << endl;
    }

    // Load existing reservations
    if (!LoadReservationsFromFile(
            "reservations.txt",
            reservationManager))
    {
        cout << "Warning: Reservations could not be loaded." << endl;
    }

    int choice;

    do
    {
        DisplayMenu();

        cin >> choice;

        // Handle non-numeric input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                resourceManager.DisplayResources();
                break;
            }

            case 2:
            {
                resourceManager.DisplayAvailability();
                break;
            }

            case 3:
            {
                reservationManager.DisplayReservations();
                break;
            }

            case 4:
            {
                int reservationID;

                cout << "Enter reservation ID: ";
                cin >> reservationID;

                Reservation* reservation =
                    reservationManager.SearchReservation(
                        reservationID
                    );

                if (reservation != nullptr)
                {
                    cout << "\nReservation found:" << endl;
                    cout << "Reservation ID: "
                         << reservation->GetReservationID()
                         << endl;
                    cout << "Student ID: "
                         << reservation->GetStudentID()
                         << endl;
                    cout << "Student Name: "
                         << reservation->GetStudentName()
                         << endl;
                    cout << "Resource ID: "
                         << reservation->GetResourceID()
                         << endl;
                    cout << "Reservation Date: "
                         << reservation->GetReservationDate()
                         << endl;
                }
                else
                {
                    cout << "Reservation not found." << endl;
                }

                break;
            }

            case 5:
            {
                int reservationID;
                int studentID;

                string studentName;
                string resourceID;
                string reservationDate;

                cout << "Enter reservation ID: ";
                cin >> reservationID;

                cout << "Enter student ID: ";
                cin >> studentID;

                cin.ignore();

                cout << "Enter student name: ";
                getline(cin, studentName);

                cout << "Enter resource ID: ";
                cin >> resourceID;

                cout << "Enter reservation date: ";
                cin >> reservationDate;

                // Make sure the resource exists
                if (!resourceManager.ValidateResourceID(resourceID))
                {
                    cout << "Reservation failed: "
                         << "Resource does not exist."
                         << endl;

                    break;
                }

                // If unavailable, add student to waiting list
                if (!resourceManager.IsResourceAvailable(resourceID))
                {
                    cout << "Resource is currently unavailable."
                         << endl;

                    cout << "Adding student to waiting list."
                         << endl;

                    waitingList.AddStudent(
                        studentID,
                        studentName,
                        resourceID
                    );

                    break;
                }

                Reservation reservation(
                    reservationID,
                    studentID,
                    studentName,
                    resourceID,
                    reservationDate
                );

                if (reservationManager.CreateReservation(reservation))
                {
                    resourceManager.SetResourceAvailability(
                        resourceID,
                        "Unavailable"
                    );

                    cout << "Reservation created successfully."
                         << endl;
                }
                else
                {
                    cout << "Reservation could not be created."
                         << endl;
                }

                break;
            }

            case 6:
            {
                int reservationID;

                cout << "Enter reservation ID to cancel: ";
                cin >> reservationID;

                Reservation* reservation =
                    reservationManager.SearchReservation(
                        reservationID
                    );

                if (reservation == nullptr)
                {
                    cout << "Reservation not found." << endl;
                    break;
                }

                string resourceID =
                    reservation->GetResourceID();

                if (reservationManager.CancelReservation(
                        reservationID))
                {
                    resourceManager.SetResourceAvailability(
                        resourceID,
                        "Available"
                    );

                    cout << "Reservation cancelled successfully."
                         << endl;
                }
                else
                {
                    cout << "Reservation could not be cancelled."
                         << endl;
                }

                break;
            }

            case 7:
            {
                waitingList.DisplayWaitingList();
                break;
            }

            case 8:
            {
                int studentID;
                string studentName;
                string resourceID;

                cout << "Enter student ID: ";
                cin >> studentID;

                cin.ignore();

                cout << "Enter student name: ";
                getline(cin, studentName);

                cout << "Enter resource ID: ";
                cin >> resourceID;

                if (!resourceManager.ValidateResourceID(resourceID))
                {
                    cout << "Resource does not exist." << endl;
                    break;
                }

                waitingList.AddStudent(
                    studentID,
                    studentName,
                    resourceID
                );

                cout << "Student added to waiting list."
                     << endl;

                break;
            }

            case 9:
            {
                WaitingList::WaitingStudent student;

                if (waitingList.RemoveStudent(student))
                {
                    cout << "Removed student:"
                         << endl;

                    cout << "Student ID: "
                         << student.StudentID
                         << endl;

                    cout << "Student Name: "
                         << student.StudentName
                         << endl;

                    cout << "Resource ID: "
                         << student.ResourceID
                         << endl;
                }
                else
                {
                    cout << "Waiting list is empty." << endl;
                }

                break;
            }

            case 10:
            {
                reservationManager.DisplaycancellationHistory();
                break;
            }

            case 11:
            {
                if (reservationManager.UndoCancellation())
                {
                    cout << "Cancellation successfully undone."
                         << endl;
                }
                else
                {
                    cout << "No cancellation could be undone."
                         << endl;
                }

                break;
            }

            case 0:
            {
                cout << "Exiting Campus Resource Reservation System."
                     << endl;
                break;
            }

            default:
            {
                cout << "Invalid menu choice."
                     << endl;
                break;
            }
        }

    } while (choice != 0);

    return 0;
}
