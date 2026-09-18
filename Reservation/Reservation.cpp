#include "Reservation.h"
#include <iostream>
using namespace std;

//default
Reservation::Reservation()
{
	ReservationID = 0;
	StudentID = 0;
	StudentName = "empty";
	ResourceID = "empty";
	ReservationDate = "empty";
}

//overloaded constructor
Reservation::Reservation(int reservationID, int studentID, string studentName, string resourceID, string reservationDate)
{
	this->ReservationID = reservationID;
	this->StudentID = studentID;
	this->StudentName = studentName;
	this->ResourceID = resourceID;
	this->ReservationDate = reservationDate;
}

//destructor
Reservation::~Reservation()
{
	
}
	
//mutators
void Reservation::SetReservationID(int reservationID)
{
	this->ReservationID = reservationID;
}

void Reservation::SetStudentID(int studentID)
{
	this->StudentID = studentID;
}

void Reservation::SetStudentName(string studentName)
{
	this->StudentName = studentName;
}

void Reservation::SetResourceID(string resourceID)
{
	this->ResourceID = resourceID;
}

void Reservation::SetReservationDate(string reservationDate)
{
	this->ReservationDate = reservationDate;
}


//accessors
int Reservation::GetReservationID() const
{
	return this->ReservationID;
}

int Reservation::GetStudentID() const
{
	return this->StudentID;
}

string Reservation::GetStudentName() const
{
	return this->StudentName;
}

string Reservation::GetResourceID() const
{
	return this->ResourceID;
}

string Reservation::GetReservationDate() const
{
	return this->ReservationDate;
}
