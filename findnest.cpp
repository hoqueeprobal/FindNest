#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item
{
private:
    int id;
    string name;
    string category;
    string foundLocation;

public:
    Item(int i, string n, string c, string f)
    {
        id = i;
        name = n;
        category = c;
        foundLocation = f;
    }

    Item() : id(0), name(""), category(""), foundLocation("") {}

    int getId() const { 
        return id; 
        
    }
    string getName() const { 
        return name; 
        
    }
    string getCategory() const { 
        return category; 
        
    }
    string getFoundLocation() const { 
        return foundLocation; 
        
    }

    bool operator<(const Item &other) const
    {
        return category < other.category;
    }
};

class LostFoundRegistry
{
private:
    vector<Item> items;

    // Checks whether the given ID already exists
    bool idExists(int id) const
    {
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getId() == id)
                return true;
        }
        return false;
    }

    void merge(vector<Item> &arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Item> leftArr(n1), rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftArr[i] < rightArr[j])
                arr[k++] = leftArr[i++];
            else
                arr[k++] = rightArr[j++];
        }

        while (i < n1)
            arr[k++] = leftArr[i++];

        while (j < n2)
            arr[k++] = rightArr[j++];
    }
   // Recursive merge sort function to sort items by category
    void mergeSort(vector<Item> &arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

public:
    // Adds a new item and prevents duplicate ID entry
    void addItem()
    {
        int id;
        string name, category, foundLocation;
        
        while (true)
        {
            cout << "Enter ID: ";
            cin >> id;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input. Enter numeric ID.\n";
                continue;
            }
        // Duplicate ID check
            if (idExists(id))
            {
                cout << "ID already exists, Please enter a different ID\n";
                continue;
            }

            cin.ignore(100, '\n');
            break;
        }

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Category: ";
        getline(cin, category);

        cout << "Enter Found Location: ";
        getline(cin, foundLocation);

        items.push_back(Item(id, name, category, foundLocation));
        cout << "Item added successfully!" << endl;
    }
    
// Removes an item using its ID
    void removeItem()
    {
        int id;
        bool found = false;

        cout << "Enter ID to remove: ";
        cin >> id;

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getId() == id)
            {
                items.erase(items.begin() + i);
                found = true;
                break;
            }
        }

        if (found)
            cout << "Item removed successfully!" << endl;
        else
            cout << "No item found with this ID." << endl;
    }
    
// Displays all items grouped by category
    void displayAll()
    {
        if (items.empty())
        {
            cout << "No data found." << endl;
            return;
        }

        vector<Item> sortedItems = items;
        mergeSort(sortedItems, 0, sortedItems.size() - 1);

        cout << "\n--- Items Grouped by Category ---" << endl;
        string currentCategory = "";

        for (int i = 0; i < sortedItems.size(); i++)
        {
            if (sortedItems[i].getCategory() != currentCategory)
            {
                currentCategory = sortedItems[i].getCategory();
                cout << "\nCategory: " << currentCategory << endl;
            }

            cout << "ID: " << sortedItems[i].getId()
                 << " | Name: " << sortedItems[i].getName()
                 << " | Found Location: " << sortedItems[i].getFoundLocation() << endl;
        }
    }
};

int main()
{
    LostFoundRegistry registry;
    int choice;

    do
    {
        cout << "\n\t\t\t FindNest" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Display All Items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Try again." << endl;
            choice = -1;
        }
        else
        {
            if (choice == 1)
                registry.addItem();
            else if (choice == 2)
                registry.removeItem();
            else if (choice == 3)
                registry.displayAll();
            else if (choice == 0)
                cout << "Exiting..." << endl;
            else
                cout << "Wrong choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
