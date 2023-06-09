#include "../Headers/main.h"
using namespace std;

int main() {
    string expression;
    while (true) {
        InfixCalc calc = InfixCalc();
        cout << "Enter an infix expression, or 'quit' to leave" << endl;
        getline(cin, expression);
        if (expression != "quit") {
            cout << calc.evaluateInfix(expression) << endl;
        }else{
            exit(0);
        }
    }
}