#include "ReservationManager.h"
#include <iostream>
#include <string>
using namespace std;


//********LINKED LIST OPERATIONS ********

//default needs to start with head node being null
ReservationManager::ReservationManager()
{
	head = nullptr;
}

//destructor

ReservationManager::~ReservationManager()
{
	/*We create a placeholder for the next node, delete the current node,
	move to the placeholder, then update the placeholder to the next node and repeat.
	*/
	Node* current = head; //current starts at the first node
	
	while (current != nullptr) //loop that keeps going until current = null (meaning there are no more nodes)
	{
		Node* nextNode = current->next; //creates the placeholder pointer for the next node
		
		delete current; //now that the placeholder is pointing at the next node it is safe to get rid of current
		
		current = nextNode; //current takes placeholder 
	}
}



///adding a reservation
bool ReservationManager::InsertReservation(Reservation reservation)
{
	//creates a new node
	Node* newNode = new Node;
	
	//puts the reservation into the new node
	newNode->reservation = reservation;
	
	newNode->next = head;
	
	head = newNode;
	
	return true;
}



//removing a reservation
bool ReservationManager::RemoveReservation(int reservationID)
{
	//start at head 
	Node* current = head;
	
	/*this keeps track of the node behind current so when we delete a node thats after head
	we can use this to change the previous node to point to the one after current*/
	Node* previous = nullptr;
	
	//check if current exists and matches reservation id
	if (current != nullptr && current->reservation.GetReservationID() == reservationID)
	{
		head = current->next;
		delete current;
		return true;
	}
	
	while (current != nullptr && current->reservation.GetReservationID() != reservationID)
	{
		//change previous to currents position and move current to the next node in the linked list
		previous = current;
		current = current->next;
	}
	
	//if reservation is not found return false
	if (current == nullptr)
	{
		return false;
	}
	
	//if it gets to this point then current is on the reservation we want to remove 
	previous->next = current->next;
	delete current;
	
	return true;
}


//search using reservation id
Reservation* ReservationManager::SearchReservation(int reservationID)
{
	Node* current = head;
	
	while (current != nullptr)
	{
		if (current->reservation.GetReservationID() == reservationID)
		{
			return &current->reservation;
		}
		
		current = current->next;
	}
	
	return nullptr;
}


//display 

void ReservationManager::DisplayReservations() const
{
	Node* current = head;
	
	while(current != nullptr)
	{
		
		cout << "Reservation ID: " << current->reservation.GetReservationID() << endl;
		cout << "Student ID: " << current->reservation.GetStudentID() << endl;
		cout << "Student Name: " << current->reservation.GetStudentName() << endl;
		cout << "Resource ID: " << current->reservation.GetResourceID() << endl;
		cout << "Reservation Date: " << current->reservation.GetReservationDate() << endl;
		
		current = current->next;
	}
}



//********RESERVATION MANAGEMENT ********
	
//this will create a new reservation
bool ReservationManager::CreateReservation(Reservation reservation)
{
	//check if reservation valid and then call insert reservation function
	if(!ValidateReservation(reservation))
	{
		return false;
	}
	
	else
	{
		return InsertReservation(reservation);
	}
}
	
//this will cancel a reservation using a reservation id
bool ReservationManager::CancelReservation(int reservationID)
{
	//this will call search function to search linked list for reservation using specified id
	// and it will create a pointer and store the result in "reservation"
	Reservation* reservation = SearchReservation(reservationID);
	
	//check to see if the result from search is null (meaning not in linked list)
	if(reservation == nullptr)
	{
		return false;
	}
	
	//save copy of reservation before deleting it so it can be used in cancelation history
	Reservation cancelledReservation = *reservation;

	//add cancelled reservation to cancellation history
	cancellationHistory.Push(cancelledReservation);
	
	//remove reservation
	RemoveReservation(reservationID);
	
	return true;
	
}

//this will undo the most recent cancellation
bool ReservationManager::UndoCancellation()
{
	//this is a placeholder, pop will fill this in with the most recently cancelleed reservation
	Reservation restoredReservation;


	/*this will simultaneously remove the top reservation from the stack then copy it into 
	restoredReservations, AND if pop fails i.e. the stack is empty
	 it will print an error msg and proceed to return false*/
	if(!cancellationHistory.Pop(restoredReservation))
	{
		cout << "Error: No cancelled reservation to restore." << endl;
		return false;
	}

	/*Need to validate that a new reservation hasnt used the cancelled reservations id
	otherwise we risk duplicating the id. If the validation check fails this will put the
	reservation back into the stack*/
	if (!ValidateReservation(restoredReservation))
	{
		cancellationHistory.Push(restoredReservation);
		return false;
	}

	//If we get here id is not in use so restore the reservation back into linked list
	return InsertReservation(restoredReservation);
}

//This displays the cancellation history
void ReservationManager::DisplayCancellationHistory() const
{
	/*main cant reach cancellationHistory cause its private
	this passes the call along to stack's DisplayHistory funct.*/
	cancellationHistory.DisplayHistory();
}
	
//this will ensure the validity of a reservation
bool ReservationManager::ValidateReservation(Reservation reservation)
{
	/*this gets the id from the reservation we need to validate and
	passes that id to the search function and checks if the return value is null
	*/
	if(SearchReservation(reservation.GetReservationID()) != nullptr)
	{
		cout << "Error: Reservation ID already exists." << endl;
		return false;
	}
	
	else 
	{
		return true;
	}
}
