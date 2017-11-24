#ifndef INDEXHEAP_H
#define INDEXHEAP_H

#include <cassert>

using namespace std;

template<typename Item>
class IndexHeap {
private:
    Item* data;
    int* indexes;
    int* reverse;
    int capacity;
    int count;
    
    void shiftUp(int i) {
        while(i > 1 && data[indexes[i]]>data[indexes[i/2]]) {
            swap(indexes[i], indexes[i/2]);
            reverse[indexes[i]] = i;
            reverse[indexes[i/2]] = i/2;
            i /= 2;
    }
    
    void shiftDown(int i) {
        while(2*i <= count) {
            int j = 2*i;
            if(j+1<=count && data[indexes[j+1]]>data[indexes[j]])
                j++;
            if(data[indexes[j]] <= data[indexes[i]]) break;
            swap(indexes[j], indexes[i]);
            reverse[indexes[j]] = j;
            reverse[indexes[i]] = i;
            i = j;
        }
    }
    
public:
    //constructor
    IndexHeap(int capacity) {
        this->capacity = capacity;
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for(int i=0; i<capacity; i++)
            reverse[i] = 0;
        count = 0;
    }
    
    //
    bool contain(int i) {
        assert(i>0 && i<=capacity);
        return reverse[i] != 0;
    }
    
    //insert an element
    void insert(int i, Item content) {
        assert(count < capacity);
        assert(!contain(i));
        count++;
        data[i] = content;
        indexes[count] = i;
        reverse[i] = count;
        shiftUp(count);
    }
    
    //extract the index of Max in data array
    int extractMaxDataIndex() {
        assert(count > 0);
        int rst = indexes[1];
        swap(indexes[1], indexes[count]);
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        
        return rst;
    }
    
    //get item by its index
    Item getItem(int index) {
        assert(contain(index));
        return data[index];
    }
};


#endif