/* Header file for class tItem */

#ifndef ITEM_HPP_INCLUDED
#define ITEM_HPP_INCLUDED
#include <string>

using namespace std;

class tItem{
    private:
        unsigned long id;
        string name;
        float cost;
        int quantity;

    public:
        tItem();
        tItem(unsigned long inputId, string inputName, float inputCost, int inputQuantity);
        unsigned long getId(void);
        void setId(unsigned long inputValue);
        string getName(void);
        void setName(string inputValue);
        float getCost(void);
        void setCost(float inputValue);
        int getQuantity(void);
        void setQuantity(int inputValue);
        void printItemList(void);
        bool operator==(const tItem& rhs) const;
        bool operator<( const tItem& rhs) const;
};

bool compareName(tItem item1, tItem item2);

#endif // ITEM_HPP_INCLUDED
