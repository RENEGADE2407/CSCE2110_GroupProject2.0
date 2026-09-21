#include "ResourceManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// Default constructor
ResourceManager::ResourceManager()
{
}

// Destructor
ResourceManager::~ResourceManager()
{
}

// Loads resources from a text file.
// Each line should contain:
// ResourceID|ResourceName|ResourceType|AvailabilityStatus
bool ResourceManager::LoadResourcesFromFile(string filename)
{
    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error: Could not open file \"" << filename << "\"." << endl;
        return false;
    }

    string line;

    while (getline(inputFile, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream lineStream(line);

        string resourceID;
        string resourceName;
        string resourceType;
        string availabilityStatus;

        // The data file uses | as the separator
        getline(lineStream, resourceID, '|');
        getline(lineStream, resourceName, '|');
        getline(lineStream, resourceType, '|');
        getline(lineStream, availabilityStatus);

        // Skip incomplete records
        if (resourceID.empty() ||
            resourceName.empty() ||
            resourceType.empty() ||
            availabilityStatus.empty())
        {
            cout << "Warning: Skipping invalid line: "
                 << line << endl;
            continue;
        }

        Resource newResource(
            resourceID,
            resourceName,
            resourceType,
            availabilityStatus
        );

        AddResource(newResource);
    }

    inputFile.close();

    return true;
}

// Adds a resource to the vector
bool ResourceManager::AddResource(Resource resource)
{
    if (ValidateResourceID(resource.GetResourceID()))
    {
        cout << "Error: Resource ID \""
             << resource.GetResourceID()
             << "\" already exists." << endl;

        return false;
    }

    resources.push_back(resource);

    return true;
}

// Displays all resources
void ResourceManager::DisplayResources() const
{
    if (resources.empty())
    {
        cout << "No resources are currently loaded." << endl;
        return;
    }

    cout << "\n===== ALL RESOURCES =====" << endl;

    for (size_t i = 0; i < resources.size(); i++)
    {
        cout << "ID: " << resources[i].GetResourceID()
             << " | Name: " << resources[i].GetResourceName()
             << " | Type: " << resources[i].GetResourceType()
             << " | Status: " << resources[i].GetAvailabilityStatus()
             << endl;
    }
}

// Displays resource availability
void ResourceManager::DisplayAvailability() const
{
    if (resources.empty())
    {
        cout << "No resources are currently loaded." << endl;
        return;
    }

    cout << "\n===== RESOURCE AVAILABILITY =====" << endl;

    for (size_t i = 0; i < resources.size(); i++)
    {
        cout << resources[i].GetResourceID()
             << " (" << resources[i].GetResourceName() << ")"
             << ": "
             << resources[i].GetAvailabilityStatus()
             << endl;
    }
}

// Searches for a resource by ID
Resource* ResourceManager::SearchResourceByID(string resourceID)
{
    for (size_t i = 0; i < resources.size(); i++)
    {
        if (resources[i].GetResourceID() == resourceID)
        {
            return &resources[i];
        }
    }

    return nullptr;
}

// Returns true if the resource ID exists
bool ResourceManager::ValidateResourceID(string resourceID)
{
    return SearchResourceByID(resourceID) != nullptr;
}

// Checks whether a resource is available
bool ResourceManager::IsResourceAvailable(string resourceID)
{
    Resource* resource = SearchResourceByID(resourceID);

    if (resource == nullptr)
    {
        cout << "Error: Resource ID \""
             << resourceID
             << "\" does not exist." << endl;

        return false;
    }

    return resource->IsAvailable();
}

// Changes the availability status of a resource
bool ResourceManager::SetResourceAvailability(
    string resourceID,
    string availabilityStatus)
{
    Resource* resource = SearchResourceByID(resourceID);

    if (resource == nullptr)
    {
        cout << "Error: Resource ID \""
             << resourceID
             << "\" does not exist." << endl;

        return false;
    }

    resource->SetAvailabilityStatus(availabilityStatus);

    return true;
}
