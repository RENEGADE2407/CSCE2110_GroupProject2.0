#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include "../Reservation/Reservation.h"
#include "../Cancellation History/CancellationHistory.h"
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

	/*This will create a CancellationHistory object inside ReservationManager
	so Manager has access to cancellation stack.
	When a reservation is canccelled reservation manager can send that reservation
	to the stack*/
	CancellationHistory cancellationHistory;
	
	public:

	//********LINKED LIST OPERATIONS ********

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


	//********RESERVATION MANAGEMENT ********
	
	//this will create a new reservation
	bool CreateReservation(Reservation reservation);
	
	//this will cancel a reservation using a reservation id
	bool CancelReservation(int reservationID);

	/*this is to restore the most reecently canceled reservation by taking it from the
	stack and putting it back into the linked list
	*/
	bool UndoCancellation();

	/*this is for displaying cancellation history.*/
	void DisplaycancellationHistory() const;
	
	//this will ensure the validity of a reservation
	bool ValidateReservation(Reservation reservation);
	
	
};



#endif
