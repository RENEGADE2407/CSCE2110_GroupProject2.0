#ifndef RESOURCE_H
#define RESOURCE_H
#include <iostream>
#include <string>
using namespace std;

class Resource
{
  private:

  string ResourceID;
  string ResourceName;
  string ResourceType;
  string AvailabilityStatus;

  public:

  // Default constructor
  Resource();

  // Overloaded constructor
  Resource(string resourceID, string resourceName, string resourceType, string availabilityStatus);

  // Destructor
  ~Resource();

  
