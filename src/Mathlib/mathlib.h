#include <math.h>
#include <string>

using namespace std;

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
	static double solveEquation(string equation);
};

class Function {
public:
	//TODO description, function
	/**
	*  a + b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double add(const double a, const double b);

	//TODO description, function
	/**
	*  a - b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double sub(const double a, const double b);

	//TODO description, function
	/**
	*  a * b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double mul(const double a, const double b);

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

	//TODO description, function
	/**
	*  a^b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double pow(const double a, const double b);

	//TODO description, function
	/**
	*  a^(1/b)
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double root(const double a, const double b);

	//TODO description, function
	/**
	*  lg(a)
	* @brief
	* @author
	* @param a
	* @returns
	*/
	static double lg(const double a);

	//TODO description, function
	/**
	*  ln(a)
	* @brief
	* @author
	* @param a
	* @returns
	*/
	static double ln(const double a);
};
