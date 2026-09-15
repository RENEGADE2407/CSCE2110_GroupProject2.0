#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
using namespace std;


class Reservation
{
	private:
	
	int ReservationID;
	int StudentID;
	string StudentName;
	string ResourceID;
	string ReservationDate;
	
	public:
	
	//default constructor
	Reservation();
	
	//overloaded constructor
	Reservation(int reservationID, int studentID, string studentName, string resourceID, string reservationDate);
	
	//destructor
	~Reservation();
	
	//mutators
	void SetReservationID(int reservationID);
	
	void SetStudentID(int studentID);
	
	void SetStudentName(string studentName);
	
	void SetResourceID(string resourceID);
	
	void SetReservationDate(string reservationDate);
	
	//accessors
	int GetReservationID() const;
	
	int GetStudentID() const;
	
	string GetStudentName() const;
	
	string GetResourceID() const;
	
	string GetReservationDate() const;
	
};


#endif
	