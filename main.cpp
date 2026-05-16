#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ShoppingList {
private:
    string fileName;
    vector<string> items;

public:
    ShoppingList(const string& file) {
        fileName = file;
    }

    void addItem() {
        string item;

        cout << "Enter an item (type EXIT to stop): ";
        cin.ignore();
        getline(cin, item);

        while (item != "EXIT") {
            items.push_back(item);

            cout << "Enter another item (type EXIT to stop): ";
            getline(cin, item);
        }

        saveItems();
    }

    void saveItems() {
        ofstream file(fileName, ios::app);

        if (!file.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }

        for (const string& item : items) {
            file << item << endl;
        }

        file.close();
        items.clear();

        cout << "Items saved successfully." << endl;
    }

    void listItems() {
        ifstream file(fileName);
        string line;

        if (!file.is_open()) {
            cout << "Could not open file." << endl;
            return;
        }

        cout << "\n--- Shopping List ---\n";

        while (getline(file, line)) {
            cout << "- " << line << endl;
        }

        file.close();
    }

    void removeItem() {
        vector<string> currentItems;
        ifstream file(fileName);
        string line;

        while (getline(file, line)) {
            currentItems.push_back(line);
        }

        file.close();

        if (currentItems.empty()) {
            cout << "Shopping list is empty." << endl;
            return;
        }

        cout << "\n--- Current Items ---\n";

        for (size_t i = 0; i < currentItems.size(); i++) {
            cout << i + 1 << " - " << currentItems[i] << endl;
        }

        int itemNumber;

        cout << "Enter the item number to remove: ";
        cin >> itemNumber;

        if (itemNumber < 1 || itemNumber > currentItems.size()) {
            cout << "Invalid item." << endl;
            return;
        }

        currentItems.erase(currentItems.begin() + (itemNumber - 1));

        ofstream outFile(fileName);

        for (const string& item : currentItems) {
            outFile << item << endl;
        }

        outFile.close();

        cout << "Item removed successfully." << endl;
    }

    void editItem() {
        vector<string> currentItems;
        ifstream file(fileName);
        string line;

        while (getline(file, line)) {
            currentItems.push_back(line);
        }

        file.close();

        if (currentItems.empty()) {
            cout << "Shopping list is empty." << endl;
            return;
        }

        cout << "\n--- Current Items ---\n";

        for (size_t i = 0; i < currentItems.size(); i++) {
            cout << i + 1 << " - " << currentItems[i] << endl;
        }

        int itemNumber;

        cout << "Enter the item number to edit: ";
        cin >> itemNumber;

        if (itemNumber < 1 || itemNumber > currentItems.size()) {
            cout << "Invalid item." << endl;
            return;
        }

        cin.ignore();

        string newItem;

        cout << "Enter the new item name: ";
        getline(cin, newItem);

        currentItems[itemNumber - 1] = newItem;

        ofstream outFile(fileName);

        for (const string& item : currentItems) {
            outFile << item << endl;
        }

        outFile.close();

        cout << "Item updated successfully." << endl;
    }
};

int main() {
    ShoppingList shoppingList("shopping_list.txt");

    int option;

    do {
        cout << "\n=== Shopping List Manager ===\n";
        cout << "1 - Add items\n";
        cout << "2 - List items\n";
        cout << "3 - Remove item\n";
        cout << "4 - Edit item\n";
        cout << "5 - Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                shoppingList.addItem();
                break;

            case 2:
                shoppingList.listItems();
                break;

            case 3:
                shoppingList.removeItem();
                break;

            case 4:
                shoppingList.editItem();
                break;

            case 5:
                cout << "Closing program..." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
        }
    } while (option != 5);

    return 0;
}
