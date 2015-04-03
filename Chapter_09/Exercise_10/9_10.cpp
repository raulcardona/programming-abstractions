//
//  9_10.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/29/14.
//
//  Sort the pipes high to low.  A


#include <stdio.h>
#include "vector.h"
#include "stack.h"

int cutStock(Vector<int> requests, int stockLength);
int getNumStockNeeded(Vector<int> requests, int stockLength, Vector<int> remainingRequests, int cutSum, int numStock);
Vector<int> sortRequests(Vector<int> requests);

int main() {
    Vector<int> requests;
    requests += 4, 3, 4, 1, 7, 8;
    int stockLength = 10;
    Vector<int> temp = sortRequests(requests);
    cout << "Total Pipes Needed: " << cutStock(temp, stockLength) << endl;
    return 0;
}

int cutStock(Vector<int> requests, int stockLength) {
    return getNumStockNeeded(requests, stockLength, requests, 0, 0);
}

int getNumStockNeeded(Vector<int> requests, int stockLength, Vector<int> remainingRequests, int cutSum, int numStock) {
    if (remainingRequests.isEmpty()) {
        return numStock;
    }
    
    for (int i = 0;  i < remainingRequests.size(); i++) {
        cutSum += remainingRequests[i];
        if (cutSum == stockLength) {
            cutSum = 0; // reset
            remainingRequests.remove(i);
            return getNumStockNeeded(requests, stockLength, remainingRequests, cutSum, numStock + 1);
        } else if (cutSum > stockLength) {
            cutSum -= remainingRequests[i];
        } else {
            remainingRequests.remove(i);
            i--;
        }
    }
    return getNumStockNeeded(requests, stockLength, remainingRequests, 0, numStock + 1);
}

//Sorts the requests in descending order
Vector<int> sortRequests(Vector<int> requests) {
    Vector<int> temp;
    int count = 0;
    while (!requests.isEmpty()) {
        if (temp.isEmpty()) {
            temp.add(requests[0]);
            requests.remove(0);
        }
        for (int i = 0; i < temp.size(); i++) {
            if (requests[count] <= temp[i]) {
                temp.insert(i, requests[count]);
                requests.remove(count);
                break;
            } else if (i == temp.size() - 1){
                temp.add(requests[count]);
                requests.remove(count);
                break;
            }
        }
    }
    Stack<int> stack;
    for (int i = 0; i < temp.size(); i++) {
        stack.push(temp[i]);
    }
    while (!stack.isEmpty()) {
        requests.add(stack.pop());
    }
    
    return requests;
}





