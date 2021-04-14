#include <math.h>
#include <stdexcept>
#include <string>

class Function {
public:
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
        if (a <= 0) {
            throw std::invalid_argument("mathlib::Function.lg: Argument must be greater then zero");
        }
        else {
            return log10(a);
        }
    }

    /**
    * @brief Natural logarithm ( ln(a) )
    * @author Andrii Dovbush xdovbu00
    * @param a argument that should be greater then 0 and less then 2
    * @returns power
    */
    static double ln(const double a) {
        if (a <= 0) {
            throw std::invalid_argument("mathlib::Function.ln: Argument must be greater then zero");
        }
        else {
            return log(a);
        }
    }
};

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