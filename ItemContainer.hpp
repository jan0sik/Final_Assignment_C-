/* Header file for class ItemContainer */

#ifndef ITEMCONTAINER_HPP_INCLUDED
#define ITEMCONTAINER_HPP_INCLUDED
#include <fstream>
#include <vector>
#include "Item.hpp"

using namespace std;

class ItemContainer{
    private:
        vector<tItem> itemlist;

    public:
        void addItem(tItem inputItem);
        void printItemList(void);
        void deleteItemId(void);
        void printFormatedOutput(ofstream& out);
        void readFormatedInput(ifstream& myin);
        void findItemById(int id);
        void sortItemById(void);
        void findItemByName(string name);
        void sortItemByName(void);
};

#endif // ITEMCONTAINER_HPP_INCLUDED
