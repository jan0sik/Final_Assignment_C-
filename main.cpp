/* Description: A small menu driven inventory management system for a small 
   convenient store. Your application shall maintain the following item 
   information. This program was compiled in C++11, since I used range-based for loops.
   Written by: Matt Topor
   Date: 05/01/2017
*/

#include <iostream>
#include <fstream>
#include "ItemContainer.hpp"
using namespace std;

#define FILE_NAME   "itemlist.txt"

int menu(void);
void readItemData(ItemContainer& itemCon);
void readItemInfoToFile(ItemContainer& itemCon);
void writeItemInfoToFile(ItemContainer& itemCon);

int main()
{
    ItemContainer itemContainer;
    int selection;
    unsigned long id;
    string name;

    readItemInfoToFile(itemContainer); // Runs function to read data from file

    do{
        selection = menu();

        switch (selection)
        {
            case 1:
                readItemData(itemContainer); // Runs function to get item info
                break;
            case 2:
                itemContainer.printItemList(); // Runs function to print all items
                break;
            case 3:
                cout<<"Enter the ID to search: ";
                cin >> id;
                itemContainer.findItemById(id); // Runs function to find for item by ID
                break;
            case 4:
                itemContainer.sortItemById(); // Runs function to sort all items by ID
                break;
            case 5:
                cout<<"Enter the name to search: ";
                getline (cin>>ws, name);
                itemContainer.findItemByName(name); // Runs functions to find for item by name
                break;
            case 6:
                itemContainer.sortItemByName(); // Runs functions to sort all items by name
                break;
            case 7:
                itemContainer.deleteItemId(); // Runs function to delete item by ID
                break;
            case 8:
                cout << "Goodbye!" << endl; // Exit
                break;
            default:
                cout << "Error: Please enter a valid selection." << endl; // Error Handling
                break;
        }
    } while(selection != 8);

    writeItemInfoToFile(itemContainer); // Runs function to save data to file
    return 0;
}

int menu(void){
    // Menu options
    int menuSelection = 0;

    cout << "\n\tInventory Management System" << endl;
    cout << "1. Add new item" << endl;
    cout << "2. Print item list" << endl;
    cout << "3. Find item by ID" << endl;
    cout << "4. Sort item by ID" << endl;
    cout << "5. Find item by name" << endl;
    cout << "6. Sort item by name" << endl;
    cout << "7. Remove an item by ID" << endl;
    cout << "8. Quit" << endl;
    cout << "\nSelect: ";
    cin.clear();
    cin >> menuSelection;

    return menuSelection;
}

void readItemData(ItemContainer& itemCon){
    // Read item data
    unsigned long id;
    string name;
    float cost;
    int quantity;

    cout << "\nPlease enter id of item: ";
    cin >> id;
    cout << "Please enter name of item: ";
    getline (cin>>ws, name);
    cout << "Please enter cost of item: ";
    cin >> cost;
    cout << "Please enter quantity of items: ";
    cin >> quantity;
    tItem* temp = new tItem;
    temp->setId(id);
    temp->setName(name);
    temp->setCost(cost);
    temp->setQuantity(quantity);

    itemCon.addItem(*temp);

    delete temp;
}

void readItemInfoToFile(ItemContainer& itemCon){
    // Read info from file
    ifstream myin(FILE_NAME);

    if(myin.is_open())
    {
        itemCon.readFormatedInput(myin);
    }
    else{
        cout << "No text file exists! Creating..." << endl;
    }
    myin.close();
}

void writeItemInfoToFile(ItemContainer& itemCon){
    // Write info to file
    ofstream myout(FILE_NAME);

    if(myout.is_open())
    {
        itemCon.printFormatedOutput(myout);
    }
    myout.close();
}
