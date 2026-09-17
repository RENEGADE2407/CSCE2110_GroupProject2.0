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
  this->ResourceType = resourcetype;
}

void Resource::SetAvailabilityStatus(string availabilityStatus)
{
  this->AvailabilityStatus = availabilityStatus;
}





















