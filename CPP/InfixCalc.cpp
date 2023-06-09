#include "../Headers/InfixCalc.h"
#include "../Headers/Queue.h"

InfixCalc::InfixCalc() {

}

int getPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string InfixCalc::toPostfix(std::string& expression) {
    std::string postfixExpression;
    Stack<char> operatorStack;
    Queue outputQueue;
    std::string currentNumber;  // Track the current number being parsed

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        // Check for a negative sign
        if (c == '-' && (i == 0 || expression[i - 1] == '(')) {
            currentNumber += c;  // Append the negative sign to the current number
        } else if (std::isdigit(c)) {
            currentNumber += c;  // Add digits and decimal point to the current number
        } else {
            if (!currentNumber.empty()) {
                outputQueue.push(currentNumber);  // Push the current number to the output queue
                currentNumber.clear();  // Reset the current number
            }

            if (isOperator(c)) {
                // Process operators
                while (!operatorStack.isEmpty() && operatorStack.getTop() != '(' &&
                       getPriority(c) <= getPriority(operatorStack.getTop())) {
                    outputQueue.push(std::string(1, operatorStack.getTop()));  // Push higher or equal priority operators to the output queue
                    operatorStack.pop();
                }
                operatorStack.Push(c);  // Push the current operator to the stack
            } else if (c == '(') {
                operatorStack.Push(c);  // Push opening parenthesis to the stack
            } else if (c == ')') {
                // Process closing parenthesis
                while (!operatorStack.isEmpty() && operatorStack.getTop() != '(') {
                    outputQueue.push(std::string(1, operatorStack.getTop()));  // Push operators until opening parenthesis to the output queue
                    operatorStack.pop();
                }
                if (!operatorStack.isEmpty() && operatorStack.getTop() == '(')
                    operatorStack.pop();  // Pop the opening parenthesis from the stack
                else {
                    throw std::runtime_error("Invalid expression: mismatched parentheses");
                }
            } else if (c != ' ') {
                throw std::runtime_error("Invalid expression: unknown character");
            }
        }
    }

    if (!currentNumber.empty()) {
        outputQueue.push(currentNumber);  // Push the final current number to the output queue
        currentNumber.clear();
    }

    while (!operatorStack.isEmpty()) {
        if (operatorStack.getTop() == '(') {
            throw std::runtime_error("Invalid expression: mismatched parentheses");
        }
        outputQueue.push(std::string(1, operatorStack.getTop()));  // Push remaining operators to the output queue
        operatorStack.pop();
    }

    while (!outputQueue.isEmpty()) {
        postfixExpression += outputQueue.front();  // Append characters from the output queue to the postfix expression
        outputQueue.popFront();
        if (!outputQueue.isEmpty())
            postfixExpression += ' ';  // Add space between characters if there are more in the queue
    }

    return postfixExpression;
}

int InfixCalc::evaluateInfix(std::string &expression) {
    return evaluate(toPostfix(expression));
}

