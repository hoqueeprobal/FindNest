#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <fstream> 
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
        : id(i), name(n), category(c), foundLocation(f) {}

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

    // Merge function for merge sort
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

    // Recursive merge sort
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

            if (idExists(id))
            {
                cout << "ID already exists. Please enter a different ID.\n";
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
        cout << "Item added successfully!\n";
    }

    // Removes an item using its ID
    void removeItem()
    {
        int id;
        cout << "Enter ID to remove: ";
        cin >> id;
        cin.ignore(100, '\n');

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getId() == id)
            {
                items.erase(items.begin() + i);
                cout << "Item removed successfully!\n";
                return;
            }
        }
        cout << "No item found with this ID.\n";
    }

    // Updates item details except ID
    void updateItem()
    {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;
        cin.ignore(100, '\n');

        for (int i = 0; i < items.size(); i++)
        {
            if (items[i].getId() == id)
            {
                string name, category, foundLocation;

                cout << "Enter New Name: ";
                getline(cin, name);

                cout << "Enter New Category: ";
                getline(cin, category);

                cout << "Enter New Found Location: ";
                getline(cin, foundLocation);

                items[i] = Item(id, name, category, foundLocation);
                cout << "Item updated successfully!\n";
                return;
            }
        }
        cout << "No item found with this ID.\n";
    }

    // Displays all items grouped by category
    void displayAll()
    {
        if (items.empty())
        {
            cout << "No data found.\n";
            return;
        }

        vector<Item> sortedItems = items;
        mergeSort(sortedItems, 0, sortedItems.size() - 1);

        cout << "\n--- Items Grouped by Category ---\n";

        string currentCategory = "";
        int categoryCount = 0;

        for (int i = 0; i < sortedItems.size(); i++)
        {
            if (sortedItems[i].getCategory() != currentCategory)
            {
                if (categoryCount > 0)
                {
                    cout << "Total items in this category: " << categoryCount << "\n";
                }

                currentCategory = sortedItems[i].getCategory();
                cout << "\nCategory: " << currentCategory << "\n";
                categoryCount = 0;
            }

            cout << "ID: " << sortedItems[i].getId()
                 << " | Name: " << sortedItems[i].getName()
                 << " | Found Location: " << sortedItems[i].getFoundLocation() << "\n";

            categoryCount++;
        }

        if (categoryCount > 0)
            cout << "Total items in this category: " << categoryCount << "\n";
    }

    // Searches item by ID or Name using Linear Search
    void searchItem()
    {
        string input;
        bool found = false;

        cout << "Enter Item ID or Name to search: ";
        getline(cin, input);

        // Check whether input is numeric (ID)
        bool isNumber = true;
        for (char c : input)
        {
            if (!isdigit(c))
            {
                isNumber = false;
                break;
            }
        }

        // Linear search by ID
        if (isNumber)
        {
            int id = stoi(input);
            for (int i = 0; i < items.size(); i++)
            {
                if (items[i].getId() == id)
                {
                    found = true;
                    cout << "Item Found!\n";
                    cout << "ID: " << items[i].getId()
                         << " | Name: " << items[i].getName()
                         << " | Category: " << items[i].getCategory()
                         << " | Found Location: " << items[i].getFoundLocation() << "\n";
                    break;
                }
            }
        }
        // Linear search by Name
        else
        {
            for (int i = 0; i < items.size(); i++)
            {
                if (items[i].getName() == input)
                {
                    found = true;
                    cout << "Item Found!\n";
                    cout << "ID: " << items[i].getId()
                         << " | Name: " << items[i].getName()
                         << " | Category: " << items[i].getCategory()
                         << " | Found Location: " << items[i].getFoundLocation() << "\n";
                }
            }
        }

        if (!found)
            cout << "No item found matching the search criteria.\n";
    }

    // Saves all items to a file grouped by category
    void saveToFileByCategory()
    {
        if (items.empty())
        {
            cout << "No data to save.\n";
            return;
        }

        ofstream outFile("lostfound-data.txt"); // Open file for writing
        if (!outFile)
        {
            cout << "Error opening file for saving!\n";
            return;
        }

        vector<Item> sortedItems = items;
        mergeSort(sortedItems, 0, sortedItems.size() - 1);

        string currentCategory = "";
        int categoryCount = 0;

        for (int i = 0; i < sortedItems.size(); i++)
        {
            if (sortedItems[i].getCategory() != currentCategory)
            {
                if (categoryCount > 0)
                {
                    outFile << "Total items in this category: " << categoryCount << "\n\n";
                    categoryCount = 0;
                }

                currentCategory = sortedItems[i].getCategory();
                outFile << "Category: " << currentCategory << "\n";
            }

            outFile << "ID: " << sortedItems[i].getId()
                    << " | Name: " << sortedItems[i].getName()
                    << " | Found Location: " << sortedItems[i].getFoundLocation() << "\n";

            categoryCount++;
        }

        if (categoryCount > 0)
            outFile << "Total items in this category: " << categoryCount << "\n";

        outFile.close();
        cout << "All data saved successfully to lostfound-data.txt!\n";
    }
};

int main()
{
    LostFoundRegistry registry;
    int choice;

    do
    {
        cout << "\n\t\t\t FindNest\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display All Items\n";
        cout << "4. Update Item\n";
        cout << "5. Search Item\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore(100, '\n');

        switch (choice)
        {
        case 1:
            registry.addItem();
            break;
        case 2:
            registry.removeItem();
            break;
        case 3:
            registry.displayAll();
            break;
        case 4:
            registry.updateItem();
            break;
        case 5:
            registry.searchItem();
            break;
        case 0:
            registry.saveToFileByCategory();
            cout << "Exiting...\n";
            break;
        default:
            cout << "Wrong choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
