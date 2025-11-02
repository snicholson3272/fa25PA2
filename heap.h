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
        //Start a while loop as long as pos is not the root
        while (pos > 0) {
            //Find the parent
            int parent = (pos - 1) / 2;
            //Compare weights of parent and child
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                //Swap the parent and child
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;

                //Change position to the childs new location
                pos = parent;
            }
            //If the weights are correct break the while loop
            else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        //Set up a while loop to run until we tell it to break
        while (true) {
            //Find children and set up a variable to store smallest weight
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            //For children comparisons we check to see if the parent has a child then also check the weights
            //Check with left child
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }

            //Check with right child
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            //Check if the smallest is no longer the parent
            if (smallest != pos) {
                //Swap parent downward
                int temp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = temp;

                //Set up new position to run threw the while loop
                pos = smallest;
            }
            //End loop if the parent is the smallest
            else {
                break;
            }
        }
    }
};

#endif