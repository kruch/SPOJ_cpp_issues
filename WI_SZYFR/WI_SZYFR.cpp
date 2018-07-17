#include <string>
#include <iostream>

using namespace std;
string alphabet = "abcdefghijklmnoprstuwxyz";
string str = "bcd";
int Key = 123;
string Cipher(int Key, string str, string alphabet);
int main()
{
	string NewMessage = Cipher(Key, str, alphabet);
	cout << NewMessage << endl;

	cin.get();
	return 0;
}
string Cipher(int Key, string str, string alphabet)
{
	string Msg;
	string NewMsg;
	int LetterPosition = 0;
	int NewLetterMovement = 0;
	int KeyArray[3];
	int iterator = 0;
	int j = 0;
	while (Key>0)
	{
		KeyArray[iterator] = Key % 10;
		Key /= 10;
		
		iterator++;
	}
	for (size_t i = 0; i <= str.length(); i++)
	{
		Msg = str.substr(i, 1);
		
		size_t found = alphabet.find(Msg);
		if (found != std::string::npos)
		{
			LetterPosition = found + j;
			j++;
		}
		if (j > sizeof(KeyArray) || LetterPosition > 26)
		{
			j = 0;
			LetterPosition = 26 - i; // alphabet.begin() + (26 - i)
		}
		NewMsg += alphabet[LetterPosition];
	}
	return NewMsg;
}
