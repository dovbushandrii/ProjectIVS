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
	static double StrWithBaseToNum(string numb, int Base);

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
