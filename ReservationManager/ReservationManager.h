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
	
	
};



#endif
