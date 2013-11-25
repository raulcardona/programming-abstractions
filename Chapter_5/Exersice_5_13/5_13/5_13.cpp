
/*
 * File: 5_13.cpp
 * -------------
 * This program diplays the reverse of a queue
 *
 */

/* Imports */
#include <iostream>
#include <fstream>
#include "stack.h"
#include "simpio.h"
#include "strlib.h"
#include "queue.h"
#include "benfile.h"

/* Function Prototypes */
void reverseQueue(Queue<string> & queue);
void printQueue(Queue<string> queue);

/* main */
int main() {
    std::ifstream inFile;
    Queue<string> queue;
    std::string fileName = promptUserForFile(inFile, "Enter a file to reverse: ");
    std::string line;
    while (getline(inFile, line)) {
        queue.enqueue(line);
    }
    reverseQueue(queue);
    printQueue(queue);
    return 0;
}

/* functions */

void reverseQueue(Queue<string> & queue) {
    int size = queue.size();
    Stack<std::string> stack;
    for (int i = 0; i < size; i++) {
        stack.push(queue.dequeue());
    }
    queue.clear();
    for (int i = 0; i < size; i++) {
        queue.enqueue(stack.pop());
    }
}

void printQueue(Queue<string> queue) {
    int size = queue.size();
    for (int i = 0; i < size; i++) {
        std::cout << queue.dequeue() << std::endl;
    }
}