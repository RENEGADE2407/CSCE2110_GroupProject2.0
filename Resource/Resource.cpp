#include "Resource.h"
#include <iostream>
using namespace std;

// Default Constructor (fills every field with a placeholder)
Resource::Resource()
{
  ResourceID = "empty";
  ResourceName = "empty";
  ResourceType = "empty";
  AvailabilityStatus = "Available";
  RequestCount = 0;
}
// Overloaded Constructor
Resource:: Resource(string resourceID, string resourceName, string resourceType, string availabilityStatus)
{
  this->ResourceID = resourceID;
  this->ResourceName = resourceName;
  this->ResourceType = resourceType;
  this->AvailabilityStatus = availabilityStatus;
}

//Destructor
Resource::~Resource()
{


}

// Mutators
void Resource::SetResourceID(string resourceID)
{
  this->ResourceID = resourceID;
}

void Resource::SetResourceName(string resourceName)
{
  this->ResourceName = resourceName;
}

void Resource::SetResourceType(string resourceType)
{
    this->ResourceType = resourceType;
}

void Resource::SetAvailabilityStatus(string availabilityStatus)
{
  this->AvailabilityStatus = availabilityStatus;
}

void Resource::SetRequestCount(int count)
{
  this->RequestCount = count;
}

// Accessors
string Resource::GetResourceID() const
{
  return this->ResourceID;
}

string Resource::GetResourceName() const
{
  return this->ResourceName;
}

string Resource::GetResourceType() const
{
  return this->ResourceType;
}

string Resource::GetAvailabilityStatus() const
{
  return this->AvailabilityStatus;
}

int Resource::GetRequestCount() const
{
  return this->RequestCount;
}

// Availiability check
bool Resource::IsAvailable() const
{
  return this->AvailabilityStatus == "Available";
}






















