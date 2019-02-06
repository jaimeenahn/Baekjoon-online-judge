#include <iostream>
#define mod 1000000000;
using namespace std;

int d[101][10];
int dx[] = { 1, -1 };

int main() {
	int number;
	scanf("%d", &number);
	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}
	d[1][0] = 0;
	for (int i = 1; i < number; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 1 && j == 0)
			{
				continue;
			}
			else
			{
			for (int x = 0; x < 2; x++)
			{
				int xx = j + dx[x];
				if (xx >= 0 && xx <= 9)
				{ 
					if (d[i + 1][xx] == 0)
					{
						d[i + 1][xx] = d[i][j];
					}
					else
					{
						d[i + 1][xx] = d[i + 1][xx] + d[i][j];
						d[i + 1][xx] = d[i + 1][xx] % mod;
					}
				}
			}
			}
		}
	}
	int total = 0;
	for (int i = 0; i <= 9; i++)
	{
		total += d[number][i];
		total %= mod;
	}
	printf("%d\n", total);

	return 0;
}