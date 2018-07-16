#include <iostream>
#include <string>

using namespace std;


string CheckTrigraphLooped(string Example);

void PrintResults(string Result);

int main()
{

	string Example = "??= ??=";

	string TriGraph = CheckTrigraphLooped(Example);

	PrintResults(TriGraph);

	cin.get();
	return 0;
}

string CheckTrigraphLooped(string Example)
{
	string TrigraphArray[9] = { "??=", "??/", "??'", "??(", "??)", "??!", "??<", "??>", "??-" };
	string TrigraphEqArray[9] = { "#", "/", "^", "[", "]", "|", "{", "}", "~" };
	size_t pos;

	int i = 0;

	for (size_t j = 0; j < Example.size(); j++)
	{
		pos = Example.find(TrigraphArray[i]);
		while (pos != string::npos)
		{
			Example.replace(Example.find(TrigraphArray[i]), TrigraphArray[i].length(), TrigraphEqArray[i]);	
			pos = Example.find(TrigraphArray[i+1]);
		}
		
	}

	return Example;
}

void PrintResults(string Result)
{
	cout << Result;
}