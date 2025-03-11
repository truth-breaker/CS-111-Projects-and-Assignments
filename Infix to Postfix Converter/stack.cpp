#include <iostream>
#include <cstdlib>
#include "stack.h"
#include <string>

using namespace std;

// Default Constructor - Initializes an empty stack
Stack::Stack() {
    top = -1; // -1 indicates the stack is empty
}

// Checks if the stack is empty
bool Stack::isEmpty() {
    return (top == -1); // If top is -1, the stack is empty
}

// Returns the top element of the stack without removing it
el_t Stack::topElem() {
    if (isEmpty()) {
        stackError("Stack underflow: No elements to return.");
    }
    return el[top]; // Return the element at the top
}

// Displays all elements from top to bottom
void Stack::displayAll() {
    if (isEmpty()) {
        cout << "[empty]" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << el[i] << endl; // Print each element from top to bottom
        }
    }
}

// Clears the stack by resetting top index
void Stack::clearIt() {
    top = -1; // Simply reset top to -1 (logical removal of elements)
}

// Checks if the stack is full
bool Stack::isFull() {
    return (top == MAX - 1); // If top reaches MAX-1, stack is full
}

// Pushes an element onto the stack
void Stack::push(el_t e) {
    if (isFull()) {
        stackError("Stack overflow: Cannot push element.");
    } else {
        el[++top] = e; // Increment top and store element
    }
}

// Pops an element from the stack and returns it
el_t Stack::pop() {
    if (isEmpty()) {
        stackError("Stack underflow: Cannot pop element.");
    }
    return el[top--]; // Return top element and decrement top
}

// Handles stack-related errors and exits program
void Stack::stackError(string msg) const {
    cout << "Error: " << msg << endl;
    exit(1); // Terminate the program with an error code
}
