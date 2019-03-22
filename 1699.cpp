#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int sq[317];
int d[100001];

int main()
{
	int number;
	scanf("%d", &number);
	for (int i = 1; i <= sqrt(number); i++)
	{
		d[i*i] = 1;
		sq[i] = i * i;
	}
	int sq_n = 0;
	for (int i = 1; i <= number; i++)
	{
		if (d[i] == 1)
			sq_n++;
		else
		{
			for (int x = 1; x <= sq_n; x++)
			{
				if (d[i] != 0)
					d[i] = min(d[i], d[sq[x]] + d[i - sq[x]]);
				else
					d[i] = d[sq[x]] + d[i - sq[x]];
			}
		}
	}
	printf("%d\n", d[number]);

	return 0;
}