#include <iostream>
using namespace std;
#include "stack.h"


// Function to check if a character is an operand
bool IsOperand(char C) {
    return (C >= '0' && C <= '9') || (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z');
}

// Function to check if a character is an operator
bool IsOperator(char C) {
    return (C == '+' || C == '-' || C == '*' || C == '/' || C == '^');
}

// Function to check if an operator is right associative
bool IsRightAssociative(char op) {
    return (op == '^');  // Only exponentiation is right-associative
}

// Function to return operator precedence
int GetOperatorWeight(char op) {
    int weight = -1;
    switch (op) {
        case '+': case '-': weight = 1; break;
        case '*': case '/': weight = 2; break;
        case '^': weight = 3; break;
    }
    return weight;
}

// Function to check if op1 has higher precedence than op2
bool HasHigherPrecedence(char op1, char op2) {
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    if (op1Weight == op2Weight) {
        return !IsRightAssociative(op1); // If left-associative, return true
    }
    return op1Weight > op2Weight;
}

// Function to convert infix to postfix using a stack
string InfixToPostfix(string expression, Stack& S) {
    string postfix = "";
    
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ' || expression[i] == ',') continue; // Ignore whitespace

        // If the character is an operand, add it to postfix
        else if (IsOperand(expression[i])) {
            postfix += expression[i];
        }
        // If the character is an operator, process precedence
        else if (IsOperator(expression[i])) {
            while (!S.isEmpty() && HasHigherPrecedence(S.topElem()[0], expression[i])) {
                postfix += S.pop();
            }
           S.push(std::string(1, expression[i]));  
        }
        // If it's an opening parenthesis, push it to stack
        else if (expression[i] == '(') {
           S.push(std::string(1, expression[i]));  
        }
        // If it's a closing parenthesis, pop until '(' is found
        else if (expression[i] == ')') {
            while (!S.isEmpty() && S.topElem() != std::string(1, '(')) {
                postfix += S.pop();
            }
            S.pop(); // Remove '(' from stack
        }
    }

    // Pop any remaining operators in the stack
    while (!S.isEmpty()) {
        postfix += S.pop();
    }

    return postfix;
}

// Main function
int main() {
    string infix, postfix;
    Stack S; // Declare a stack instance
    
    cout << "Enter the infix expression: ";
    getline(cin, infix);
    
    postfix = InfixToPostfix(infix, S);
    
    cout << "The postfix expression is: " << postfix << endl;
    
    return 0;
}
