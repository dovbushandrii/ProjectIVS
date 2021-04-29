//============================================================================//
/*
* IVS, Project 2 solution
* Authors: xhavlo01 xdovbu00 xhaltm02 xkolar80
* GNU General Public License v3
*/
//============================================================================//
/**
* @file transtalor.h
* @brief Translator from different numeric systems
* @author Andrii Dovbush, xdovbu00
* @author Anton Havlovskyi, xhavlo01
* @author Ondřej Kolařík, xkolar80
* @author Adam Haltmar, xhaltm02
*/
//============================================================================//

#ifndef __TRANSLATOR_H__

#define __TRANSLATOR_H__

#include <string>

class Translator {
private:
    /*
    * @brief Checks number correctness due to numeric base
    * @author Andrii Dovbush xdovbu00
    * @param numb line with the number
    * @param Base base of numeric system
    * @returns true if number is writen correctly
    */
    static bool checkOnErrors(std::string numb, int base) {
        if (base < 2 || base > 16) {
            throw std::exception("Translator::checksOnErrors: Inappropriate base value");
        }
        else {
            if (base < 11) {
                for (size_t i = 0; i < numb.size(); i++) {
                    bool cond1 = (numb[i] >= '0' && numb[i] < base + '0');
                    bool cond2 = numb[i] == '.' || numb[i] == ',';
                    bool cond3 = numb[i] == '-';
                    if (!(cond1 || cond2 || cond3)) {
                        return false;
                    }
                }
            }
            else {
                for (size_t i = 0; i < numb.size(); i++) {
                    bool cond1 = (numb[i] >= '0' && numb[i] <= '9');
                    cond1 = cond1 || (numb[i] >= 'A' && numb[i] < base - 10 + 'A');
                    cond1 = cond1 || (numb[i] >= 'a' && numb[i] < base - 10 + 'a');
                    bool cond2 = numb[i] == '.' || numb[i] == ',';
                    bool cond3 = numb[i] == '-';
                    if (!(cond1 || cond2 || cond3)) {
                        return false;
                    }
                }
            }
            return true;
        }
    }

public:
    /**
    * @brief Deletes spaces in the line
    * @author Andrii Dovbush xdovbu00
    * @param line line
    * @returns line without spaces
    */
    static std::string deleteSpaces(std::string line) {
        std::string result = "";
        for (size_t i = 0; i < line.size(); i++) {
            if (!isspace(line[i])) {
                result += line[i];
            }
        }
        return result;
    }

    /**
    * @brief Converts number in base 2...16 to decimal number
    * @author Anton Havlovsky xhavlo01
    * @param numb line with the number
    * @param Base base of numeric system
    * @returns decimal equivalent
    */
    static double StrWithBaseToNum(std::string numb, int Base)
    {
        int c = 0;
        int number = 0;
        int numbStart = 0;
        double result = 0;
        double sign = 1;

        numb = deleteSpaces(numb);

        if (checkOnErrors(numb,Base)) {

            while (numb[numbStart] == '-') {
                sign = -sign;
                numbStart++;
            }

            for (size_t i = numbStart; i < numb.length(); i++)
            {
                if (numb[i] == ',' || numb[i] == '.') {
                    break;
                }
                c++;
            }
            for (size_t i = numbStart; i < numb.length(); i++, c--)
            {
                if (numb[i] == ',' || numb[i] == '.') {
                    i++;
                }
                if (numb[i] >= 'a') {
                    number = (numb[i] - 'a') + 10;
                }
                else if (numb[i] >= 'A') {
                    number = (numb[i] - 'A') + 10;
                }
                else {
                    number = numb[i] - '0';
                }
                result += number * pow(Base, (double)(c - 1));
            }
            return result * sign;
        }
        else {
            throw std::exception("Translator::StrWithBaseToNum: Inappropriate number was given due to numeric base");
        }
    }

    /**
    * @brief Converts decimal number to number in base 0...16
    * @author Andrii Dovbush xdovbu00
    * @param numb decimal numb to convert
    * @param Base base of numeric system
    * @returns string with converted number
    */
    static std::string NumToStrWithBase(double numb, int Base) {

        unsigned precision = 8;

        if (Base > 1 && Base < 17) {
            std::string result = "";
            int intPart = (int)floor(abs(numb));
            double fracPart = abs(numb) - intPart;

            //Dealing with integer part
            if (!intPart) {
                result += '0';
            }

            while (intPart) {
                char modulus = intPart % Base;
                if (modulus < 10) {
                    result.insert(0,1,(modulus + '0'));
                }
                else {
                    modulus -= 10;
                    result.insert(0, 1, (modulus + 'A'));
                }
                intPart /= Base;
            }

            //Dealing with fraction part
            if (fracPart > 0) {
                result += '.';
            }
            for (unsigned i = 0; i < precision && fracPart > 0; i++) {
                fracPart *= Base;
                char integ = (char)floor(fracPart);
                fracPart -= (double)integ;
                if (integ < 10) {
                    result += integ + '0';
                }
                else {
                    integ -= 10;
                    result += integ + 'A';
                }
            }

            if (numb < 0) {
                result.insert(0, 1, '-');
            }
            return result;
        }
        else {
            throw std::exception("Translator::NumToStrWithBase: Inappropriate base value");
        }
    }
};

#endif // ! __TRANSLATOR_H__