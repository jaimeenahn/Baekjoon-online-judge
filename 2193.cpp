#include <iostream>

using namespace std;
long long int d[91][2];


int main()
{
	int number;
	scanf("%d", &number);
	d[1][0]= 0;
	d[1][1]= 1;
	for (int i = 1; i <= number; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (j == 1 && k == 1)
					continue;
				else
					d[i + 1][k] += d[i][j];
			}
		}
	}
	long long int total = 0;
	for (int i = 0; i < 2; i++)
	{
		total += d[number][i];
	}
	printf("%lld\n", total);
	return 0;
}