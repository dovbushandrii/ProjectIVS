//============================================================================//
/*
* IVS, Project 2 solution
* Authors: xhavlo01 xdovbu00 xhaltm02 xkolar80
* GNU General Public License v3
*/
//============================================================================//
/**
* @file profiling.cpp
* @brief test program to test Math library
* @author Andrii Dovbush, xdovbu00
* @author Anton Havlovskyi, xhavlo01
* @author Ondřej Kolařík, xkolar80
* @author Adam Haltmar, xhaltm02
*/
//============================================================================//

#include "../Mathlib/mathlib.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> value;
    double number = 0, result = 0, summ = 0;
    while (cin >> number) {
        value.push_back(number);
        summ = Function::add(summ, number);
    }

    if (value.size()) {
        double mean = Function::div(summ, (double)value.size());
        summ = 0;

        for (size_t i = 0; i < value.size(); i++) {
            double squareOfDiff = Function::power(Function::sub(value[i], mean), 2.0);
            summ = Function::add(summ, squareOfDiff);
        }

        result = Function::div(summ, (double)(value.size() - 1));
        result = Function::sqrt(result);
    }

    cout << "Standard deviation(For " << value.size() << " values): " << result;
    return 0;
}

