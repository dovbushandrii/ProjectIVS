#include <string>

using namespace std;

class Translator {
public:
	//TODO description, function
	/**
	*  Converts number in base 0...16 to decimal number
	* @brief
	* @author
	* @param numb
	* @param Base
	* @returns
	*/
    static double StrWithBaseToNum(string numb, int Base)
    {
        int c = 0;
        int number = 0;
        double result = 0;
        for (int i = 0; i < numb.length(); i++)
        {
            if (numb[i] == ',' || numb[i] == '.')
                break;
            c++;
        }
        for (int i = 0; i < numb.length(); i++, c--)
        {
            if (numb[i] == ',' || numb[i] == '.')
                continue;
            else if (numb[i] > '9')
                number = numb[i] - 55;
            else
                number = numb[i] - '0';
            result += number * pow(Base, c - 1);
        }
        return result;
    }

	//TODO description, function
	/**
	*  Converts decimal number to number in base 0...16
	* @brief
	* @author
	* @param numb
	* @param Base
	* @returns
	*/
	static string NumToStrWithBase(double numb, int Base);
};

class Controller {};
