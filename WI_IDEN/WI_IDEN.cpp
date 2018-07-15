#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;


string ShorteningToUpperOrFirstLowercase(string Variable, size_t MinVariableLenght);

size_t MaxVariableLenght = 7;

int main()
{
	
	string VariableName="ALA_MA_KOTA_I_2_PSY";
	string ChangedName = ShorteningToUpperOrFirstLowercase(VariableName, MaxVariableLenght);
	
	cout << ChangedName;

	cin.get();
}



std::string ShorteningToUpperOrFirstLowercase(string VariableName, size_t MaxVariableLenght)
{
	string NewVarName = "";

	if (VariableName.empty()) return NewVarName;

	if (VariableName.length() <= MaxVariableLenght)
	{
		return VariableName;
	}

	if (VariableName.length() > MaxVariableLenght)
	{
		for (int i = VariableName.length(); i > 0; i--)
		{
			std::size_t found = VariableName.rfind("_");
			if (found!=std::string::npos) // usuwanie od konca znaków specjalnych
			{
				VariableName.erase(found,1);
			}
			else if (VariableName.length() <= MaxVariableLenght)
			{
				return VariableName;
			}
			else if (VariableName.length() > MaxVariableLenght) break;
		}

		for (int i = VariableName.length(); i > 0; i--)
		{
			if (isdigit(VariableName[i]))
			{
				VariableName.erase(VariableName[i],1);
			}
			else if (VariableName.length() <= MaxVariableLenght)
			{
				return VariableName;
			}
			else if (VariableName.length() > MaxVariableLenght) break;
		}

		for (size_t i = 0; i <= VariableName.length(); i++)
		{
			if (VariableName.length() <= MaxVariableLenght)
			{
				return VariableName;
			}
			if (VariableName[i] == 'A' ||
					 VariableName[i] == 'E' ||
					 VariableName[i] == 'I' ||
					 VariableName[i] == 'O' ||
					 VariableName[i] == 'U' ||
					 VariableName[i] == 'Y')
			{
				VariableName.erase(std::remove(VariableName.begin(), VariableName.end(), VariableName[i]), VariableName.end());
				//VariableName.erase(VariableName[i]);
			}
		
		}

		if (VariableName.length() > MaxVariableLenght)
		{
			for (int i = VariableName.length(); i > 0; i--)
			{
				VariableName.erase(VariableName[i],1);

				if (VariableName.length() <= MaxVariableLenght)
				{
					return VariableName;
				}
			}
		}
	}

}


