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
  int RequestCount;

  public:

  // Default constructor
  Resource();

  // Overloaded constructor
  Resource(string resourceID, string resourceName, string resourceType, string availabilityStatus);

  // Destructor
  ~Resource();

  // Mutators
  void SetResourceID(string resourceID);

  void SetResourceName(string resourceName);

  void SetResourceType(string resourceType);

  void SetAvailabilityStatus(string availabilityStatus);

  void SetRequestCount(int count);
  
  //Accessors
  string GetResourceID() const;

  string GetResourceName() const;

  string GetResourceType() const;

  string GetAvailabilityStatus() const;

  int GetRequestCount() const;



  bool IsAvailable() const;

};

#endif





