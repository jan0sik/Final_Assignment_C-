/* Item Container file which holds item specific 
functions used to interact with items. */

#include "ItemContainer.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void ItemContainer::addItem(tItem inputItem){
    // Adds item at current count and increments
    itemlist.push_back(inputItem);
}
void ItemContainer::printItemList(void){
    // Loops through all items and executes print function
    for(int i=0;i<(int)itemlist.size();++i)
    {
        itemlist[i].printItemList();
    }
}
void ItemContainer::findItemById(int id){
    // Finds item by ID and prints item
    bool k = true;

    for (tItem iterator : itemlist ) {
        if (iterator.getId() == id) {
            iterator.printItemList();
            k = false;
        }
    }
    if (k)
        cout << "Item not found!" << endl;
}
void ItemContainer::sortItemById(void){
    // Sorts items by ID numbers
    sort(itemlist.begin(), itemlist.end());
    for(int i=0;i<(int)itemlist.size();++i)
    {
        itemlist[i].printItemList();
    }
}
void ItemContainer::findItemByName(string name){
    // Finds item by name and prints item
    bool k = true;

    for (tItem iterator : itemlist ) {
        if (iterator.getName() == name) {
            iterator.printItemList();
            k = false;
        }
    }
    if (k)
        cout << "Item not found!" << endl;
}
void ItemContainer::sortItemByName(void){
    // Sorts items by names in alphanumeric order
    sort(itemlist.begin(), itemlist.end(), compareName);
    for(int i=0;i<(int)itemlist.size();++i)
    {
        itemlist[i].printItemList();
    }
}
void ItemContainer::deleteItemId(void){
    // Searches for ID in items list, deletes the item by ID, and erases the position
    unsigned long id;

    cout << "\nEnter ID # to delete: ";
    cin >> id;
    tItem temp(id, "NA", 0.0, 0);
    vector<tItem>::iterator pos=find(itemlist.begin(), itemlist.end(), temp);
    if (pos != itemlist.end()){
        itemlist.erase(pos);
    } else {
        cout << "Item not found!" << endl;
    }
}

void ItemContainer::readFormatedInput(ifstream& myin){
    // Reads data from file based on format of *~*~*~*
    unsigned long id;
    string name;
    float cost;
    int quantity;

    for(;;)
    {
        myin >> id;
        myin.ignore(1);
        getline(myin, name, '~');
        myin >> cost;
        myin.ignore(1);
        myin >> quantity;
        if(myin.good()){
            tItem temp(id, name, cost, quantity);
            addItem(temp);
        }
        else if(myin.eof())
        {
            break;
        }
        else{
            cout << "Fatal Error!" << endl;
            break;
        }
    }

}
void ItemContainer::printFormatedOutput(ofstream& out){
    // Writes data to file in the format of *~*~*~*
    for(int i=0;i<(int)itemlist.size();++i)
    {
        out << itemlist[i].getId();
        out << '~'<< itemlist[i].getName();
        out << '~'<< itemlist[i].getCost();
        out << '~'<< itemlist[i].getQuantity() << endl;
    }
}