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
