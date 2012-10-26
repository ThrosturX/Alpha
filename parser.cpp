#include <iostream>
#include <string>

using namespace std;

class Query
{
public:
	Query();
	Query(string input);

	string valueFor(string val);

private:
	string target;
	string delim;
};

Query::Query()
{
	delim = ":/?&=";
}

Query::Query(string input)
{
	delim = ":/?&=";
	target = input;
}

string Query::valueFor(string val)
{
	//val.append(delim);
	size_t found;
	size_t start, end;
	string result;

	found = target.find(val);

	if (found==string::npos)
		return '\0';
	else
	{
		do
		{
			end = target.find_first_of(delim, ++found);
		}
		while(end <= found);		
		
		result = target.substr(found + val.length(), end);

	}

	return result;
}
