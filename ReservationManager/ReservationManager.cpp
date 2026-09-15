#include "ReservationManager.h"
#include <iostream>
#include <string>
using namespace std;

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
