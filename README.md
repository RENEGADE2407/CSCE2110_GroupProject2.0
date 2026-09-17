**Campus Resource Reservation System (CRRS)**

This project is a simulation of a reservation system for campus resources. CRRS is a C++ program that uses a command line menu to interact with the system. 

The project uses object-oriented programming and basic data structures to handle the system's data. For example, a vector is used for resource inventory, a stack is used to store cancelled reservations for the undo cancellation function, a linked list is used to store active reservations, and a FIFO queue is used to manage the waiting list for resources. 

**Objectives**

*  Upload resource information through an input file.
*  Display a menu that allows the user to do the following:
   *  Display all resources / display resource availability.
   *  Sort resources.
   *  Create reservations for campus resources.
   *  Cancel, search, and display active reservations.
   *  Display waiting list.
   *  Display cancellation history.
   *  Restore the most recent cancelled reservation.
   *  Generate report.
   *  Exit the system.
*  Implement linked list to store/manage active reservations.
*  Implement queue to handle waiting list.
*  Implement stack to store cancellation history and restore cancelled reservations.
*  Implement reservation validation that prevents creating a reservation with a prexisting reservation ID, or a resource ID that does not exist

**Technologies / Tools Used**

* C++
* C++ standard library
* GitHub
* Notepad++

**Project Structure**

Project1/  
|  
|--include/  
| |--Resource.h  
| |--Reservation.h  
| |--ReservationManager.h  
|  
|--src/ **Not sure what this is but it was in the project 1 file organization**
| |--main.cpp  
| |--Resource.cpp  
| |--Reservation.cpp  
| L--ReservationManager.cpp  
|  
|--data/  
| |--resources.txt  
| L--reservations.txt  
|  
|--README.txt  
L--.gitignore  **Might need to add makefile**

**Installation**

1. Download the repository -- gitclone https://github.com/RENEGADE2407/CSCE2110_GroupProject2.0.git
2. Change to project directory -- cd CSCE2110_GroupProject2.0
3. Compile using makefile -- **!!!NEED MAKE FILE NAME MUEY IMPORTANTE!!!**

**How to Run**

1. After compiling, run executable **!!!NEED EXECUTABLE!!!**
2. Use menu to interact with reservation system

**Data Set / Input**

* resources.txt
* reservation.txt

**Methodology**

1. Load resource information from data file.
2. Store/display/search resources in a vector
3. Create/validate/search/remove/display reservations
4. Add students to waiting list queue (when resource unavailable)
5. Store cancelled reservations in a stack (also capable of restoring most recently cancelled reservation)
6. Generate report

**Results**

**In terms of results..... we have no results**

**Challenges / Limitations**

**Many and often lol -- NEED INPUT**

**Future Improvements**

**Since this is milestone 1, I believe we should fill this in with milestone 2 more or less-- NEED INPUT**

**Author**  
Jason Wildman  
Drake Thompson  
Benjamin Constantin

**Course**  
CSCE 2110 - Foundations of Data Structures

**Instructor**  
Professor Bahareh Dorri

**University**  
University of North Texas

**Semester**  
Fall 2026

**References**

**Might need input might get removed**

