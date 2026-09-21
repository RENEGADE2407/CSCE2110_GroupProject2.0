# **Campus Resource Reservation System (CRRS)**  

  
This project is a simulation of a reservation system for campus resources. CRRS is a C++ program that uses a command line menu to interact with the system. 

The project uses object-oriented programming and basic data structures to handle the system's data. For example, a vector is used for resource inventory, a stack is used to store cancelled reservations for the undo cancellation function, a linked list is used to store active reservations, and a FIFO queue is used to manage the waiting list for resources. 

**_Objectives_**
-------------------------------------------------------------------------------------

*  Upload resource information through an input file.
*  Display a menu that allows the user to do the following:
   *  Display all resources / display resource availability.
   *  Create reservations for campus resources.
   *  Cancel, search, and display active reservations.
   *  Display waiting list.
   *  Display cancellation history.
   *  Restore the most recent cancelled reservation.
   *  Exit the system.
*  Implement linked list to store/manage active reservations.
*  Implement queue to handle waiting list.
*  Implement stack to store cancellation history and restore cancelled reservations.
*  Implement reservation validation that prevents creating a reservation with a preexisting reservation ID, or a resource ID that does not exist

**_Technologies / Tools Used_**
-------------------------------------------------------------------------------------
* C++
* C++ standard library
* GitHub
* Notepad++

**_Project Structure_**
-------------------------------------------------------------------------------------
Project1/  
|  
|--include/  
| |--Resource.h  
| |--Reservation.h  
| |--ReservationManager.h  
|  
|--src/
| |--main.cpp  
| |--Resource.cpp  
| |--Reservation.cpp  
| L--ReservationManager.cpp  
|  
|--data/  
| |--resources.txt  
| L--reservations.txt  
|  
|--Makefile
|--README.md  
L--.gitignore

**_Installation_**
-------------------------------------------------------------------------------------

1. Clone the repository:
   git clone https://github.com/RENEGADE2407/CSCE2110_GroupProject2.0.git

2. Change to the project directory:
   cd CSCE2110_GroupProject2.0

3. Compile the project:
   g++ main.cpp Resource/Resource.cpp ResourceManager/ResourceManager.cpp Reservation/Reservation.cpp ReservationManager/ReservationManager.cpp "Waiting List/WaitingList.cpp" "Cancellation History/CancellationHistory.cpp" -o crrs

**_How to Run_**
--------------------------------------------------------------------------------------------

Run the executable:

./crrs

The program will load resources from resources.txt and reservations from reservations.txt and display a command-line menu.

**_Data Set / Input_**
-----------------------------------------------------------------------------------------------

* resources.txt
* reservations.txt

**_Methodology_**
----------------------------------------------------------------------------------------------

1. Load resource information from data file.
2. Store and display resources in a vector
3. Create/validate/search/remove/display reservations
4. Add students to waiting list queue (when resource unavailable)
5. Store cancelled reservations in a stack (also capable of restoring most recently cancelled reservation)

**_Results_**
------------------------------------------------------------------------------------------------------

**In terms of results..... we have no results-- NEED INPUT**


**_Challenges / Limitations_**
------------------------------------------------------------------------------------------------------

* Coordinating class interactions
* Ensuring program compiles
* Making sure invalid reservations are properly handled
* Making all parts of the program work together 


**_Future Improvements_**
-------------------------------------------------------------------------------------------------------

The goal for the future is to refine CRRS by implementing a search fucntion for resources and a sort function for reservations. Some other improvements include error handling for user interface and generating system reports for the following:
* Active reservations
* Resource utilization
* Most requested resources
* Waiting-list statistics

<br>
<br>
<br>
<br>

**_Author_**  
Jason Wildman  
Drake Thompson  
Benjamin Constantin

**_Course_**  
CSCE 2110 - Foundations of Data Structures

**_Instructor_**  
Professor Bahareh Dorri

**_University_**  
University of North Texas

**_Semester_**  
Fall 2026



