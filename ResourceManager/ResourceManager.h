#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Resource/Resource.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

  void SortResourcesByName();

  void SetRequestCount(string resourceID, int count);

};

#endif
