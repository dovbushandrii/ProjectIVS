﻿//============================================================================//
/*
* IVS, Project 2 solution
* Authors: xhavlo01 xdovbu00 xhaltm02 xkolar80
* GNU General Public License v3
*/
//============================================================================//
/**
* @file mathlib.h
* @brief Math library
* @author Andrii Dovbush, xdovbu00
* @author Anton Havlovskyi, xhavlo01
* @author Ondřej Kolařík, xkolar80
* @author Adam Haltmar, xhaltm02
*/
//============================================================================//

#ifndef  __MATHLIB_H__

#define  __MATHLIB_H__

#include <math.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "translator.h"

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
    *  a^(1/2)
    * @brief Square root function
    * @author Andrii Dovbush
    * @param a rooted
    * @returns root from a by b base
    */
    static double sqrt(const double a) {
        return pow(a, 0.5);
    }

    /**
   *  floor(a)!
   * Finds factorial of floor(a)
   * @brief Factorial func
   * @author Andrii Dovbush
   * @param a number
   * @returns factorial of given number
   */
    static double fact(const double a) {
        if (a < 0) {
            throw std::invalid_argument("mathlib::Function.fact: Argument must be greater then or equal to zero");
        }
        int numb = (int)floor(a);
        int result = 1;
        while (numb > 1) {
            result *= numb;
            numb--;
        }
        return result;
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
private:

    static bool isDigit(char symb, const int base) {
        bool cond1 = symb >= '0';
        bool cond2 = symb == '.' || symb == ',';
        if (base < 11) {
            cond1 = cond1 && symb < base + '0';
        }
        else {
            cond1 = (cond1 && symb <= '9') || (symb >= 'A' && symb < base - 10 + 'A');
            cond1 = cond1 || (symb >= 'a' && symb < base - 10 + 'a');
        }
        if (!(cond1 || cond2)) {
            return false;
        }
        return true;
    }

    static bool operation(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'l' || c == 's' || c == '!';
    }

    static int priority(char op) {
        if (op < 0) {
            if (-op == 'l' || -op == 'L' || -op == 's') return 6;
            if (-op == '!') return 5;
            else return 3;
        }
        else {
            if (op == '+' || op == '-')return 1;
            else if (op == '*' || op == '/')return 2;
            else if (op == '^')return 4;
            else return -1;
        }
    }

    static void action(std::vector<double>& value, char op) {
        if (op < 0) {                            
            double unitar = value.back();
            value.pop_back();
            if (-op == '-') {
                value.push_back(-unitar);
            }
            else if (-op == 'l') {
                value.push_back(Function::ln(unitar));
            }
            else if (-op == 'L') {
                value.push_back(Function::lg(unitar));
            }
            else if (-op == 's') {
                value.push_back(Function::sqrt(unitar));
            }
            else if (-op == '!') {
                value.push_back(Function::fact(unitar));
            }
        }
        else {                              
            double right = value.back();
            value.pop_back();
            double left = value.back();
            value.pop_back();
            if (op == '+') {
                value.push_back(Function::add(left,right));
            }
            else if (op == '-') {
                value.push_back(Function::sub(left, right));
            }
            else if (op == '*') {
                value.push_back(Function::mul(left, right));
            }
            else if (op == '/') {
                value.push_back(Function::div(left, right));
            }
            else if (op == '^') {
                value.push_back(Function::power(left, right));
            }
        }
    }

    static double calculus(std::string equation, const int base) {
        equation = Translator::deleteSpaces(equation);
        bool unary = true;        
        std::vector<double>value;      
        std::vector<char>op;          
        for (size_t i = 0; i < equation.size(); i++) {
            if (equation[i] == '(') {
                op.push_back('(');
                unary = true;
            }
            else if (equation[i] == ')') {
                while (op.back() != '(') {  
                    action(value, op.back());
                    op.pop_back();
                }
                op.pop_back();
                unary = false;
            }
            else if (operation(equation[i])) {
                char zn = equation[i];
                if (zn == '!') {
                    unary = true;
                }
                else if (zn == 'l') {
                    i++;
                    if (equation[i] == 'g') {
                        zn = 'L';
                    }
                }
                else if (zn == 's') {
                    i += 3;
                }
                if (unary == true)zn = -zn;
                while (!op.empty() && priority(op.back()) >= priority(zn)) {
                    action(value, op.back());
                    op.pop_back();
                }
                op.push_back(zn);
                if (-zn != '!') {
                    unary = true;
                }
                else {
                    unary = false;
                }
            }
            else {
                std::string number;      
                while (i < equation.size() && isDigit(equation[i],base)) {
                    number += equation[i++];
                }
                i--;
                value.push_back(Translator::StrWithBaseToNum(number,base));
                unary = false;
            }
        }
        while (!op.empty()) {     
            action(value, op.back());
            op.pop_back();
        }
        return value.back(); 
    }

public:
    /**
    * Allowed functions:
    * a + b
    * a - b
    * a / b
    * a * b
    * a ^ b
    * sqrt(a) -> a^(1/2)
    * lg(a)   -> log10(a)
    * ln(a)   -> logE(a)
    * a! -> floor(a)!
    * @brief Solves equation writen in std:string format
    * @author Andrii Dovbush xdovbu00
    * @param equation equation writen in string format
    * @param base numerical base
    * @returns calculated result
    */
    static double solveEquation(std::string equation, const int base) {
        return calculus(equation,base);
    }

    /**
    * Allowed functions:
    * a + b
    * a - b
    * a / b
    * a * b
    * a ^ b
    * sqrt(a) -> a^(1/2)
    * lg(a)   -> log10(a)
    * ln(a)   -> logE(a)
    * a! -> floor(a)!
    * Numeric base: 10
    * @brief Solves equation writen in std:string format
    * @author Andrii Dovbush xdovbu00
    * @param equation equation writen in string format
    * @returns calculated result
    */
    static double solveEquation(std::string equation) {
        return solveEquation(equation, 10);
    }
};


#endif // ! __MATHLIB_H__
