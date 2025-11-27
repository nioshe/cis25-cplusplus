#include <iostream>
#include <string>
using namespace std;

// Struct for inventory item
struct Item {
    string name;
    int id;
};

// Binary search function to find item by ID
int binarySearch(Item arr[], int size, int targetID) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].id == targetID) {
            return mid;
        }
        else if (arr[mid].id > targetID) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1; // Not found
}

int main() {

    int size = 100;

    // Dynamically allocate array
    Item* inventory = new Item[size];

    // Fill array with sample sorted data (ID = 1 to 100)
    for (int i = 0; i < size; i++) {
        inventory[i].id = i + 1;  // Sorted IDs
        inventory[i].name = "Item_" + to_string(i + 1);
    }

    // Ask user for ID to search for
    int searchID;
    cout << "Enter an item ID to search (1 - 100): ";
    cin >> searchID;

    // Perform binary search
    int index = binarySearch(inventory, size, searchID);

    if (index != -1) {
        cout << "\nItem found!\n";
        cout << "Name: " << inventory[index].name << endl;
        cout << "ID: " << inventory[index].id << endl;
    }
    else {
        cout << "\nItem not found." << endl;
    }

    // Free memory
    delete[] inventory;

    return 0;
}
