#ifndef UNTITLED5_CALCULATOR_H
#define UNTITLED5_CALCULATOR_H
#include "Stack.h"
#include <iostream>
#include <unordered_set>

class Calculator {
private:
    Stack<int> operands;
    const std::unordered_set<char> operators = {'+', '-', '*', '/'};
public:
    Calculator();
    int evaluate(std::string expression);
    bool isOperator(char token);
    int calculate(int operand_1, int operand_2, char Operator);
};


#endif //UNTITLED5_CALCULATOR_H
