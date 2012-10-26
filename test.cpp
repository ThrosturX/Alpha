#include <iostream>
#include <string>
#include "parser.cpp"

using namespace std;

int FAILED_TESTS = 0;

void assertEquals(string desc, string test_result, string intended_result);


int main(int argc, char* argv[])
{
	// create object
	Query uri("http://www.ru.is/?course=hugb&exercise=tdd");
	
	// call tests
	assertEquals("Test if exercise is tdd", uri.valueFor("exercise"), "tdd");	
	
	assertEquals("Test if course is hugb", uri.valueFor("course"), "hugb");


	if (FAILED_TESTS)
	{
		cout << "\033[1;31m" ;
		cout << "\aFailed " << FAILED_TESTS << " tests." << endl;
	}
	else
	{
		cout << "\033[1;32m" ;
		cout << "TEST SUCCESS!";
	}

	cout << "\033[0m" << endl;

	return FAILED_TESTS;
}

void assertEquals(string desc, string test_result, string intended_result)
{
	if (test_result.compare(intended_result) != 0)
	{
		FAILED_TESTS++;

		cout << desc << ":" <<
		endl << "returned   [" << test_result << "]" <<
		endl << "instead of [" << intended_result << "]" << endl;
	}
}
