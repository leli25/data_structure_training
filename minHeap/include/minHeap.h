#ifndef MINHEAP_H
#define MINHEAP_H

#include <cassert>
using namespace std;

template<typename Item>
class MinHeap {
private:
    Item* data;
    int count;
    int capacity;
    
    void shiftUp(int i) {
        Item v = data[i];
        while(i>1 && v < data[i/2]) {
            data[i] = data[i/2];
            i /= 2;
        }
        data[i] = v;
    }
    
    void shiftDown(int i) {
        while(2*i <= count) {
            int j = 2*i;
            if(j+1<=count && data[j]>data[j+1])
                j += 1;
            if(data[i] <= data[j]) break;
            swap(data[i], data[j]);
            i = j;
        }
    }
public:
    MinHeap(int capacity) {
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }
    
    ~MinHeap() {
        delete[] data;
    }
    
    void insert(Item v) {
        assert(count < capacity);
        data[count+1] = v;
        count++;
        shiftUp(count);
    }
    
    Item extractItem() {
        assert(count > 0);
        Item ret = data[1];
        data[1] = data[count];
        count--;
        shiftDown(1);
        
        return ret;
    }
};

#endif