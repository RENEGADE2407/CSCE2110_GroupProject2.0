#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Resource/Resource.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ReservationManager;
class WaitingList;

class ResourceManager
{
  private:

  vector<Resource> resources;

  void QuickSort(int low, int high);

  int Partition(int low, int high);

  public:

  ResourceManager();

  ~ResourceManager();

  bool LoadResourcesFromFile(string filename);

  bool AddResource(Resource resource);

  void DisplayResources() const;

  void DisplayAvailability() const;

  Resource* SearchResourceByID(string resourceID);

  bool ValidateResourceID(string resourceID);

  bool IsResourceAvailable(string resourceID);

  bool SetResourceAvailability(string resourceID, string availabilityStatus);

  void SortResourcesByRequestCount();

  void SetRequestCount(string resourceID, int count);

  //this will add up the reservations and the students in a waiting list for a resource then repeat for every resource
  void CalculateAllRequestCounts(ReservationManager& reservationManager, WaitingList& waitingList);

  //this will display the most requested resource
  void DispalyMostRequestedResources() const;
};

#endif
