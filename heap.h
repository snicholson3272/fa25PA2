//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        //First using size we place the idx at the end of array.
        data[size] = idx;
        //Now sent to upheap to organize in array.
        upheap(size, weightArr);
        //Adjust the size
        ++size;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        //Check to see if heap is empty
        if (size == 0) {
            return -1;
        }
        //Save value of root
        int temp = data[0];
        //Replace the root with the last element to ensure no gaps
        data[0] = data[size - 1];
        //Adjust size
        --size;
        //Send to downheap to organize
        if (size > 0) {
            downheap(0, weightArr);
        }
        //Return the removed root
        return temp;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif