#include <iostream>
#define mod 10007;

using namespace std;
int d[1001][10];


int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 10; i++)
	{
		d[1][i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int x = 0; x < 10; x++)
			{
				if (j + x <= 9)
				{
					d[i + 1][j + x] += d[i][j];
					d[i + 1][j + x] %= mod;
				}
			}
		}
	}
	int total = 0;
	for (int i = 0; i < 10; i++)
	{
		total += d[N][i];
		total %= mod;
	}

	printf("%d\n", total);
	return 0;
}