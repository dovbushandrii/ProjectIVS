#include <math.h>
#include <stdexcept>
#include <string>

class Function {
public:
    /**
    * Variable to set precision of calculations
    * in Function::lg and Function::ln
    * functions.
    * Should be initialized at the start
    * of the programm
    */
    static double precision;

    /**
    * @brief Sum function ( a + b )
    * @author Andrii Dovbush xdovbu00
    * @param a addend
    * @param b addend
    * @returns sum of a and b
    */
    static double add(const double a, const double b) {
        return a + b;
    }

    /**
    * @brief Subtraction function ( a - b )
    * @author Andrii Dovbush xdovbu00
    * @param a minuend
    * @param b subtrahend
    * @returns difference
    */
    static double sub(const double a, const double b) {
        return a - b;
    }

    /**
    * @brief Multiplication function ( a * b )
    * @author Anton Havlovskyi
    * @param a - multiplied
    * @param b - multiplicator
    * @returns multiplicated a by b
    */
    static double mul(const double a, const double b) {
        return a * b;
    }

    /**
    * @brief Division function ( a / b )
    * @author Andrii Dovbush xdovbu00
    * @param a divided
    * @param b divider
    * @returns division a by b
    */
    static double div(const double a, const double b) {
        return a / b;
    }

    /**
    * @brief Power function ( a^b )
    * @author Andrii Dovbush xdovbu00
    * @param a base value
    * @param b power
    * @returns division a by b
    */
    static double power(const double a, const double b) {
        return pow(a, b);
    }

    //TODO description, function
    /**
    *  a^(1/b)
    * @brief Root function
    * @author Anton Havlovskyi
    * @param a rooted
    * @param b rooter
    * @returns root from a by b base
    */
    static double root(const double a, const double b) {
        double c = 1 / b;
        return pow(a, c);
    }

    /**
    * @brief Common logarithm ( lg(a) )
    * @author Andrii Dovbush xdovbu00
    * @param a argument that should be greater then 0
    * @returns power
    */
    static double lg(const double a) {
        double result = -1;
        if (a <= 0) {
            throw std::invalid_argument("mathlib::Function.lg: Argument must be greater then zero");
        }
        else {
            double newValue = 0;
            double aCopy = a;
            if (a > 1) {
                while (aCopy >= 10) {
                    aCopy = aCopy / 10;
                    newValue++;
                }
            }
            else {
                while (aCopy < 1) {
                    aCopy = aCopy * 10;
                    newValue--;
                }
            }

            while (abs(newValue - result) > precision) {
                result = newValue;
                double almostA = pow(10, newValue);
                newValue += (a - almostA) / (a * 10);
            }
        }
        return result;
    }

    /**
    * @brief Natural logarithm ( ln(a) )
    * @author Andrii Dovbush xdovbu00
    * @param a argument that should be greater then 0 and less then 2
    * @returns power
    */
    static double ln(const double a) {
        double result = 0;
        if (a <= 0) {
            throw std::invalid_argument("mathlib::Function.ln: Argument must be greater then zero");
        }
        else {
            double x = a - 1;
            double newValue = x;
            double addend = x;
            for (int i = 2; abs(newValue - result) > precision; i++) {
                result = newValue;
                addend = addend * x * (-1);
                newValue = newValue + addend / i;
            }
            result = newValue;
        }
        return result;
    }
};

//Static Variable Initialization
double Function::precision = 0.000000001;

class Equation {
public:
    //TODO description, function
    /**
    *  Solves equation
    * @brief
    * @author
    * @param equation
    * @returns
    */
    static double solveEquation(std::string equation) {
        return 0;
    }
};