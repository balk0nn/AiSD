#include "../Headers/Calculator.h"

// Constructor
Calculator::Calculator() {
    operands;
    operators;
}

int Calculator::evaluate(std::string expression) {
    int toPush = 0;
    bool wasDigit = false;
    bool negative = false;
    int a;
    int b;

    for (std::size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (std::isdigit(c)) {
            wasDigit = true;
            toPush = toPush * 10 + (c - '0');

        } else if (c == '-' && (i + 1 < expression.size()) && isdigit(expression[i + 1])) {

            wasDigit = false;  // Reset the flag
            toPush = 0;  // Reset the number
            negative = true;
            continue;

        } else if (isOperator(c)) {
            if (wasDigit) {
                negative ? operands.Push(-toPush): operands.Push(toPush);
                wasDigit = false;
                negative = false;
                toPush = 0;
            }

            b = operands.getTop();
            operands.pop();

            if (operands.isEmpty()) {
                throw std::runtime_error("no operands");
            }

            a = operands.getTop();
            operands.pop();

            operands.Push(calculate(a, b, c));

        } else {
            if (wasDigit) {
                negative ? operands.Push(-toPush): operands.Push(toPush);
                wasDigit = false;
                negative = false;
                toPush = 0;
            }
        }
    }

    if (operands.getSize() != 1) {
        throw std::runtime_error("not 1 number left in stack");
    }

    return operands.getTop();
}

bool Calculator::isOperator(char token) {
    return operators.find(token) != operators.end();
}

int Calculator::calculate(int operand_1, int operand_2, char Operator) {
    switch (Operator) {
        case '+':
            return operand_1 + operand_2;
        case '-':
            return operand_1 - operand_2;
        case '*':
            return operand_1 * operand_2;
        case '/':
            if (operand_2 == 0) {
                throw std::runtime_error("Division by 0");
            }
            return operand_1 / operand_2;

        default:
            throw std::runtime_error("Invalid operator");
    }
}