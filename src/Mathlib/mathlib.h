#include <math.h>
#include <string>

using namespace std;

class Equation {
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
	//TODO description, function
	/**
	*  a + b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double add(double a, double b);

	//TODO description, function
	/**
	*  a - b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double sub(double a, double b);

	//TODO description, function
	/**
	*  a * b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double mul(double a, double b);

	//TODO description, function
	/**
	*  a / b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double div(double a, double b);

	//TODO description, function
	/**
	*  a^b
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double pow(double a, double b);

	//TODO description, function
	/**
	*  a^(1/b)
	* @brief
	* @author
	* @param a
	* @param b
	* @returns
	*/
	static double root(double a, double b);

	//TODO description, function
	/**
	*  lg(a)
	* @brief
	* @author
	* @param a
	* @returns
	*/
	static double lg(double a);

	//TODO description, function
	/**
	*  ln(a)
	* @brief
	* @author
	* @param a
	* @returns
	*/
	static double ln(double a);
};
