#include <iostream>

using namespace std;

int collatzProblem(int s);

int main()
{
	long int s = 3;
	int t = 0;
	int counter = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		counter = 0;
		cin >> s;
		if (s > 10000 && s < 1) return 0;
		while (s != 1)
		{
			s = collatzProblem(s);
			counter++;
		}
		cout << counter << endl;
	
	}

		cin.get();
		return 0;
}
int collatzProblem(int s)
{
	if (s % 2 == 0) s /= 2;
	else  s = (3 * s) + 1; 
	return s;
}