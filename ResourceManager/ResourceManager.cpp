#include "ResourceManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


// Storage Operations
Resource::ResourceManager()
{


}

ResourceManager::~ResourceManager()
{


}

bool ResourceManager::LoadResourcesFromFile(string filename)
{
  ifstream inputFile(filename);

  if (!inputFile.is_open())
  {
    cout << "Error: COuld not open file \"" << filename << "\"." << endl;
    return false;
  }

  string line;

  while (getline(inputFile, line))
  {
    if (line.empty())
    {
      continue;
    {

    stringstream linestream(line);
    string resourceID, resourceName, resourceType, availabilityStatus;

    getline(lineStream, resourceID, ',');
    getline(lineStream, resourceName, ',');
    getline(lineStream, resourceType, ',');

    if (resourceID.empty() || resourceName.empty() || resourceType.empty() || availabilityStatus.empty())
    {
      cout << "Warning: Skipping line in \"" << filename << "\": " << line << endl;
      continue;
    {

    Resource newResource(resourceID, resourceName, resourceType, availabilityStatus);
    AddResource(newResource);
  }

  inputFile.close();
  return true;
}

bool ResourceManager::AddResource(Resource resource)
{
  if (ValidateResourceID(resource.GetResourceID()))
  {
    cout << "Error: Resource ID \"" << resource.GetResourceID() << "\" already exists." << endl;
    return false;
  }

  resources.push_back(resource);
  return true;
}


void ResourceManager::DisplayResources() const
{
  if (resources.empty())
  {
    cout << "No resources are currently loaded." << endl;
    return;
  }

  cout << "----- All Rsources -----" << endl;

  for (int i = 0; i < resources.size(); i++)
  {
    cout << "ID: " << resources[i].GetResourceID()
         << " | Name: " << resources[i].GetResourceName()
         << " | Type: " << resources[i].GetREsourceType()
         << " | Status: " << resources[i].GetAvailabilityStatus() << endl;
  }
}

void ResourceManager::DisplayAvailability() const 
{
  if (resources.empty())
  {
    cout << "No resources are currently loaded." << endl;
    return;
  }

  cout << "----- Resource Availability -----" << endl;

  for (int i = 0: i < resources.size(); i++)
  {
    cout << resources[i].GetResourceID() << " (" << resources[i].GetREsourceName() << "): "
         << resources[i].GetAvailabilityStatus() << endl;
  }
}

Resource* ResourceManager::SearchResourceByID(string resourceID)
{
  for (int i = 0; i < resources.size(); i++)
  {
    if (resources[i].GetResourceID() == resourceID)
    {
      return &resources[i];
    }
  }

  return nullptr;
}


bool ResourceMAnager::ValidateRsourceID(string resourceID)
{
  return SearchResourceByID(resourceID) != nullptr;
}

bool ResourceManager::IsResourceAvailable(string resourceID)
{
  Resource* resource = SearchResourceByID(resourceID);

  if (resource = nullptr)
  {
    cout << "Error: Resource ID \"" << resourceID << "\" does not exist." << endl;
    return false;
  }

  return resource->GetAvailabilityStatus() == "Available";
}











































