#include "ResourceManager.h"
#include "../ReservationManager/ReservationManager.h"
#include "../WaitingList/WaitingList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void ResourceManager::QuickSort(int low, int high)
{
    //this checks if there are still 2 or more resourcees to sort
    if (low < high)
    {
        //partitions resources and gets pivots final position
        int pivotIndex = Partition(low, high);

        //this sorts the resources left of the pivot
        QuickSort(low, pivotIndex - 1);

        //sorts the resources on right of the pivot
        QuickSort(pivotIndex + 1, high);
        
    }
}

int ResourceManager::Partition(int low, int high)
{
    /*the request count of the last resource = the pivot,
    resources with more requests will be moved to left of the pivot
    others will be moved to the right of the pivot*/
    int pivot = resources[high].GetRequestCount();

    //i will keep track of where the next resource that comes before the pivot should be placed
    int i = low -1;

    //this will go thru each resource before the pivot
    for (int j = low; j < high; ++j)
    {
         //if resource has more requests than pivot increment i and swap resource into that spot
         if (resources[j].GetRequestCount() > pivot)
         {
             ++i;

             swap(resources[i], resources[j]);
         }
    }

    //this moves the pivot into its sorted location
    swap(resources[i + 1], resources[high]);

    return i + 1;
}

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

void ResourceManager::SortResourcesByRequestCount()
{
    //this starts the quicksort using the first and last resource
    if (resources.size() > 1)
    {
        QuickSort(0, resources.size() - 1);
    }
}

void ResourceManager::SetRequestCount(string resourceID, int count)
{
    for (int i = 0; i < resources.size(); ++i)
        {
            if(resources[i].GetResourceID() == resourceID)
            {
                resources[i].SetRequestCount(count);
                return;
            }
        }
}

//this will add all the irequests and the students in a waiting list for a resource then repeat for every resource
void ResourceManager::CalculateAllRequestCounts(ReservationManager& reservationManager, WaitingList& waitingList)
{
    //this goes thru every resource
    for(int i = 0; i < resources.size(); ++i)
        {
            //gets id of the current resource
            string resourceID = resources[i].GetResourceID();

            //gets number of active reservation
            int reservationCount = reservationManager.CountReservedResources(resourceID);

            //gets the num of students in a waiting list for a resource
            int waitingCount = waitingList.CountWaitingForResource(resourceID);

            //adds them together
            int totalRequestCount = reservationCount + waitingCount;

            //store total in resource info
            resources[i].SetRequestCount(totalRequestCount);
        }
}
