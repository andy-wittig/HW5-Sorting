#ifndef SORT_INTERFACE 
#define SORT_INTERFACE 

template<class ItemType>
class SortInterface {
public:
    virtual void sort(vector<ItemType>& data) = 0;
    virtual int getComparisons() = 0;
    virtual int getSwaps() = 0;
    virtual double getRuntime() = 0;
    virtual void resetInformation() = 0;
    virtual ~SortInterface() {};
};

#endif