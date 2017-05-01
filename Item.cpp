#include <iostream>
#include "Item.hpp"

tItem::tItem(){
    //Default constructor
}
tItem::tItem(unsigned long inputId, string inputName, float inputCost, int inputQuantity){
    id = inputId;
    name = inputName;
    cost = inputCost;
    quantity = inputQuantity;
}

unsigned long tItem::getId(void){
    return id;
}
void tItem::setId(unsigned long inputValue){
    id=inputValue;
}
string tItem::getName(void){
    return name;
}
void tItem::setName(string inputValue){
    name=inputValue;
}

float tItem::getCost(void){
    return cost;
}
void tItem::setCost(float inputValue){
    cost=inputValue;
}
int tItem::getQuantity(void){
    return quantity;
}
void tItem::setQuantity(int inputValue){
    quantity=inputValue;
}
void tItem::printItemList(void){
	// Prints each item in this format
    cout << "\nID of item: " << id << endl;
    cout << "Name of item: " << name << endl;
    cout << "Item cost: $" << cost << endl;
    cout << "Amount of items: " << quantity << endl;
}
bool tItem::operator==(const tItem& rhs) const
{
    if(id == rhs.id)
        return true;
    else
        return false;
}
bool tItem::operator<( const tItem& rhs) const
{
    if(id < rhs.id)
        return true;
    else
        return false;
}

bool compareName(tItem item1, tItem item2) 
// Custom function for comparing strings
{
    return (item1.getName() < item2.getName());
}