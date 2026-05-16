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
};

int main() {
    ShoppingList shoppingList("shopping_list.txt");

    int option;

    do {
        cout << "\n=== Shopping List Manager ===\n";
        cout << "1 - Add items\n";
        cout << "2 - List items\n";
        cout << "3 - Exit\n";
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
                cout << "Closing program..." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
        }

    } while (option != 3);

    return 0;
}
