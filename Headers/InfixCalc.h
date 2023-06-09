#ifndef UNTITLED5_INFIXCALC_H
#define UNTITLED5_INFIXCALC_H

#include "../Headers/Calculator.h"

class InfixCalc : public Calculator {
public:
    InfixCalc();
    int evaluateInfix(std::string& expression);
    std::string toPostfix(std::string& expression);
};

#endif
