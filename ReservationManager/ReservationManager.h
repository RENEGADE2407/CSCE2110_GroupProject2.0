#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;

class ReservationManager
{
	private:
	
	struct Node
	{
		Reservation reservation;
		Node* next;	//points to next node
	};
	
	//this is where the linked llist starts
	Node* head;
	
	public:

	//********LINKED LIST OPERATIONS ********\\

	//condtructorr
	ReservationManager();
	
	//destructor
	~ReservationManager();
	
	//this will add a reservation to the linked list
	bool InsertReservation(Reservation reservation);
	
	//this shall remove a reservation from the linked leist using a reservation id
	bool RemoveReservation(int reservationID);
	
	///this searches the linked list for a reservation using a reservation id
	Reservation* SearchReservation(int reservationID);
	
	//this displays all reservations in linked list
	void DisplayReservations() const;


	//********RESERVATION MANAGEMENT ********\\
	
	//this will create a new reservation
	bool CreateReservation(Reservation reservation);
	
	//this will cancel a reservation using a reservation id
	bool CancelReservation(int reservationID);
	
	//this will ensure the validity of a reservation
	bool ValidateReservation(Reservation reservation);
	
	
};



#endif
