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

  public:

  ResourceManager();

  `ResourceMAnager();

  bool LoadResourcesFromFile(string filename);

  bool AddResource(Resource resource);

  void DisplayResources() const;

  void DisplayAvailability() const;

  Resource* SearchResourceByID(string resourceID);

  bool ValidateResourceID(string resourceID);

  bool IsResourceAvailable(string resourceID);

  bool SetResourceAvailability(string resourceID, string availabilityStatus);

};

#endif
