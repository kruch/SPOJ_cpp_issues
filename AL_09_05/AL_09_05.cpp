#include <cstdio>
#include <iostream>

using namespace std;
const int Size = 128;

int n;
int CitiesArray[Size][Size];
int TrainsArray[Size][Size];

int main() {
	int t;
	scanf_s("%d", &t);

	while (t-- > 0) {
		scanf_s("%d", &n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf_s("%d", &CitiesArray[i][j]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf_s("%d", &TrainsArray[i][j]);

		bool Connection = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int ConnectionCount = 0;
				for (int k = 0; k < n; k++) {
					ConnectionCount += CitiesArray[i][k] * CitiesArray[k][j];
				}

				if (ConnectionCount != TrainsArray[i][j]) {
					Connection = false;
					break;
				}
			}

			if (!Connection)
				break;
		}

		printf("%s\n", Connection ? "TAK" : "NIE");
	}

	return 0;
}